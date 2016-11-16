#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {false, true}bool;
enum token{A, B};

struct stats {
	char c[2];
	int freq[2];
	int size;
};

bool occurrence(const char *str, struct stats **stat)
{
	struct stats *_stat = NULL;
	int i, count[26] = {0};

	if(!(_stat = malloc(sizeof(struct stats))))
		return false;

	count[0] = 1;
	for (; *str != '\0'; str++)
		count[*str - 'A']++;
	
	_stat->size = 0;
	
	for (i = 0; i < 26; i++){
		if (count[i] != 0){
			_stat->c[_stat->size] = i + 'A';
			_stat->freq[_stat->size] = count[i];
			_stat->size++;
		}
	}
	*stat = _stat;
	return true;
}

/*LOL HACK*/
char *build_str(int num)
{
	int i, j, len;
	bool check_b;
	check_b = false;
	char *str, *str_cpy;
	if(!(str = calloc(1000, sizeof(*str))))
		return NULL;
	str_cpy = str;

	*str = 'B';
	if (num == 1)
		return str;

	len = 0;
	for (;;){
		
	}

	str_cpy[len] = '\0';
	return str_cpy;
}

int main(int argc, char const *argv[])
{
	struct stats *stat = NULL;
	int k;
	char *str;
	scanf("%d", &k);
	if (k < 1 || k > 45)
		return 1;

	str = build_str(k);

	if (!occurrence(str, &stat))
		return 1;

	printf("%s\n", str);
	//printf("%c %c\n", stat->c[A], stat->c[B] );
	printf("%d %d\n", stat->freq[A] - 1, stat->freq[B]);
	free(str);
	free(stat);
	return 0;
}