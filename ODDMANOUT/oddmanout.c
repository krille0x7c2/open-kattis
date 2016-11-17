#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>


typedef enum {false, true}bool;

size_t input(long int **buffer)
{
	int i;
	long int val;
	char str[1024];
	char *ptr = NULL;
	long *i_buffer = NULL;

	if (!(fgets(str, 1024, stdin)))
		return -1;

	if (!(i_buffer = calloc(1024, sizeof(*i_buffer))))
		return -1;

	ptr = str;
	i = 0;
	val = 0;
	
	for(; *ptr != '\0'; ptr++){
		if (isdigit(*ptr)) {
			errno = 0;
			val = strtol(ptr, &ptr, 10);
			if ((errno == ERANGE && (val == LONG_MAX ||
			 val == LONG_MIN)) 						|| 
			(errno != 0 && (val == 0))) {
			   free(i_buffer);
               perror("strtol");
               exit(EXIT_FAILURE);
           	}
           i_buffer[i++] = val;
		}
	}

	*buffer = i_buffer;
	return i;
}
int main(int argc, char const *argv[])
{
	long int *i_buff = NULL;
	long int *buff = NULL;
	long int *rows[50] = {NULL};
	int i, n, g, k, size;
	char c;

	scanf("%d", &n);
	if (n < 1 || n > 50)
		return 1;

	while((c = getchar()) != '\n' && c != EOF)
		;

	for (k = 0; k < n; k++){
		
		scanf("%d", &g);
		if (g < 3 || g > 1000)
			return 1;
		while((c = getchar()) != '\n' && c != EOF)
		;

		size = input(&buff);
		if(!(i_buff = malloc(sizeof(int*) * 1024)))
			return 1;

		memcpy(i_buff, buff, 1024);
		free(buff);
		buff = NULL;

		rows[k] = i_buff;


	
	}

	return 0;
}