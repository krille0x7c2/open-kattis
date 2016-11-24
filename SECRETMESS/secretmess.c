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

#define MAX_SIZE 10005

typedef enum {false, true}bool;

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
	static int nr_message;
	printf("Message nr:%d was padded %d times\n",++nr_message ,m - l);
#endif

	return m;
}		/* -----  end of function pad_plain  ----- */

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
	
	if (!(str_new = realloc(str_in, len + 2)))
		return 1;
	
	*str = str_new;
	
	return len;
}		/* -----  end of function get_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rotate_table
 *  Description:  
 * =====================================================================================
 */
	int
rotate_table ( char ***table, int l )
{
	int i, j, x, y, len;
	char **new_table = NULL;
	
	len = sqrt(l);
	/* Allocate */
	if (!(new_table = malloc(l)))
		return 1;

	for (i = 0; i < len; i++){
		if(!(new_table[i] = malloc(len)))
			return 1;
	}
	
	/* Rotate */
	x = len - 1;
	y = 0;
	for (i = 0; i < len; i++){
		for (j = 0; j < len; j++){
			new_table[j][i] = table[0][x][y];
			y++;
		}
		x--;
		y = 0;
	}
	*table = new_table;
	return 0;
}		/* -----  end of function rotate_table  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  build_table
 *  Description:  
 * =====================================================================================
 */
	char **
build_table ( char *plain_txt, int l)
{
	int i, j, k, len;
	char **table = NULL;
	len = sqrt(l);
	
	if (!(table = malloc(l)))
		return NULL;
	
	for (i = 0; i < len; i++){
		if(!(table[i] = malloc(len)))
			return NULL;
	}

	k = 0;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
			table[i][j] = plain_txt[k++];

	return table;
}		/* -----  end of function build_table  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  encrypt
 *  Description:  
 * =====================================================================================
 */
	char *
encrypt ( char *str, int l )
{
	int i, j, m, c, len;
	char *cipher_txt = NULL;
	char **table = NULL;
	
	m = pad_plain(&str, l);
	
	table = build_table(str, m);

	rotate_table(&table, m);
	len = sqrt(m);

	if (!(cipher_txt = malloc(m + 1)))
		return NULL;
	
	c = 0;
	for (i = 0; i < len; i++){
		for (j = 0; j < len; j++){
			if (table[i][j] != '*')
				cipher_txt[c++] = table[i][j];
		}
	}

	for (i = 0; i < len; i++){
		free(table[i]);
		table[i] = NULL;
	}
	cipher_txt[c + 1] = '\0';
	return cipher_txt;
}		/* -----  end of function encrypt  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	char c, *cipher_str = NULL, *row = NULL, *rows[100] = {NULL};
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
	
	for (i = 0; i < n; i++){
		cipher_str = encrypt(rows[i], strlen(rows[i]));
		printf("%s\n", cipher_str);
		cipher_str = NULL;
	}
	
	free(cipher_str);
	cipher_str = NULL;

	for (i = 0; i < n; i++){
		free(rows[i]);
		rows[i] = NULL;
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
