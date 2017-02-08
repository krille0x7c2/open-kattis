#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int base = 0;
static long result = 0;

long str2int(char *str)
{
	char *ptr = str;
	long val = strtol(ptr, &ptr, 10);

	return val;
}

void compute(char *str, int n)
{
	static int lck = 1;
	long val = str2int(str);
	
	if (val > base && lck) {
		result = val;
		lck = 0;
		
	} else if (val < result && val > base) {
		result = val;
	}

}

long fact(int n)
{
	if (n >= 1)
		return n * fact(n - 1);
	else
		return 1;
}

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void permute(char *str, int s, int n)
{
	int i;
	if (s == n) {
		compute(str, n);
	}
		
	for (i = s; i <= n; i++) {
		swap((str + s), (str + i));
		permute(str, s + 1, n);
		swap((str + s), (str + i));
	}
}

int main(int argc, char *argv[])
{
	int len;
	char str[10];
	long val;

	fgets(str, 8, stdin);
	str[strcspn(str, "\n")] = '\0';

	len = strlen(str);

	base = str2int(str);

	permute(str, 0, len - 1);

	printf("%d\n", result);
	
	return 0;
}
