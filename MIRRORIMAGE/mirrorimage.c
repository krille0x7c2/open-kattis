/*
 * =====================================================================================
 *
 *       Filename:  mirrorimage.c
 *
 *    Description:  open-kattis problem
 *
 *        Version:  1.0
 *        Created:  11/18/16 11:53:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christian Bodelsson (cb), krille0x7c2@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include  	<stdio.h>
#include	<string.h>

struct Test {
	char row[25][25];
	int x;
	int y;
};

	void
reverse_str ( char *str )
{
	if (str){
		char *end = str + strlen(str) - 1;
#		define XOR_SWAP(a, b) do\
		{\
			a ^= b;\
			b ^= a;\
			a ^= b;\
		} while (0)

		while (str < end){
			XOR_SWAP(*str, *end);
			str++;
			end--;
		}
#		undef XOR_SWAP
	}
}		/* -----  end of function reverse_str  ----- */

	void
mirror ( struct Test *tc )
{
	int i,  j;
	for (i = 0; i < tc->x; i++ ){
		for (j = 0; j < tc->y; j++){

		}
	}
}		/* -----  end of function mirror  ----- */

	int
main ( int argc, char *argv[] )
{
	int i, j, c, t, r, k;
	struct Test *test, *tests[100];
	char cc, *str;
	scanf("%d", &t);
	while((cc = getchar()) != '\n' && cc != '\0')
		;
	if (t < 1 || t > 100)
		return 1;
	for (i = 0; i < t; i++){
		scanf("%d %d", &r, &c);
		while((cc = getchar()) != '\n' && cc != '\0')
			;
		if (r < 1 || r > 20 || c < 1 || c > 20)
			return 1;
		for (k = 0; k < r; k++ ){
			if(!(str = malloc(sizeof(char*) * 25)))
				return 1;

			if(!(test = malloc(sizeof(struct Test))))
				return 1;

			fgets(str, 20, stdin);
			str[strcspn(str, "\n")] = '\0';
			strncpy(test->row[r], str, 25);
			free(str);
			str = NULL;
		}
			test->x = r;
			test->y = c;
			tests[i] = test;
	}

	for ( i = 0; i < t; i++){
		for ( j = 0; j < tests[i]->x; j++ ) {
			printf("%s\n", tests[i]->row[j]);
		}
	}
	return EXIT_SUCCESS;
}				/* ---------  end of function main  ---------- */
