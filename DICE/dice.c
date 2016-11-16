#include <stdlib.h>
#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int c, i, j, k, m, n, sum, count, tmp, end, max;
	c = m = n = count = max = 0;
	int arr[20*20];

	scanf("%d %d", &n, &m);
	if (n < 4 || n > 20 || m < 4 || m > 20)
		return 1;

	sum = n + m;

	for (k = 2; k <= sum; k++){
		for (i = 1; i <= n; i++){
			for (j = 1; j <= m; j++){
				if (i + j == k)
					count++;
			}
			
		}
		arr[c++] = count;
		count = 0;
	}
	end = c;
	for (i = 0; i < end; i++){
		tmp = arr[i];
		if (tmp > max)
			max = tmp;
	}

	for (i = 0; i < end; i++){
		if(arr[i] == max)
			printf("%d\n", i + 2);
	}
	
		
	return 0;
}