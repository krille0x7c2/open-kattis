#include <stdlib.h>
#include <stdio.h>

#define TIMESTAMP 45
int main(int argc, char **argv)
{
	int h,m;
	h = 0;
	m = 0;
	scanf("%d %d",&h,&m);
		;
	if (h < 0 || h > 23 || m < 0 || m > 59)
		return 1;

	if (m < TIMESTAMP){
		m = (60 - TIMESTAMP + m) % 60;
		if (h == 0)
			h = 23;
		else
			h--;
	}else if (m > TIMESTAMP){
		m = m - TIMESTAMP;
	}

	printf("%d %d\n",h,m);

	return 0;
}