#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int num;
	char *ptr;
	char str[] = "20";
	num = (int)strtol(str, &ptr, 10);

	if(*ptr == '\0')
		printf("%d %c\n", num, *ptr);
	return 0;
}