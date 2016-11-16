#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int get_lower_bound(char *str)
{
	int i, size, buffer[100], tmp, diff, total, next;
	char *ptr;
	ptr = str;
	i = 0;
	size = 0;
	memset(buffer, 0, 100);
	while(*ptr){
		if (isdigit(*ptr) && *ptr != '0'){
			buffer[i] = strtol(ptr, &ptr, 10);
			if(buffer[i] > 1000000)
				return 1;
			i++;
			size++;
		}else{
			ptr++;
		}
	}
	diff = 0;
	for (i = 0; i < size; i++){
		tmp = buffer[i];
		total = tmp * 2;
		next = buffer[i + 1];
		if (next > total){
			diff += next - total;
		}
	}
	printf("%d\n", diff);

	return size;
}

int main(int argc, char const *argv[])
{
	
	int i, t;
	char *str, *strings[13];
	char c;
	scanf("%d", &t);
	if (t < 1 || t > 13)
		return 1;

	while((c = getchar()) != '\n' && c != EOF)
		;
	
	i = 0;
	do {

		str = malloc(101);
		fgets(str, 100, stdin);
		str[strcspn(str, "\n")] = '\0';
		strings[i] = str;
		i++;
	} while (i != t);

	for (i = 0; i < t; i++){
		get_lower_bound(strings[i]);
		free(strings[i]);
	}
	
	return 0;
}