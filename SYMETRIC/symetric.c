#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Set {
	int num;
	char *names[15];
};


int main(int argc, char const *argv[])
{
	struct Set *set, *sets[20], *sym_set, *sym_sets[20];
 	int c, i, j, k, r, n;
 	char *str;

 	c = 0;
 	for(;;){
 		
 	    scanf("%d", &n);
 		if (n < 1) 
 			break;
 		if (n > 15)
 			return 1;

 		set = malloc(sizeof(struct Set));

 		set->num = n;

 		i = 0;
 		do{
 			str = malloc(26);
 			if(str == NULL)
 				return 1;
 			scanf("%s", str);
 			set->names[i] = str;
 			i++;
 		} while(i != n);

 		sets[c] = set;
 		c++;
 	}
 	k = 0;
 	r = 1;
 	for (i = 0; i < c; i++){
 		sym_set = malloc(sizeof(struct Set));	
 		for (j = 0; j < sets[i]->num; j++){
 			if (j % 2 == 0){
 				sym_set->names[k++] = sets[i]->names[j];
 			}else{
 				sym_set->names[sets[i]->num - r++] = sets[i]->names[j];
 			}
 		}
 		k = 0;
 		r = 1;
 		sym_set->num = sets[i]->num;
 		free(sets[i]);
 		sym_sets[i] = sym_set;
 	}

 	for (i = 0; i < c; i++){
 		printf("SET %d\n", i + 1);
 		for(j = 0; j < sym_sets[i]->num; j++){
 			printf("%s\n", sym_sets[i]->names[j]);
 			free(sym_sets[i]->names[j]);
 		}
 		free(sym_sets[i]);
 	}		
 		
    return 0;
}
