#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {down, up}bool;

typedef void (*policies)(char *str);

void seatup(char *str)
{
	bool start;
	int adj_c = 0;
	char *ptr = str;

	start = up ? *ptr == 'U' : down; 
	ptr++;

	for (; *ptr != '\0'; ptr++) {

		if (*ptr == 'D' && start)
			adj_c += 2;
		else if (*ptr == 'U' && !start){
			adj_c++;
			start = up;
		}
		else if (*ptr == 'D' && !start){
			adj_c++;
			start = up;
		}
	}
	printf("%d\n", adj_c);
}

void seatdown(char *str)
{
	bool start;
	int adj_c = 0;
	char *ptr = str;

	start = up ? *ptr == 'U' : down; 

	ptr++;
	for (; *ptr != '\0'; ptr++) {
		
		if (*ptr == 'U' && !start)
			adj_c += 2;
		else if (*ptr == 'U' && start){
			adj_c++;
			start = down;
		}
		else if (*ptr == 'D' && start){
			adj_c++;
			start = down;
		}
	}
	printf("%d\n", adj_c);
}

void seatasyoulike(char *str)
{
	bool start;
	int adj_c = 0;
	char *ptr = str;

	start = up ? *ptr == 'U' : down; 

	ptr++;
	for (; *ptr != '\0'; ptr++) {

		if (*ptr == 'U' && start || *ptr == 'D' && !start)
			continue;
		else if (*ptr == 'U' && !start) {
			adj_c++;
			start = up;
		} else if (*ptr == 'D' && start) {
			adj_c++;
			start = down;
		}
	}
	printf("%d\n", adj_c);
	
}

int main(int argc, char *argv[])
{
	policies pol[3];
	pol[0] = seatup;
	pol[1] = seatdown;
	pol[2] = seatasyoulike;
	int i;
	char str[1010], *ptr;

	fgets(str, 1005, stdin);
	str[strcspn(str, "\n")] = '\0';

	ptr = str;
	for (i = 0; i < 3; i++)
		(*pol[i])(ptr);

	return 0;
}