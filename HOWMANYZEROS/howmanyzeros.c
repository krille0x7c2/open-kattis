#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int str_to_int(char *str)
{
	return (int)strtol(str, NULL, 10);
}

int count_zeros(char *str)
{
	int i;
	int tot = 0;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] - '0' == 0)
			tot++;
	}
	return tot;
}

char *int_to_str(int n)
{
	char *str;
	str = calloc(12,sizeof(char));
	sprintf(str, "%d", n);
	return str;
}

int main(int argc, char const *argv[])
{
	unsigned int i, m, n;
	unsigned int tot = 0;
	char *m_ptr, *n_ptr;
	char *str_pair[2];
	
	do{
		scanf("%u %u", &m, &n);
		if (m < 0 || m > UINT_MAX)
			return 1;

		for (i = m; i <= n; i++){
			tot += count_zeros(int_to_str(i));
		}
		printf("%u\n", tot);

	}while(1);


	
	return 0;
}