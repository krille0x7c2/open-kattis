/*
 * =====================================================================================
 *
 *       Filename:  alpha-spam.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2016 12:10:11 PM
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
#include	<ctype.h>
#include	<string.h>

int (*scores[4])(char *str);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  count_underscore
 *  Description:  
 * =====================================================================================
 */
	int
count_underscore ( char *str )
{
	int count = 0;
	for (; *str != '\0'; str++)
		if (*str == '_')
			count++;
	return count;
}		/* -----  end of function count_underscore  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  is_upper
 *  Description:  
 * =====================================================================================
 */
	int
is_upper ( char c )
{
	return (c >= 'A' && c <= 'Z' ? 1 : 0);
}		/* -----  end of function is_upper  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  count_lowercase
 *  Description:  
 * =====================================================================================
 */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  is_lower
 *  Description:  
 * =====================================================================================
 */
	int
is_lower ( char c )
{		
	return (c >= 'a' && c <= 'z' ? 1 : 0);
}		/* -----  end of function is_lower  ----- */

	int
count_lowercase ( char *str )
{
	int count = 0;
	for (; *str != '\0'; str++)
		if (is_lower(*str))
			count++;
	return count;
}		/* -----  end of function count_lowercase  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  count_uppercase
 *  Description:  
 * =====================================================================================
 */
	int
count_uppercase ( char *str )
{
	int count = 0;
	for (; *str != '\0'; str++)
		if (is_upper(*str))
			count++;
	return count;
}		/* -----  end of function count_uppercase  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  count_symbols
 *  Description:  
 * =====================================================================================
 */
	int
count_symbols ( char *str )
{
	int count = 0;
	for (; *str != '\0'; str++) {
		if (*str >= '!' && *str <= '@')
			count++;
		else if (*str >= '[' && *str <= '`' && *str != '_')
			count++;
		else if (*str >= '{' && *str <= '~')
			count++;
	}
	return count;
}		/* -----  end of function count_symbols  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	char input[100005];
	int i, len;
	scores[0] = count_underscore;
	scores[1] = count_lowercase;
	scores[2] = count_uppercase;
	scores[3] = count_symbols;

	fgets(input, 100005, stdin);
	input[strcspn(input, "\n")] = '\0';
	len = strlen(input);
	for (i = 0; i < 4; i++){
		printf("%f\n",(double)(*scores[i]) (input) / len);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
