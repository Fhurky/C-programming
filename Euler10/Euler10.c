#include <stdio.h>

int isPrime(int num){
	int i ;
    if(num < 2){
        return 0;  // Not prime
    }

    for(i=2; i*i<=num; i++){
        if(num % i == 0){
            return 0;  // Not Prime
        }
    }

    return 1;  // Prime
}

int main(){
    int limit = 2000000, i;
    long long sum = 0;

    for (i=2; i<limit; i++){
        if (isPrime(i)){
            sum += i;
        }
    }

    printf("The sum of all prime numbers under 2 million: %lld\n", sum);

    return 0;
}

