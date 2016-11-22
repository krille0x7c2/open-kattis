/*
 * =====================================================================================
 *
 *       Filename:  skop.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/22/2016 11:17:56 AM
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sum_n_pos
 *  Description:  The sum of the first N positive integers
 * =====================================================================================
 */
	int
sum_n_pos ( int number )
{
	return (number * (1 + number) / 2);
}		/* -----  end of function sum_n_pos  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sum_n_odd
 *  Description:  The sum of the first N odd integers 
 * =====================================================================================
 */
	int
sum_n_odd ( int number )
{
	int i, sum, count;
	i = 3;
	count = 1;
	sum = 1;
	for (;;){
		if (count == number)
			return sum;

		if (i % 2 != 0){
			sum += i;
			count++;
		}
		i++;
	}
}		/* -----  end of function sum_n_odd  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sum_n_even
 *  Description:  The sum of the first N even integers
 * =====================================================================================
 */
	int
sum_n_even ( int number )
{
	int i, sum, count;
	i = 4;
	count = 1;
	sum = 2;
	for (;;){
		if (count == number)
			return sum;

		if (i % 2 == 0){
			sum += i;
			count++;
		}
		i++;
	}
}		/* -----  end of function sum_n_even  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int set[10000];
	int i, p, n, k, s1, s2, s3;
	memset(set, 0, 10000);
	scanf("%d", &p);
	if (p < 1 || p > 10000)
		return 1;
	i = 0;
	do{
		scanf("%d %d",&k, &n);
		if (n < 1 || n > 10000)
			return 1;
		set[i] = n;
		i++;
	} while (i != p);

	for(i = 0; i < p; i++){
		s1 = sum_n_pos(set[i]);
		s2 = sum_n_odd(set[i]);
		s3 = sum_n_even(set[i]);
		printf("%d %d %d %d\n",i + 1 ,s1, s2, s3);
	}
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
