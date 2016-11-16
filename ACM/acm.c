#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum boolean {false, true};

struct Entry {
	int m;
	char c;
	enum boolean check;
};

int extract_number(char *token)
{
	return strtol(token, NULL, 10);
}

char extract_alpha(char *token)
{
	char *ptr;
	(void)strtol(token, &ptr, 10);
	if (*ptr == ' ')
		ptr++;
	return *ptr;
}

char extract_str(char *token)
{
	char *ptr;
	(void)strtol(token, &ptr, 10);
	ptr += 3;
	return *ptr;
}

int main(int argc, char const *argv[])
{
	int i, j, n, total, points;
	char str[15];
	char tmp_c;
	struct Entry *entry;
	entry = malloc(sizeof(struct Entry) * 100);
	n = 0;
	do{
		fgets(str, 13, stdin);
		str[strcspn(str, "\n")] = '\0';

		(entry + n)->m = extract_number(str);
		if ((entry + n)->m < 1)
			break;
		if ((entry + n)->m > 300)
			return 1;

		(entry + n)->c = extract_alpha(str);
		if (!isalpha((entry + n)->c))
			return 1;

		(entry + n)->check = extract_str(str) == 'r' ? true : false;

		n++;
	} while (n != 99);

	points = 0;
	total = 0;


	for(i = 0; i < n; i++){
		if ((entry + i)->check)
			total++;
	}

	for(i = 0; i < n; i++){
		if ((entry + i)->check){
			tmp_c = (entry + i)->c;
			points += (entry + i)->m;
			for(j = i; j >= 0; j--){
				if (!(entry + j)->check && (entry + j)->c == tmp_c)
					points += 20;
			}
		}
	}

	printf("%d %d\n", total, points);

	return 0;
}