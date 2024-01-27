#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 1000

// Function to check if a number is prime
bool isPrime(int num){
	int i;
    if (num < 2){
        return false;
    }
    for(i=2; i*i<=num; ++i){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

// Function to find the number of consecutive primes for a given quadratic expression
int consecutivePrimes(int a, int b){
    int n = 0;
    while(isPrime(n*n + a*n + b)){
        n++;
    }
    return n;
}

// Function to find the product of coefficients a and b that produce the maximum number of primes
int findProductOfCoefficients(){
    int maxConsecutivePrimes = 0;
    int product = 0;
    int a,b;
    int currentConsecutivePrimes;
    for(a =-LIMIT+1; a<LIMIT; ++a){
        for(b = 2; b <=LIMIT; ++b){
            if(isPrime(b)){
                currentConsecutivePrimes = consecutivePrimes(a, b);
                if (currentConsecutivePrimes > maxConsecutivePrimes){
                    maxConsecutivePrimes = currentConsecutivePrimes;
                    product = a*b;
                }
            }
        }
    }

    return product;
}

int main(){
    int result = findProductOfCoefficients();

    printf("The product of the coefficients a and b is: %d\n", result);

    return 0;
}

