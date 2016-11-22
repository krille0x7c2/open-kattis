/*
 * =====================================================================================
 *
 *       Filename:  oddmanout.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/22/2016 03:55:47 PM
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
#include	<ctype.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ext_int
 *  Description:  
 * =====================================================================================
 */
	void
ext_int ( char *str, long int *buff )
{
	int i;
	long int val;
	char *p;
	p = str;
	i = 0;
	while(*p){
		if (isdigit(*p)){
			val = strtol(p, &p, 10);
			buff[i++] = val;
		} else {
			p++;
		}
	}
}		/* -----  end of function ext_int  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bubble_sort
 *  Description:  
 * =====================================================================================
 */
	void
bubble_sort ( long int **a, int n )
{

}		/* -----  end of function bubble_sort  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  who_came_alone
 *  Description:  
 * =====================================================================================
 */
	long int
who_came_alone ( long int *lst, int n )
{
	int i;
	for (i = 0; i < n - 1; i += 2) {
		if (lst[i] != lst[i + 1])
			return lst[i];
	}
	return lst[n -1];
}		/* -----  end of function who_came_alone  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int i, j, t, s, n, g, gs[50];
	long int *cs, *css[50];
	char c, *str_in;
	scanf("%d", &n);
	if (n < 1 || n > 50)
		return 1;


	i = 0;
	do{
		scanf("%d", &g);
		if (g < 3 || g > 1000)
			return 1;
		if (!(cs = malloc(sizeof(long) * g)))
			return 1;
		if (!(str_in = malloc(10000)))
			return 1;
		while((c = getchar()) != '\n' && c != EOF)
			;

		fgets(str_in, 10000, stdin);
		ext_int(str_in, cs);
		css[i] = cs;
		gs[i] = g;
		free(str_in);
		str_in = NULL;
		i++;
	} while (i != n);
	
	for (i = 0; i < n; i++) {
		s = 1;
		while(s){
			s = 0;
			for (j = 1; j < gs[i]; j++) {
				if (css[i][j] < css[i][j - 1]) {
					t = css[i][j];
					css[i][j] = css[i][j - 1];
					css[i][j - 1] = t;
					s = 1;
				}
			}
	 	}
	}
	
	for (i = 0; i < n; i++){
		printf("Case #%d: %ld\n", i + 1,  who_came_alone(css[i], gs[i]));
		free(css[i]);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
