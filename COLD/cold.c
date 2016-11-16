#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i, n, tot;
	int *t;
	char x;

	i = tot = 0;

	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;

	t = malloc(sizeof(int));
	do {
		scanf("%d%c",&t[i], &x);
		if (t[i] < -1000000 || t[i] > 1000000){
			free(t);
			return 1;
		}
		i++;
		t = realloc(t,sizeof(int) * (i +1));
		
	} while(x != '\n');

	for (i = 0; i < n; i++){
		if (t[i] < 0)
			tot++;
	}

	printf("%d\n", tot);
	free(t);
	return 0;
}