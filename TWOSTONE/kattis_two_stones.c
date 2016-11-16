#include <stdlib.h>
#include <stdio.h>

struct Player
{
	int turn;
	int num;
};

int main(void)
{
	int n,i,j;
	j = 1;
	struct Player Bob, Alice;
	Alice.turn = 1;
	Bob.turn = 0;
	scanf("%d",&n);
	if (n < 1 || n > 10000000)
		return 1;
	
	int *ground;
	ground = malloc(sizeof(int)*n);

	if (ground == NULL)
		return 1;

	for (i = 0; i < n; i++)
		ground[i] = j++;

	for (i = 0; i < n; i++){
		if (Alice.turn && i != n -1){
			ground[i] = 0;
			ground[i + 1] = 0;

			Alice.turn = 0;
			Bob.turn = 1;
		}else if(Bob.turn && i != n -1){
			ground[i] = 0;
			ground[i + 1] = 0;

			Bob.turn = 0;
			Alice.turn = 1;
		}

		if (i == n -1){
			printf("%s\n", Alice.turn ? "Alice" : "Bob");
		}
	}
	free(ground);
	return 0;
}
