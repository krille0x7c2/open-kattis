/*
 * =====================================================================================
 *
 *       Filename:  grass.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2016 09:19:25 AM
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

struct Line {
	float w;
	float l;
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  calculate_cost
 *  Description:  
 * =====================================================================================
 */
	float
calculate_cost ( float w, float l )
{	
	return (w * l);
}		/* -----  end of function calculate_cost  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	struct Line *line, *lines[100];
	int i, l;
	float c, result;
	scanf("%f", &c);
	if (c < 0 || c > 100)
		return 1;

	scanf("%d", &l);
	if (l < 0 || l > 100)
		return 1;

	i = 0;
	do {
		if (!(line = malloc(sizeof(struct Line))))
			return 1;

		scanf("%f %f", &line->w, &line->l);
		lines[i] = line;
		i++;
	} while (i != l);
	
	result = 0;
	for (i = 0; i < l; i++){
		result += calculate_cost(lines[i]->w, lines[i]->l);
		free(lines[i]);
	}
	printf("%f\n", result * c);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
