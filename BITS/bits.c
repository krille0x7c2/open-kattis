/*
 * =====================================================================================
 *
 *       Filename:  bits.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2016 09:27:56 AM
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
 *         Name:  count_ones
 *  Description:  
 * =====================================================================================
 */
	int
count_ones ( char *str )
{
	int count = 0;
	for (; *str != '\0'; str++){
		if (*str == '1')
			count++;
	}
	return count;
}		/* -----  end of function count_ones  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  int2bin
 *  Description:  
 * =====================================================================================
 */
	char *
int2bin ( int n )
{
	int i;
	char *buffer = NULL, *buffer_cpy = NULL;
	if (!(buffer = calloc(33, sizeof(char))))
		return NULL;
	buffer_cpy = buffer;
	/* move to last position - null character*/
	buffer += 31;
	/* move backwards */
	for (i = 31; i >= 0; i--){
		*buffer-- = (n & 1) + '0';
		n >>= 1;
	}
	return buffer_cpy;
}		/* -----  end of function int2bin  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
#define MAX_SIZE 33
	int
main ( int argc, char *argv[] )
{
	int i, t, x, mem;
	char *strs[1000];
	scanf("%d", &t);
	i = 0;
	do {
		scanf("%d", &x);
		strs[i] = int2bin(x);
		i++;
	} while (i != t);

	mem = 0;
	for (i = 0; i < t; i++){
		mem = count_ones(strs[i]);
		printf("%d\n", mem);
		free(strs[i]);
		strs[i] = NULL;
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
