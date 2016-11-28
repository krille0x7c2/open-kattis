/*
 * =====================================================================================
 *
 *       Filename:  humancannonball.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2016 09:48:21 AM
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

struct Line {
	float velocity;
	float angle;
	float distance;
	float h1;
	float h2;
	float max;
};

typedef struct Point {
	float x, y;
}point;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_trajectory
 *  Description:  
 * =====================================================================================
 */
	point *
get_trajectory ( float v, float t, float a )
{
	point *p;
	float x, y, ar;
	ar = (a * M_PI) / 180;
	x = v * t * cos(ar);
	y = (v * sin(ar) * t) - (9.81 * pow(t, 2)) / 2;
	if (!(p = malloc(sizeof(struct Point))))
		return NULL;
	p->x = x;
	p->y = y;
	return p;
}		/* -----  end of function get_trajectory  ----- */

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
	point *p = NULL;
	int i, n;
	float fi, max, tmp, d1, d2;
	scanf("%d", &n);
	if ( n < 1 || n > 100)
		return 1;
	
	i = 0;
	do {
		if (!(line = malloc(sizeof(struct Line))))
			return 1;
		scanf("%f %f %f %f %f", &line->velocity, 
				&line->angle, &line->distance,
				&line->h1, &line->h2);
		lines[i] = line;
		i++;
	} while (i != n);
	
	for (i = 0; i < n; i++){
		tmp = max = d1 = d2 = 0.0;
		for (fi = 0.1; fi < 20.0; fi += 0.1){
			p = get_trajectory(lines[i]->velocity, fi, lines[i]->angle);
			tmp = p->y;
			if (tmp > max){
				max = tmp;
				d1 = p->x;
				free(p);
			}else{
				d2 = p->x;
				free(p);
				break;
			}
		}

		if (d1 > lines[i]->distance || d2 < lines[i]->distance ){
			if ((max - 1) > lines[i]->h1 && (max + 1) < lines[i]->h2){
			printf("Safe\n");
			}else{
				printf("Not Safe\n");
			}
		}else{
			printf("Not Safe\n");
		}
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
