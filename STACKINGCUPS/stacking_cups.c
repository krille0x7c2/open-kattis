#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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


int bubble_sort (struct Cup *cup, int n) {
    int i, t, s = 1;
    char *str_tmp = NULL;
    str_tmp = malloc(sizeof(char) * 30);
    if (str_tmp == NULL)
    	return 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if ((cup + i)->radius < (cup + i - 1)->radius) {
            	/*Integer*/
                t = (cup + i)->radius;
                (cup + i)->radius = (cup + i - 1)->radius;
                (cup + i - 1)->radius = t;
                s = 1;
                /*Char*/
                strcpy(str_tmp, (cup + i)->color);
                strcpy((cup + i)->color, (cup + i - 1)->color);
                strcpy((cup + i - 1)->color, str_tmp);
            }
        }
    }
   // free(str_tmp);
    return 0;
}

int main(int argc, char const *argv[])
{
	struct Cup *cup;
	int n, c, i, j;
	char *ptr;
	char *str_token = NULL;

	scanf("%d", &n);
	if (n < 1 || n > 20)
		return 1;
	while ((c = getchar()) != '\n' && c != EOF)
		;/*empty*/

	cup = malloc(sizeof(struct Cup) * n);
	if (cup == NULL)
		return 1;

	i = 0;
	do{
		ptr = NULL;
		str_token = malloc(sizeof(char) * 30);
		if (str_token == NULL)
			return 1;

		fgets(str_token, 30, stdin);
		str_token[strcspn(str_token, "\n")] = '\0';

		if (strlen(str_token) > 24)
			return 1;

		if (!isdigit(str_token[0])){

			str_token = twist_str(str_token);
			if (str_token == NULL)
				return 1;

			(cup + i)->radius = (int)strtol(str_token, &ptr, 10);
			if ((cup + i)->radius < 1 || (cup + i)->radius > 999)
				return 1;
			if (*ptr == ' ')
				ptr++;
			for (j = 0; j < strlen(ptr); j++){
				if(!(ptr[j]>='a' && ptr[j]<='z'))
					return 1;
			}
			if (strlen(ptr) > 20)
				return 1;

			(cup + i)->radius *= 2;
			strcpy((cup + i)->color, ptr);
			i++;
			//free(new_token);
			free(str_token);
			str_token = NULL;

		}else{

		(cup + i)->radius = (int)strtol(str_token, &ptr, 10);
		if ((cup + i)->radius < 1 || (cup + i)->radius > 999)
			return 1;
		if (*ptr == '\0')
			return 1;
		if (*ptr == ' ')
			ptr++;
		for (j = 0; j < strlen(ptr); j++){
			if(!(ptr[j]>='a' && ptr[j]<='z'))
				return 1;
		}
		if (strlen(ptr) > 20)
			return 1;

		strcpy((cup + i)->color, ptr);
		i++;
		//free(str_token);
		}
	} while (i != n);

	if (bubble_sort(cup, n))
		return 1;

	for (i = 0; i < n; i++)
		printf("%s\n", (cup + i)->color);

	//free(cup);
	return 0;
}