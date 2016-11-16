#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <time.h>


struct input {
	int n;
	int q;
};

int isPrime(int number){

    if(number < 2) return 0;
    if(number == 2) return 1;
    if(number % 2 == 0) return 0;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return 0;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
	struct input input;
	int x[20000];
	int i, j, tot_prime;
	i = tot_prime = j = 0;

	int n = 100000000;
   	int *prime;
	prime = malloc(200000000 * sizeof(int));

   for(i=0;i<n;i++) // initializes the prime number array
   {
      prime[i]=i;
   }
   for(i=2;i<n;i++) // Implementation of the Sieve
   {
      if(prime[i]!=0)
      { 
         for(j=2;j<n;j++)
         {
            {
               prime[j*prime[i]]=0;
               if(prime[i]*j>n)
                  break;    
            }
         }
      }
   }

   for(i=0;i<n;i++) // Prints the prime numbers
      if(prime[i]!=0)
      {
         printf("%d ",prime[i]);
      }

    free(prime);


	// if (scanf("%d %d", &input.n, &input.q) != 2)
	// 	return 1;

	// //clock_t tic = clock();
	// if (input.n < 1 || input.n > 100000000)
	// 	return 1;

	// if (input.q < 1 || input.q > 20000)
	// 	return 1;

	// // do {
	// // 	scanf("%d", &x[i++]);
	// // 	if (x[i - 1] < 1 || x[i - 1] > 100000000)
	// // 		return 1;

	// // } while (i != input.q);

	// for (i = 1; i <= input.n; i++){
	// 	if (is_prime_mr(i))
	// 		tot_prime++;
	// }
	// printf("%d\n", tot_prime);

	// for (i = 0; i < input.q; i++)
	// 	printf("%d\n", isPrime(x[i]) ? 1 : 0 );

	//clock_t tock = clock();

	
	//printf("Time: %f\n", (double)(tock - tic) / CLOCKS_PER_SEC);

	return 0;
}