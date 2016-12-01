/*
 * =====================================================================================
 *
 *       Filename:  falsesec.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2016 12:16:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christian Bodelsson (cb), krille0x7c2@gmail.com
 *   	  License:  GNU General Public License
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>


static const char *morse[] = {
	".-", "-...", "-.-.", "-..", ".", 
	"..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---", ".--.", 
	"--.-", ".-.", "...", "-", "..-", "...-", 
	".--", "-..-", "-.--", "--.."
};

static const char *extra[] = {
	".-.-", "---.", "----", "..--"
};

static const char *sign[] = {
	",", ".", "?", "_"	
};

static const char *alpha[] = {
	"A", "B", "C", "D", "E", "F", 
	"G", "H", "I", "J", "K", "L", 
	"M", "N", "O", "P", "Q", "R", 
	"S", "T", "U", "V", "W", "X",
	"Y", "Z"
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  crypt
 *  Description:  
 * =====================================================================================
 */
	char *
crypt ( char *cipher_txt )
{
	int k, a, aa, c, i, j, n, len, pauses[1000] = {0};
	char *ptr, tmp[5], mess[8000], str[8000], *ret_ptr;
	memset(tmp, 0, 5);
	memset(mess, 0, 8000);
	memset(str, 0, 8000);
	ptr = cipher_txt;
	n = 0;
	for (; *ptr != '\0'; ptr++){
		if (*ptr >= 'A' && *ptr <= 'Z'){
			strcat(mess, morse[*ptr - 'A']);
			pauses[n] = strlen(morse[*ptr - 'A']);	
		}else if (*ptr == ','){
			strcat(mess, extra[0]);	
			pauses[n] = strlen(extra[0]);	
		}else if (*ptr == '.'){
			pauses[n] = strlen(extra[1]);	
			strcat(mess, extra[1]);
		}else if (*ptr == '?'){
			pauses[n] = strlen(extra[2]);	
			strcat(mess, extra[2]);
		}else if (*ptr == '_'){
			pauses[n] = strlen(extra[3]);	
			strcat(mess, extra[3]);
		}else
			printf("ERROR\n");
		n++;
	}
	c = 0;
	aa = 0;
	for (i = n - 1; i >= 0; i--){
		k = pauses[i];
	    for (j = 0; j < k; j++){
			tmp[j] = mess[c++];
		}
		tmp[j] = '\0';
		for (a = 0; a < 26; a++){
			if (!strcmp(morse[a], tmp)){
				strcat(str, alpha[a]);
				break;
			}else if(!strcmp(extra[a % 4], tmp)){
				strcat(str, sign[a % 4]);
				break;
			}
		}
	}
	
	if (!(ret_ptr = malloc(sizeof(char) * 1005)))
		return NULL;

	strcpy(ret_ptr, str);
	return ret_ptr;
}		/* -----  end of function crypt  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, n;
	char c, cipher[1005], *plain[3000];
	n = 0;

	while(fgets(cipher, 1005, stdin) != NULL){
		cipher[strcspn(cipher, "\n")] = '\0';
		plain[n] = crypt(cipher);
		memset(cipher, 0, 1005);
		n++;
	}
	for ( i = 0; i < n; i++ )
		printf("%s\n", plain[i]);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
