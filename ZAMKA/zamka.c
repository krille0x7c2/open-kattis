#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int sum_int_str(char *str_int)
{
	int i;
	int sum = 0;
	for (i = 0; i < strlen(str_int); i++)
		sum += str_int[i] - '0';
	return sum;
}

int str_to_int(char *str)
{
	return (int)strtol(str, NULL, 10);
}
char *int_to_str(int n)
{
	char *str;
	str = calloc(7,sizeof(char));
	sprintf(str, "%d", n);
	return str;
}
int main(int argc, char const *argv[])
{
	int i, j, l, d, x;
	char *str_int[3];
	char *tmp_ptr;
	int tmp;
	int n, m;
	int num;
	i = j = l = d = x = 0;
	for (i = 0; i < 3; i++){
		str_int[i] = calloc(7,sizeof(char));
		if (str_int[i] == NULL)
			return 1;
	}
	
	for (i = 0; i < 3; i++){
		fgets(str_int[i],7,stdin);
		str_int[i][strcspn(str_int[i],"\n")] = '\0';
		num = str_to_int(str_int[i]);
		if (i != 2){
			if (num < 1 || num > 10000)
	    		return 1;
		}else{
		    if (num < 1 || num > 36)
				return 1;
		}
	}

	l = str_to_int(str_int[0]);
	d = str_to_int(str_int[1]);
	x = str_to_int(str_int[2]);
	n = d;
	tmp = 0;
	tmp_ptr = calloc(7,sizeof(char));
	for (i = l; i < d; i++){
		tmp_ptr = int_to_str(i);
		if (sum_int_str(tmp_ptr) == x){
			tmp = str_to_int(tmp_ptr);
			if (tmp < n){
				n = tmp;
			}
		}
	}

	l = str_to_int(str_int[0]);
	d = str_to_int(str_int[1]);
	x = str_to_int(str_int[2]);

	m = l;
	tmp = 0;
	for (i = l; i <= d; i++){
		tmp_ptr = int_to_str(i);
		if (sum_int_str(tmp_ptr) == x){
			tmp = str_to_int(tmp_ptr);
			if (tmp > m){
				m = tmp;
			}
		}
	}
		
	printf("%d\n",n);
	printf("%d\n",m);
	return 0;
}