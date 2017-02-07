#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct In {
	int n;
	long input[30];
};

long range(long max, long min) { return max - min; }


long max(long *x, int n)
{
	long tmp = -1000000;
	long *ptr = x;
	ptr++;

	int i;
	for (i = 0; i < n; i++) {
		if (*ptr > tmp)
			tmp = *ptr;
		ptr++;
	}
	return tmp;
}

long min(long *x, int n)
{
	long tmp = 1000000;
	long *ptr = x;
	ptr++;
	
	int i;
	for (i = 0; i < n; i++) {
		if (*ptr < tmp)
			tmp = *ptr;
		ptr++;
	}
	return tmp;
}

struct In *str2int(char *str)
{
	int i;
	char *ptr;
	ptr = str;
	struct In *in = malloc(sizeof(struct In));

	i = 0;
	while(*ptr) {
		if (isdigit(*ptr) || *ptr == '-') {
			long val = strtol(ptr, &ptr, 10);
			in->input[i++] = val;
		} else {
			ptr++;
		}
	}
	in->n = in->input[0];
	return in;
} 

void compute(struct In *in)
{
	static int counter = 1;
	long mx, mn, rg;
	mx = max(in->input, in->n);
	mn = min(in->input, in->n);
	rg = range(mx, mn);

	printf("%s %d: %d %d %d\n", "Case", counter, mn, mx, rg);
	counter++;
}

int main(int argc, char *argv[])
{
	int i, c;
	struct In *in = NULL;
	struct In *ins[100];
	char str[10005];

	c = 0;
	while(fgets(str, 10000, stdin)) {
		str[strcspn(str,"\n")] = '\0';
		in = str2int(str);
		ins[c++] = in;
	}
	
	i = 0;
	for (i = 0; i < c; i++) {
		compute(ins[i]);
		free(ins[i]);
	}

	return 0;
}