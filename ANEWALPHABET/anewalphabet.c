/*
 * =====================================================================================
 *
 *       Filename:  anewalphabet.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2016 11:22:11 AM
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
#include	<ctype.h>

char *lookup[] = {
	"@", "8", "(", "|)", "3", "#", "6", "[-]", 
	"|", "_|", "|<", "1", "[]\\/[]", "[]\\[]",
	"0", "|D", "(,)", "|Z", "$", "']['", "|_|", 
	"\\/", "\\/\\/", "}{", "`/", "2"
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i;
	char *tmp, *ptr, str[10005];
	memset(str, 0, 10005);
	fgets(str, 10005, stdin);
	str[strcspn(str, "\n")] = '\0';
	ptr = str;

	for (; *ptr != '\0'; ptr++){
		if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')){
			i = tolower(*ptr) - 'a';
			tmp = lookup[i];
			for (; *tmp != '\0'; tmp++)
				printf("%c", *tmp);
		} else {
			printf("%c", *ptr);
		}
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
