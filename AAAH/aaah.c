/*
 * =====================================================================================
 *
 *       Filename:  aaah.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2016 11:04:23 AM
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
typedef enum {false, true}bool;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go_to_doc
 *  Description:  
 * =====================================================================================
 */
	bool
go_to_doc ( char *str_j, char *str_d )
{
	if (strlen(str_d) <= strlen(str_j))
		return true;
	else
		return false;
}		/* -----  end of function go_to_doc  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	const char *out[] = {"go", "no"};
	char jon[1003], doc[1003];
	fgets(jon, 1001, stdin);
	fgets(doc, 1001, stdin);
	
	if (go_to_doc(jon, doc))
		printf("%s\n", out[0]);
	else
		printf("%s\n", out[1]);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
