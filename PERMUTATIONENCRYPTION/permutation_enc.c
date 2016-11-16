#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void swapn(char *a, int i, int j)
{
	if (i != j){
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
	}
}

void print_enc_msg(char *string, size_t len)
{
	int i;
	printf("%c",'\'' );
	for (i = 0; i < len; i++)
		printf("%c", string[i]);
	printf("%c\n",'\'' );
}

void encrypt(char *dest, char *ptr, int *key, int msg_len, int key_len)
{
	int i, j ,c;
	i = j = c = 0;

	while (j != (msg_len / key_len)){
		for (i = 1; i < key_len + 1; i++){
			swapn(ptr, i, key[i] - 1);
			dest[c] = ptr[i];
			swapn(ptr, i, key[i] - 1);
			c++;
		}
		ptr += key_len;
		j++;
	}
}

int *get_key(void)
{
	char x;
	int *payload;
	int i, c, key_len, msg_len;
	i = c = key_len = msg_len = 0;

	payload = malloc(sizeof(int));
	if (payload == NULL) 
		return NULL;

	do {
		scanf("%d%c", &payload[i], &x);
		if (payload[0] == 0)	  		
			return payload;

		i++;

		payload = realloc(payload,sizeof(int) * (i + 1));
		if (payload == NULL) 
			return NULL;

		c++;

	} while (x != '\n');
	return payload;
}

void *get_message(int key_len)
{
	int msg_len;
	char *str;
	str = malloc(sizeof(char) * 1024);
	(void)fgets(str, 1024,stdin);
	str[strcspn(str, "\n")] = '\0';

	msg_len = strlen(str);
	//Whitespace padding
	while (msg_len % key_len != 0){
 		strcat(str," ");
 		msg_len = strlen(str);
 	}
	return str;
}


int main(int argc, char const *argv[])
{
	int i, j, c;
	int *key_collection[150];
	char *str_collection[150];
	int key_len;
	int msg_len;

	for (i = 0;; i++) {
	
		key_collection[i] = get_key();
		key_len = key_collection[i][0];
		if (key_len == 0 || key_len > 20){
			free(key_collection[i]);
			break;
		}
		str_collection[i] = get_message(key_len);
	}

	c = i;
	
	for (i = 0; i < c; i++){
		
		msg_len = strlen(str_collection[i]);
		key_len = key_collection[i][0];
		char *new_str = malloc(sizeof(int) * msg_len + 1);
		encrypt(new_str, str_collection[i], key_collection[i], msg_len, key_len);
		print_enc_msg(new_str,msg_len);

		free(str_collection[i]);
		free(key_collection[i]);
		free(new_str);
	}

	return 0;
}