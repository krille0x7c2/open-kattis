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
 *         Name:  get_max
 *  Description:  
 * =====================================================================================
 */
	int
get_max ( char *str, int n )
{
	int i, c, tmp, max;
	char *ptr, *ans;

	if (!(ptr = calloc(33, sizeof(char))))
		return 1;
	max = tmp = 0;
	
	for (i = 0; i < n; i++){
		strncpy(ptr, str, i + 1);
		c = (int) strtol(ptr, NULL, 10);
		ans = int2bin(c);
		tmp = count_ones(ans);
		free(ans);
		ans = NULL;
		if (tmp > max)
			max = tmp;
	}
	free(ptr);
	return max;
}		/* -----  end of function get_max  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, t, max[1000];
	char c, *str;
	memset(max, 0, 1000);
	scanf("%d", &t);
	while((c = getchar()) != '\n' && c != EOF)
		;
	
	i = 0;
	do {
		if (!(str = malloc(33)))
			return 1;
		fgets(str, 31, stdin);
		str[strcspn(str, "\n")] = '\0';
		max[i] = get_max(str, strlen(str));
		free(str);
		str = NULL;
		i++;
	} while (i != t);

	for (i = 0; i < t; i++)
		printf("%d\n", max[i]);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
