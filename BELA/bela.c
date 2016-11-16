#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum boolean {false, true};
enum Number {seven, eight, nine, T, J, Q, K, A};
enum Suit {S, H, D, C};
int dom[8] = {0, 0, 14, 10, 20, 3, 4, 11};
int n_dom[8] = {0, 0, 0, 10, 2, 3, 4, 11};

struct Card {
	enum Suit suit;
	enum Number num;
	enum boolean isdominant;
};

int main(int argc, char const *argv[])
{
	struct Card *card = NULL;
	int i, n, total;
	char b, c;
	char in[4];
	scanf("%d %c", &n, &b);
	if (n < 1 || n > 100)
		return 1;
	while ((c = getchar()) != '\n' && c != EOF)
		;/*Empty*/
	card = malloc(sizeof(struct Card) * (n * 4));
	i = 0;
	n *= 4;
	do{
		fgets(in, 4, stdin);
		in[strcspn(in, "\n")] = '\0';
		switch(in[0]){
			case '7': (card + i)->num = seven; 	break;
			case '8': (card + i)->num = eight; 	break;
			case '9': (card + i)->num = nine; 	break;
			case 'T': (card + i)->num = T; 		break;
			case 'J': (card + i)->num = J; 		break;
			case 'Q': (card + i)->num = Q; 		break;
			case 'K': (card + i)->num = K; 		break;
			case 'A': (card + i)->num = A; 		break;
			default:							break;
		}
		switch(in[1]){
			case 'S':
			(card + i)->isdominant = in[1] == b ? true : false;
			break;
			case 'H':
			(card + i)->isdominant = in[1] == b ? true : false;
			break;
			case 'D':
			(card + i)->isdominant = in[1] == b ? true : false;
			break;
			case 'C':
			(card + i)->isdominant = in[1] == b ? true : false;
			break;
			default:
			break;
		}
		i++;
	} while(i != n);

	total = 0;
	for(i = 0; i < n; i++){
		if((card + i)->isdominant)
			total += dom[(card + i)->num];
		else
			total += n_dom[(card + i)->num];
	}

	printf("%d\n", total);

	free(card);


	return 0;
}