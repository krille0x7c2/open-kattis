/*
 * =====================================================================================
 *
 *       Filename:  message.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2016 12:11:07 PM
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
#include	<math.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  build_block
 *  Description:  
 * =====================================================================================
 */
	char **
build_block ( char *str, int n )
{
	int i, j, k, row;
	row = sqrt(n);
	char **block = NULL;
	
	if (!(block = malloc(n)))
		return NULL;

	for (i = 0; i < row; i++){
		if (!(block[i] = malloc(row)))
			return NULL;
	}

	k = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < row; j++)
			block[i][j] = str[k++];

	return block;
}		/* -----  end of function build_block  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  decrypt
 *  Description:  
 * =====================================================================================
 */
	char *
decrypt ( char *str, int n )
{
	int c, i, j, k, end;
	int row = sqrt(n);
	char *plain_txt = NULL;
	char **block = NULL;

	if (!(plain_txt = calloc(10005, sizeof(char))))
		return NULL;
		
	block = build_block(str, n);

	k = 0;
	end = row - 1;
	for (i = end; i >= 0; i--)
		for (j = i; j < (i + row); j += row)
			for (c = 0; c < row; c++)
				plain_txt[k++] = block[c][j];

	plain_txt[k] = '\0';
	
	return plain_txt;
}		/* -----  end of function decrypt  ----- */

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
	char c, *plain = NULL, *str = NULL, *strs[100] = {NULL};
	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;
	while((c = getchar()) != '\n' && c != EOF)
		;

	i = 0;
	do {

		if (!(str = malloc(sizeof(char) * 10005)))
			return 1;
		(void)fgets(str, 10005, stdin);
		str[strcspn(str, "\n")] = '\0';
		strs[i] = str;
		i++;

	} while (i != n);

	for (i = 0; i < n; i++){

		plain = decrypt(strs[i], strlen(strs[i]));
		printf("%s\n", plain);
		free(strs[i]);
		free(plain);
		plain = NULL;
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
