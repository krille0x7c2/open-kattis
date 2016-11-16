#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {false, true}bool;

struct input {
	int rotations;
	char str[41];
};


const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
						 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
						 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
						 'Y', 'Z', '_', '.'};

void reverse_str(char * str)
{
  if (str)
  {
    char * end = str + strlen(str) - 1;

    // swap the values in the two given variables
    // XXX: fails when a and b refer to same memory location
#   define XOR_SWAP(a,b) do\
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

bool encrypt(char *str, int rot)
{
	int i = 0;
	reverse_str(str);
	for (; *str != '\0'; str++){
		while(*str != alphabet[i])
			i++;
		*str = alphabet[(i + rot) % 28];
		i = 0;
	}
}

int main(int argc, char const *argv[])
{
	struct input *in, *lst[30];
	char c;
	int i, n;
	n = 0;

	for (;;){
		if (!(in = malloc(sizeof(struct input))))
			return 1;
		scanf("%d", &in->rotations);
		if (in->rotations == 0)
			break;
		if (in->rotations < 1 || in->rotations > 27)
			return 1;
		scanf("%s", in->str);
		/*Clean the stream*/
		while((c = getchar()) != '\n' && c != EOF)
			;
		lst[n] = in;
		n++;
	} 
	for (i = 0; i < n; i++)
		encrypt(lst[i]->str, lst[i]->rotations);

	for (i = 0; i < n; i++){
		printf("%s\n", lst[i]->str);
		free(lst[i]);
	}
	free(in);
	
	return 0;
}