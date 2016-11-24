/*
 * =====================================================================================
 *
 *       Filename:  secretmess.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2016 02:26:43 PM
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
#include	<math.h>

#define DEBUG
#define MAX_SIZE 10005

typedef enum {false, true}bool;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rotate_table
 *  Description:  
 * =====================================================================================
 */
	void
rotate_table ( void )
{
	/* TODO */
}		/* -----  end of function rotate_table  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_square
 *  Description:  
 * =====================================================================================
 */
	int
find_square ( int n )
{
	int tmp;
	tmp = sqrt(n);
	while (tmp * tmp != n)
		tmp = sqrt(++n);
	return n;
}		/* -----  end of function find_square  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pad_plain
 *  Description:  
 * =====================================================================================
 */
	int
pad_plain ( char **plain_txt, int l )
{
	static int nr_message;
	int i, m;
	char *padded_txt = NULL;
	
	if((m = find_square(l)) == l)
		return l;
	
	if (!(padded_txt = realloc(*plain_txt, m + 1)))
		return 1;

	for (i = l; i < m; i++)
		padded_txt[i] = '*';
	
	*plain_txt = padded_txt;

#ifdef DEBUG
	printf("Message nr:%d was padded %d times\n",++nr_message ,m - l);
#endif
	
	return m;
}		/* -----  end of function pad_plain  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  encrypt
 *  Description:  
 * =====================================================================================
 */
	void
encrypt ( char *str )
{
	/* TODO */
}		/* -----  end of function encrypt  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_str
 *  Description:  MAX_SIZE lenght string from stdin
 * =====================================================================================
 */
	int
get_str ( char **str )
{
	int len;
	char *str_in, *str_new;
	str_in = str_new = NULL;
	
	if (!(str_in = malloc(MAX_SIZE)))
		return 1;
	
	fgets(str_in, MAX_SIZE, stdin);
	str_in[strcspn(str_in, "\n")] = '\0';
	
	len = strlen(str_in);

	if (len < 1 || len > 10000)
		return 1;
	
	if (!(str_new = realloc(str_in, len + 1)))
		return 1;
	
	*str = str_new;
	
	return len;
}		/* -----  end of function get_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	char c, *row = NULL, *rows[100] = {NULL};
	int i, n;

	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;
	/*Clear stdin of trailing newline*/
	while((c = getchar()) != '\n' && c != EOF)
		;/*EMPTY */
	
	i = 0;
	do {
		get_str(&row);
		rows[i] = row;
		row = NULL;
		i++;
	} while (i != n);
	
	/* TODO */
	
	for (i = 0; i < n; i++){
		free(rows[i]);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
