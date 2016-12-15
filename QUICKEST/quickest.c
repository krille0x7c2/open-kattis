/*
 * =====================================================================================
 *
 *       Filename:  quickest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2016 10:07:15 AM
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
#include	<limits.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, n, totals[100] = {0};
	char c, *str = NULL;

	scanf("%d", &n);
	while((c = getchar()) != '\n' && c != EOF);
	
	i = 0;
	do{
		if (!(str = malloc(1028)))
			return 1;
		fgets(str, 1024, stdin);
		str[strcspn(str, "\n")] = '\0';
		totals[i] = strlen(str);
		free(str);
		str = NULL;
		i++;
	}while(i != n);

	for (i = 0; i < n; i++)
		printf("%d\n", totals[i]);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
