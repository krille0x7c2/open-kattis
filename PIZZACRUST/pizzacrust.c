#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int r, c;
	double area;
	double crust_area, diff;
	diff = crust_area = 0.0;

	scanf("%d %d", &r, &c);
	if (c < 1 || c > r || r < c || r > 100)
		return 1;


	area = (M_PI * pow(r, 2));
	crust_area = (M_PI * pow(r - c, 2));
	crust_area /= area;

	printf("%f\n", crust_area * 100);

	return 0;
}