#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

typedef struct ecoin {
	int tech_val;
	int val;
}ecoin_t;

uint64_t emod(const ecoin_t *coin)
{
	uint64_t sum = coin->val * coin->val + coin->tech_val + coin->tech_val;
	uint64_t root = sqrt(sum);

	if (root % 1 == 0)
		return root;

	return 0;
}

uint64_t find_coins(ecoin_t *coins[],int **reached, int nr_coins, int goal)
{
	int i, j, k;
	for (i = 0; i < nr_coins; i++){
		for (j = coins[i]->val; j <= goal; j++){
			for (k = coins[i]->tech_val; k <= goal; k++){
				reached[j][k] = min(reached[j][k], 
					reached[j - coins[i]->val][k - coins[i]->tech_val] + 1);
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int i;
	int n;
	int m;
	int s;
	ecoin_t *coins[100];
	ecoin_t *coin;
	i = 0;

	scanf("%d", &n);
	if (n < 1 || n > 100)
		return 1;

	scanf("%d %d",&m, &s);
	if (m < 1 || m > 40)
		return 1;
	if (s < 1 || s > 300)
		return 1;

	do {
		coin = malloc(sizeof(ecoin_t));
		scanf("%d %d",&coin->val, &coin->tech_val);
		coins[i] = coin;
	} while (++i != m);

	printf("%d\n", emod(coins[0]));

	for (i = 0; i < 2; i++){
		printf("%d %d\n",coins[i]->val, coins[i]->tech_val );
		free(coins[i]);
	}

	printf("%d\n",emod );


	return 0;
}