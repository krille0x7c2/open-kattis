/*
 * =====================================================================================
 *
 *       Filename:  erase.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2016 02:06:01 PM
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
 *         Name:  cmp_bin_str
 *  Description:  
 * =====================================================================================
 */
	bool
cmp_bin_str ( char *a, char *b, int n )
{
	int i;
	for (i = 0; i < n; i++){
		if (a[i] == b[i])
			continue;
		else
			return false;
	}
	return true;
}		/* -----  end of function cmp_bin_str  ----- */

/* ===  FUNCTION  ======================================================================
 *         Name:  flip_bin_str
 *  Description:  
 * =====================================================================================
 */
	char *
flip_bin_str ( char *str, int n, int l )
{
	int i;
	char *ret_str, *ptr;

	if (!(ret_str = malloc(n + 1)))
		return NULL;

	ptr = str;
	
	i = 0;
	for (; l > 0; l-- ){
		for (; *ptr != '\0'; ptr++){
			if (*ptr == '0')
				ret_str[i] = '1';
			else
				ret_str[i] = '0';
			i++;
		}
		i = 0;
		ptr = ret_str;
	}
	return ret_str;
}		/* -----  end of function flip_bin_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int n, l;
	char str[1005], hdd[1005], *del_str;
	scanf("%d %s %s", &n, str, hdd);
	
	l = strlen(str);
	del_str = flip_bin_str(str, l, n);
	
	if (cmp_bin_str(del_str, hdd, l))
		printf("Deletion succeeded\n");
	else
		printf("Deletion failed\n");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
