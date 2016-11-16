#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int get_input(char **in, const int size)
{
	int n = 0;
	/*Allcoate max-space*/
	char *ptr = calloc(size,sizeof(char));
	if (ptr == NULL) 
		return -1;
	/*Get input from stdin*/
	if (fgets(ptr, size, stdin) == NULL)
		return -1;
	/*Remove and replace newline from fgets with nul*/
	ptr[strcspn(ptr, "\n")] = '\0';
	/*Get character count*/
	n = strlen(ptr);
	/*Update pointer*/
	*in = ptr;
	/*Lenght should be n > 0*/
	if (n == 0)
		return -1;
	return n;
}
#define MAX 1024

int main(int argc, char const *argv[])
{
	int i, j;
	int len = 0;
	char *string = NULL;
	char *new_string = NULL;
	char *ptr;

	len = get_input(&string, MAX);
	new_string = calloc(len + 1, sizeof(char));

	if (new_string == NULL)
		return 1;
	if (len < 1 || len > 250)
		return 1;

	ptr = new_string;
	for (i = 0; string[i] != '\0'; i++){
		if (string[i] != string[i+1]){
			*new_string = string[i];
			*(new_string + 1) = '\0';
			new_string++;
		}else{
			while(string[i] != string[i + 1])
				i++;
		}
	
	}

	printf("%s\n",ptr);

	return 0;
}