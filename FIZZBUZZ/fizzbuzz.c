#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	if (x < 1 || x > 100)
		return 1;
	if (y <= x || y > n)
		return 1;
	if (n < 1 || n > 100)
		return 1;

	for (i = 1; i <= n; i++){
		if (i % x == 0 && i % y == 0)
			printf("%s\n", "FizzBuzz");
		else if (i % x == 0)
			printf("%s\n", "Fizz");
		else if (i % y == 0)
			printf("%s\n", "Buzz");
		else
			printf("%d\n", i);
	}
	return 0;
}