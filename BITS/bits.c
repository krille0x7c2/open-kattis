#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define BUF_SIZE 33

int 
input_loop(int *ptr_i, const int n_in, const int min, const int max)
{
	int i;
	for (i = 0; i < n_in; i++){
		if (scanf("%d",&ptr_i[i]) != 1)
			return 1;
		if (ptr_i[i] < min || ptr_i[i] > max)
			return 1;
	}
	return 0;
}

int 
allocate_input_space(int **array)
{
	int c, i;
	int *array_t;
	c = 0;
	if(scanf("%d",&c) != 1)
		return -1;

	array_t = malloc(sizeof(int)*c);

	if(array_t == NULL)
		return -1;

	*array = array_t;
	return c;
}

int 
print_i_array(int *array,size_t size)
{
	int i;
	if (array == NULL)
		return -1;

	for (i = 0; i < size; i++)
		printf("%d ",array[i]);
}

int count_zeros(const unsigned char *bin_str, const size_t size)
{
	int i, total;
	total = 0;
	while(*(bin_str++) - '0' != 1)
		total++;
	return total;
}

void int2binstr(int num, unsigned char **buffer, const int size,
	const int strip)
{
	unsigned char *buff_t;
	unsigned char *ref;
	ref = *buffer;
	int count = 0;
	

	*buffer += (size - 1);
	int i;
	for (i = 31; i >= 0; i--){
	 	*(*buffer)-- = (num & 1) + '0';
	 	num >>= 1;
	}
	*buffer = ref;
}

int
count_ones(unsigned char *bin_str)
{
	int total = 0;
	while(*(bin_str) != '\0'){
		if(((*bin_str++) - '0') == 1 )
			total++;
	}
	return total;
}

int 
main(void)
{
	int i;
	unsigned char *buffer = NULL;

	int *number = NULL;

	int count = 0;
	int c = 0;
	c = allocate_input_space(&number);
	unsigned char *collect[c];
	if (c > 1000)
		return 1;

	for (i = 0; i < c; i++){
		if (scanf("%d",&number[i]) != 1)
			return 1;
		if (number[i] < 0 || number[i] > INT_MAX)
			return 1;
		buffer = malloc(sizeof(unsigned char) * BUF_SIZE);
		buffer[BUF_SIZE - 1] = '\0';
		int2binstr(number[i],&buffer, BUF_SIZE - 1,1);
		collect[i] = buffer;
		
	}
	for (i = 0; i < c; i++)
		printf("%d\n", count_ones(collect[i]));


	return 0;
}