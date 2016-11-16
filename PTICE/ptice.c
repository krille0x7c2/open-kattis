#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Player {
	int score;
	int winner;
	char *str;
	char *name;
}player_t, *player_ptr;

/*Worst crap i've ever written!!!*/

int count_hits(const char *str, const char *str1)
{
	int i, tot;
	tot = 0;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == str1[i])
			tot++;
	}
	return tot;
}

int main(int argc, char const *argv[])
{

	player_ptr adrian, goran, bruno;
	player_t *players[3];

	adrian = malloc(sizeof(player_ptr*));
	goran = malloc(sizeof(player_ptr*));
	bruno = malloc(sizeof(player_ptr*));

	players[0] = adrian;
	players[1] = bruno;
	players[2] = goran;

	adrian->name = "adrian";
	bruno->name = "bruno";
	goran->name = "goran";

	adrian->str = malloc(sizeof(char)*100+2);
	goran->str = malloc(sizeof(char)*100+2);
	bruno->str = malloc(sizeof(char)*100+2);

	adrian->str = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCA";

	bruno->str = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";

	goran->str = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAA";
	
	int res_bruno, res_adrian, res_goran;
	int i, j, n;
	int tmp = 0;
	int winner = 0;
	int point = 1;
	int check = 0;
	char str[105];
	memset(str, 0, sizeof(char)*105);
	(void)scanf("%d",&n);
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	if (n < 1 || n > 100)
		return 1;

	(void)fgets(str, 101, stdin);
	str[strcspn(str, "\n")] = '\0';

	adrian->score = count_hits(str, adrian->str);
	bruno->score = count_hits(str, bruno->str);
	goran->score = count_hits(str, goran->str);

	if (adrian->score >= bruno->score && adrian->score >= goran->score)
		adrian->winner = 1;
	if (bruno->score >= adrian->score && bruno->score >= goran->score)
		bruno->winner = 1;
	if (goran->score >= adrian->score && goran->score >= bruno->score)
		goran->winner = 1;

	j = 0;
	while(j != 3){
		if(players[j]->winner){
			if(!check){
				printf("%d\n", players[j]->score);
				check = 1;
			}
			printf("%s\n", players[j]->name);
		}
		j++;
	}

	return 0;
}