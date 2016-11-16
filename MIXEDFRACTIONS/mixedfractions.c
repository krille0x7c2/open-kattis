#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

struct stats {
	int a;
	int b;
	int whole;
};

int main(int argc, char const *argv[])
{
	struct stats *stat = NULL, *lst[2000] = {NULL};



	int i, a, b, n, whole;
	char c;
	n = 0;
	for (;;){
		if (!(stat = malloc(sizeof(struct stats))))
			return 1;

		scanf("%d %d", &a, &b);
		if ( a == 0 && b == 0)
			break;
		if (a < 1 || a > INT_MAX || b < 1 || b > INT_MAX){
			for (i = 0; lst[i] != NULL; i++){
					free(lst[i]);
					lst[i] = NULL;
			}
			free(stat);
			stat = NULL;
			return 1;
		}
		while((c = getchar()) != '\n' && c != EOF)
			;

		whole = a / b;

		stat->a = a;
		stat->b = b;
		stat->whole = whole;

		lst[n] = stat;
		n++;
	}

	for (i = 0; i < n; i++){
		if(lst[i] != NULL){
		printf("%d %d %c %d\n", 
			lst[i]->whole, lst[i]->a % lst[i]->b,'/',lst[i]->b);
		free(lst[i]);
		lst[i] = NULL;
		}
	}
	if (stat != NULL)
		free(stat);
	stat = NULL;

	return 0;
}