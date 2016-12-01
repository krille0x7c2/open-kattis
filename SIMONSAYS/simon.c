/*
 * =====================================================================================
 *
 *       Filename:  simon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2016 02:59:14 PM
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

typedef enum {false, true}bool;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_simon
 *  Description:  
 * =====================================================================================
 */
	bool
find_simon ( char *str )
{
	if (strstr(str, "simon says") != NULL)
		return true;
	return false;
}		/* -----  end of function find_simon  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, t;
	char c, *str, *strs[20];
	scanf("%d", &t);
	while((c = getchar()) != '\n' && c != EOF)
		;
	i = 0;
	do {
		if (!(str = malloc(1005)))
			return 1;
		fgets(str, 1005, stdin);
		strs[i++] = str;
	} while (i != t);

	for (i = 0; i < t; i++){
		if (find_simon(strs[i])){
			strs[i] += 11;
			printf("%s\n", strs[i]);
		} else {
			printf("\n");
		}
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
