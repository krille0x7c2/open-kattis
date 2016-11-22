/*
 * =====================================================================================
 *
 *       Filename:  volim.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/2016 01:00:37 PM
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


static int time_left = 210;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, j, k, n, t, ts[100];
	char z, cs[100];
	memset(ts, 0, 100);
	memset(cs, 0, 100);
	scanf("%d", &k);
	if (k < 1 || k > 8)
		return 1;
	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;

	i = 0;
	do{
		scanf("%d %c", &t, &z);
		if (t < 1 || t > 100)
			return 1;
		ts[i] = t;
		cs[i] = z;
		i++;
	} while (i != n);

	i = k - 1;
	j = 0;
	for (;;){
		if (time_left < 0)
			break;
		if (cs[j] == 'P' || cs[j] == 'N'){
			time_left -= ts[j];
			j++;
		}else if (cs[j] == 'T'){
			time_left -= ts[j];
			if (time_left < 0)
				break;
			i++;
			j++;
		}
	}
	printf("%d\n", (i % 8) + 1);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
