/*
 * =====================================================================================
 *
 *       Filename:  areal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2016 01:55:25 PM
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
#include	<math.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	const int mul = 4;
	double len = 0.0;
	long long a;
	scanf("%lld", &a);
	len = sqrt(a) * mul;
	printf("%f\n", len);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
