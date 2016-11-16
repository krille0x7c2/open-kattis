#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double sin_degrees(double degrees) {
    return sin(degrees * (M_PI/180.0));
}

int main(int argc, char const *argv[])
{
	int h, v;
	int res_i;
	double res_d;
	scanf("%d %d", &h, &v);

	if (h < 1 || h > 10000)
		return 1;
	if (v < 1 || v > 89)
		return 1;

	res_i = ceil(h/sin_degrees(v));

	printf("%d\n",res_i);
	return 0;
}