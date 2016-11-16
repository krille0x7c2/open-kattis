#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
int main(int argc, char const *argv[])
{
	int *val;
	int *ptr;
	const int bottle = 400;
	int i, t, n, count;
	scanf("%d",&t);
	if (t < 1 || t > 1000)
		return 1;

	val = calloc(t,sizeof(int));
	if (val == NULL)
			return 1;
	ptr = val;
	i = 0;
	do{
		scanf("%d", &n);
		if (n < 0 || n > 10000)
			return 1;
		if (n >= 1 && n < 400)
			*val = 1;
		else
			*val = (int)ceil((float)n/bottle);
		val++;
		i++;

	}while(i != t);

	for (i = 0; i < t; i++)
		printf("%d\n", ptr[i]);
	
	return 0;
}