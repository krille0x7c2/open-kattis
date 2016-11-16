#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

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
	char vowel[] = {'a','e','i','o','u'};
	char *str, *new_str;
	char *ptr;
	str = new_str = ptr = NULL;
	int i, j, len;
	len = get_input(&str,MAX);
	new_str = calloc(len + 1,sizeof(char));

	ptr = new_str;
	for (i = 0; str[i] != '\0'; i++){
		for (j = 0; j < 5; j++){
			if (str[i] == vowel[j]){
				i += 2;
				break;
			}
		}
		*new_str = str[i];
		*(new_str + 1) = '\0'; 
		new_str++; 
	}
	printf("%s\n",ptr);
	
	free(str);
	return 0;
}