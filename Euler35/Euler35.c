#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1000000

bool isPrime(int n){
	int i;
    if(n <= 1){
        return false;
    }
    for(i=2; i*i<=n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int countCircularPrimes(){
    int count = 0;
    int i,j;
    for(i=2; i<MAX; i++){
        if(isPrime(i)){
            int num = i;
            int numDigits = 0;
            int temp = num;

            while(temp > 0){
                numDigits++;
                temp /= 10;
            }

            bool isCircularPrime = true;
            for(j=0; j<numDigits-1; j++){
                int lastDigit = num % 10;
                num /= 10;
                num = lastDigit * (int)pow(10, numDigits-1) + num;

                if(!isPrime(num)){
                    isCircularPrime = false;
                    break;
                }
            }

            if(isCircularPrime){
                count++;
            }
        }
    }

    return count;
}

int main(){
    int result = countCircularPrimes();

    printf("Number of circular primes below one million: %d\n", result);

    return 0;
}

