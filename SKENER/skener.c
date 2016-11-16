#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum bool {false, true}bool;

bool validate(char *str)
{
	for ( ; *str != '\0'; str++){
		if (isalpha(*str) || isdigit(*str) || *str == '.')
			continue;
		else
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int i, j, r, c, k, u, zr, zc;
	char cc, **input, *str, *new_row, *ptr, **res, **new_res;

	scanf("%d %d %d %d", &r, &c, &zr, &zc);
	if (r < 1 || r > 50 || c < 1 || c > 50)
		return 1;
	if (zc < 1 || zc > 5 || zr < 1 || zr > 5)
		return 1;
	while((cc = getchar()) != '\n' && cc != EOF)
		;

	input = calloc(r, sizeof(char*));
	res = calloc(r*zr,sizeof(char*));
	new_res = calloc(r*zr,sizeof(char*));
	

	i = 0;
	do{
		str = malloc(c + 2);
		if (str == NULL) 
			return 1;
		fgets(str, c + 2, stdin);
		str[strcspn(str, "\n")] = '\0';
		if(!validate(str))
			return 1;
		input[i] = str;
		i++;
	}while(i != r);
	
	
	for (i = 0; i < r; i++){
		u = 0;
		ptr = input[i];
		new_row = malloc(sizeof(strlen(str)) * zc + 1);
		for (j = 0; j < strlen(str); j++){
			for (k = 0; k < zc; k++){
				new_row[u++] = *ptr;
			}
			ptr++;
		}
		res[i] = new_row;
	}

	u = 0;
	k = 0;
	for (i = 0; i < r; i++){
		for (j = 0; j < zr; j++){
			new_res[u++] = res[k];
		}
		k++;
	}

	for (i = 0; i <  (r * zr); i++)
		printf("%s\n", new_res[i]);
	
	return 0;
}