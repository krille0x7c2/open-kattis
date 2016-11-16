#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct point {
	int x;
	int y;
}point_t;

int main(int argc, char const *argv[])
{
	int hit_x = 0;
	int hit_y = 0;
	int lost_x, lost_y;
	point_t *point;
	point_t *rect[4];
	int i;
	for (i = 0; i < 3; i++){
		point = malloc(sizeof(point_t));
		scanf("%d %d",&point->x, &point->y);
		if (point->x < 1 || point->x > 1000)
			return 1;
		if (point->y < 1 || point->y > 1000)
			return 1;
		
		rect[i] = point;
	}
	
	if (rect[0]->x != rect[1]->x){
		if (rect[1]->x != rect[2]->x)
			hit_x = rect[1]->x;
		else
			hit_x = rect[0]->x;
	}

	if (rect[1]->x != rect[2]->x){
		if (rect[0]->x != rect[2]->x)
			hit_x = rect[2]->x;
		else
			hit_x = rect[1]->x;
	}

	if (rect[0]->y != rect[1]->y){
		if (rect[1]->y != rect[2]->y)
			hit_y = rect[1]->y;
		else
			hit_y = rect[0]->y;
	}

	if (rect[1]->y != rect[2]->y){
		if (rect[0]->y != rect[2]->y)
			hit_y = rect[2]->y;
		else
			hit_y = rect[1]->y;
	}
		

	printf("%d %d\n",hit_x, hit_y);

	for (i = 0; i < 3; i++){
		free(rect[i]);
	}

	return 0;
}