#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 50
typedef enum {false, true}bool;
typedef enum {Tablet = 1, Compass = 2, Gear = 4}card;
static const int bonuspoint = 7;

struct stats {
	char c[4];
	int freq[4];
	int size;
};

char *get_string(void)
{
	char *str;
	if (!(str = malloc(MAX_SIZE + 2)))
		return NULL;
	fgets(str, MAX_SIZE + 2, stdin);
	str[strcspn(str, "\n")] = '\0';
	return str;
}

bool valid(char *str)
{
	for (; *str != '\0'; str++){
		if (*str == 'C' || *str == 'G' || *str == 'T')
			continue;
		else
			return false;
	}
	return true;
}

bool char_occurrence(char *str, struct stats **stat)
{
	struct stats *_stat = NULL;
	int i, count[26] = {0};

	if(!(_stat = malloc(sizeof(struct stats))))
		return false;

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


int bonus(const struct stats *stat)
{
	int i, flag = 0;
	for (i = 0; i < stat->size; i++){
		switch(stat->c[i]){
			case 'C': flag |= Compass; break;
			case 'G': flag |= Gear; break;
			case 'T': flag |= Tablet; break;
			default: break;
		}
	}
	return flag == 0x07 ? true : false ;
}

int count_bouns(struct stats *stat)
{
	int i, *ptr, total, tmp;

	ptr = stat->freq;
	total = 0;
	tmp = 0;
	for(;;){
		for(i = 0; i < stat->size; i++){
			if(!ptr[i])
				return total;
			else
				tmp++;
			ptr[i] -= 1;
		}
		if (tmp % stat->size == 0)
			total++;
	}
	return total;
}

int main(int argc, char const *argv[])
{
	char *str;
	int i, score, b;
	struct stats *stat = NULL;
	str = get_string();
	if (!valid(str))
		return 1;

	char_occurrence(str, &stat);

	score = 0;
	for (i = 0; i < stat->size; i++)
		score += pow(stat->freq[i],2);

	if (bonus(stat)){
		b = count_bouns(stat);
		for (i = 0; i < b; i++)
			score += bonuspoint;
	}
	printf("%d\n", score);
	free(str);
	free(stat);
	return 0;
}