#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	uint64_t x;
	uint64_t y;
	// if(scanf("%lld",&x) != 1)
	// 	return 1;
	while(scanf("%lld %lld", &x, &y) != EOF){
		if (x < 0 || x > 1000000000000000)
			return 1;
		if (y < 0 || y > 1000000000000000)
			return 1;
		if ( x > y)
			printf("%lld\n", x - y);
		else
			printf("%lld\n", y - x);
	}
	return 0;
}