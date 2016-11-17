#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

struct Cup {
	int radius;
	char color[21];
};

char *twist_str(char *str)
{
	int i, len;
	char *ptr;
	char *new_str;
	ptr = str;
	len = strlen(str);

	new_str = malloc(sizeof(char) * 30);
	if (new_str == NULL)
		return NULL;

	for (i = 0; i < len; i++){
		if (!isdigit(*ptr))
			ptr++;
		else
			break;
	}
	strcpy(new_str, ptr);
	strcat(new_str, " ");
	ptr -= i;
	strncat(new_str, ptr, i - 1);

	return new_str;
}


int bubble_sort (struct Cup **cup, int n) {
    int i, t, s = 1;
    char *str_tmp = NULL;
    str_tmp = malloc(sizeof(char) * 30);
    if (str_tmp == NULL)
    	return 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (cup[i]->radius < cup[i - 1]->radius) {
            	/*Integer*/
                t = cup[i]->radius;
                cup[i]->radius = cup[i - 1]->radius;
                cup[i - 1]->radius = t;
                s = 1;
                /*Char*/
                strcpy(str_tmp, cup[i]->color);
                strcpy(cup[i]->color, cup[i - 1]->color);
                strcpy(cup[i - 1]->color, str_tmp);
            }
        }
    }

    return 0;
}


int main(int argc, char const *argv[])
{
	struct Cup *cup, *cups[20];
	int n, c, i, j, tmp;
	char *ptr = NULL;
	char *str_token = NULL;
	cup = NULL;

	scanf("%d", &n);
	if (n < 1 || n > 20)
		return 2;
	while ((c = getchar()) != '\n' && c != EOF)
		;/*empty*/

	for (i = 0; i < n; i++){
		tmp = 0;
		ptr = NULL;
		if(!(str_token = malloc(sizeof(char) * 25)))
			return 4;

		if(!(cup = malloc(sizeof(struct Cup))))
				return 1;

		fgets(str_token, 25, stdin);
		str_token[strcspn(str_token, "\n")] = '\0';


		if (!isdigit(*str_token)){

			if(!(str_token = twist_str(str_token)))
				return 6;

			errno = 0;
			tmp = (int)strtol(str_token, &ptr, 10);
			
			// if (tmp < 1 || tmp > 999){
			// 	return 7;
			// }

			if (*ptr == ' ')
				ptr++;


			tmp *= 2;
			cup->radius = tmp;
			strcpy(cup->color, ptr);
			cups[i] = cup;
			free(str_token);
			str_token = NULL;

		}else{

			tmp = (int)strtol(str_token, &ptr, 10);
			// if (tmp < 1 || tmp > 999)
			// 	return 10;

			if (*ptr == ' ')
				ptr++;

			cup->radius = tmp;
			strcpy(cup->color, ptr);
			cups[i] = cup;
			free(str_token);
			str_token = NULL;
		}
	}

	if (bubble_sort(cups, n))
		return 14;

	for (i = 0; i < n; i++){
		if (cups[i]->radius != 0){
			printf("%s\n", cups[i]->color);
		}
		
	}
	return 0;
}