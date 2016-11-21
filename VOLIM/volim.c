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
	char answer;
};

struct player {
	struct box b;
	int time;
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
	struct player *p;
	
	int i, k, n, t, ts[100];
	char z, cs[100];
	memset(ts, 0, 100);
	memset(cs, 0, 100);
	scanf("%d", &k);
	if (k < 1 || k > 8)
		return 1;
	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;
	if (!(p = malloc(sizeof(struct player)* 8)))
		return 1;
	for ( i = 0; i < 8; i++){
		(p + i)->label = i;
		(p + i)->time = 0;
	}

	i = 0;
	do{
		scanf("%d %c", &t, &z);
		if (t < 1 || t > 100)
			return 1;
		ts[i] = t;
		cs[i] = z;
		i++;
	} while (i != n);
	
	i = k - 1;
	
	(p + i)->b.time_left = TIME_TO_EXPLODE;
	for (;;){
		switch(cs[i]){
			case 'T':
				(p + i)->b.time_left -= ts[i];
				i++;
				break;
			case 'N':
			case 'P':
				while(cs[i] != 'T'){
					(p + i)->b.time_left -= ts[i];
					if ((p + i)->b.time_left == 0)
						goto done;
					i++;
				}
				break;
		}
	
		if ((p + i)->b.time_left == 0)
			break;
		if ( i == n)
			i = 0;
	}

done:
	printf("%d", (p + i)->label);	

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
