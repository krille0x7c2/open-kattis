#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *board[7];
	char *str;
	int i, j, k, valid;

	/*Yes i know, possible memoryleak..*/
	for (i = 0; i < 7; i++){
		if (!(str = malloc(sizeof(*str) * 10)))
			return 1;
		fgets(str, 10, stdin);
		str[strcspn(str, "\n")] = '\0';
		board[i] = str;
	}


	valid = 0;
	/*Horizontal*/
	for (i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			if (board[i][j] == '.'){
				if (j > 1){
					if (board[i][j - 2] == 'o' && board[i][j - 1] == 'o')
						valid++;
				}
				if (j < 5){
					if (board[i][j + 1] == 'o' && board[i][j + 2] == 'o')
						valid++;
				}
			}
		}
	}

	/*Vertical*/
	for (j = 0; j < 7; j++){
		for(i = 0; i < 7; i++){
			if (board[i][j] == '.'){
				if (i > 1){
					if (board[i - 2][j] == 'o' && board[i - 1][j] == 'o')
						valid++;
				}
				if (i < 5){
					if (board[i + 1][j] == 'o' && board[i + 2][j] == 'o')
						valid++;
				}
			}
		}
	}
	printf("%d\n", valid);
	for (i = 0; i < 7; i++)
		free(board[i]);

	return 0;
}