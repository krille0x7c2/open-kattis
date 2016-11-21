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


struct box {
	int time_left;
	int label;
};

static const int TIME_TO_EXPLODE = 210;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	struct box box;
	int k, n, t;
	char z;
	scanf("%d", &k);
	if (k < 1 || k > 8)
		return 1;
	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;
	scanf("%d %c", &t, &z);
	if (t < 1 || t > 100)
		return 1;


	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
