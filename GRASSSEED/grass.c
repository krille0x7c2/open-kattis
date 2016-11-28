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
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	struct Line *line, *lines[100];
	int i, l;
	float c;
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
	
	for (i = 0; i < l; i++)
		printf("%f %f\n", lines[i]->w, lines[i]->l);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
