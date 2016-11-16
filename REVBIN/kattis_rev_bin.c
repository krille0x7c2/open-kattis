#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 33

char *int_to_bin_str(int num,char *string,int buf_size)
{
	string += (buf_size - 1);
	int i;

	for (i = 31; i >= 0; i--){
		*string-- = (num & 1) + '0';
		num >>= 1;
	}
	return string;
}

void reverse_string(char *str)
{
	if (str)
  	{
    	char * end = str + strlen(str) - 1;

    // swap the values in the two given variables
    // XXX: fails when a and b refer to same memory location
#	define XOR_SWAP(a,b) do\
	    {\
	      a ^= b;\
	      b ^= a;\
	      a ^= b;\
	    } while (0)

	    // walk inwards from both ends of the string, 
	    // swapping until we get to the middle
	    while (str < end)
	    {
	      XOR_SWAP(*str, *end);
	      str++;
	      end--;
	    }
#   undef XOR_SWAP
  }
}



int bin_str_to_int(char *bin_string)
{
	return (int) strtol(bin_string,NULL, 2);
}

int main(void)
{
	int x;
	char *ptr;
	char bin_string[BUF_SIZE];
	

	bin_string[BUF_SIZE - 1] = '\0';

	scanf("%d", &x);
	if ( x < 1 || x > 1000000000)
		return 1;

	int_to_bin_str(x,bin_string,BUF_SIZE - 1);
	ptr = &bin_string[strcspn(bin_string, "1")];
	reverse_string(ptr);
	printf("%d\n", bin_str_to_int(ptr));
	return 0;
}