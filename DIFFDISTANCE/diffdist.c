/*
 * =====================================================================================
 *
 *       Filename:  diffdist.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2016 12:14:14 PM
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
#include	<string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  p_norm
 *  Description:  
 * =====================================================================================
 */
	float
p_norm ( float x1, float x2, float y1, float y2, float p )
{
	float norm;
	norm = pow(pow(fabs(x1 - x2), p) + pow(fabs(y1 - y2), p), 1/p);
	return norm;
}		/* -----  end of function p_norm  ----- */

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
	float x1, x2, y1, y2, p, res[1000];
	memset(res, 0.0, 1000);
	n = 0;
	for (;;){
		scanf("%f", &x1);
		if (x1 == 0)
			break;
		scanf("%f %f %f %f", &y1, &x2, &y2, &p);
		res[n++] = p_norm(x1, x2, y1, y2, p); 
	}
	for (i = 0; i < n; i++ )
		printf("%f\n", res[i]);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
