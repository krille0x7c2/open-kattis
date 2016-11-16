#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int i, j, tmp, max, current;
	char *player; 
	char *players[5];

	tmp = max = current = 0;
	for (i = 0; i < 5; i++){
		player = malloc(sizeof(char)*10);
		fgets(player,10,stdin);
		player[strcspn(player, "\n")] = '\0';
		players[i] = player;
		
	}

	for (i = 0; i < 5; i++){
		for (j = 0; j < 7; j++){
			if (players[i][j] != ' ')
				tmp += (players[i][j] - '0');
		}
		
		
		if (tmp > max){
			max = tmp;
			current = i;
			current++;
		}
		tmp = 0;
		
	}

	printf("%d %d\n", current, max);

	

	return 0;
}