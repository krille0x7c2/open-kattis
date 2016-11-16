#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct answer {
	int time;
	char type;
}answer_t;

int main(int argc, char const *argv[])
{

	int i, k, n, t;
	char z;
	int timeout = 210;
	scanf("%d", &k);
	if (k < 1 || k > 8)
		return 1;
	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;
	
	i = n;
	answer_t *answers[i];
	do {
	scanf("%d %c",&t,&z);
	if (t < 1 || t > 100)
		return 1;
	answers[i] = calloc(n,sizeof(char));
	if (answers[i] == NULL)
		return 1;
	answers[i]->time = t;
	answers[i]->type = z;
	i--;
	}while (i != 0);

	int tmp = 0;
	char d;
	for (i = 0; i < n; i++){
		tmp = answers[i]->time;
		d = answers[i]->type;
		switch(d){
			case 'T':
			break;
			case 'N':
			break;
			case 'p':
			break;
			default:
			break;
		}
	}


	return 0;
}