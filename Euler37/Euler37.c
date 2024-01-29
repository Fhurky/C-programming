#include <stdio.h>
#include <stdbool.h>

#define LIMIT 1000000

bool is_prime(int n){
	int i;
    if(n<2){
        return false;
    }
    for(i=2; i*i<= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool is_truncatable_prime(int n){
    if(n<10){
        return false;
    }

    int temp = n;
    int base = 10;

    while(temp>0){
        if(!is_prime(temp) || !is_prime(n % base)){
            return false;
        }
        base *= 10;
        temp /= 10;
    }

    return true;
}

int main(){
    int count = 0;
    int sum = 0;
    int num;
    for(num=23; count<11 && num<LIMIT; num += 2){
        if(is_truncatable_prime(num)){
            sum += num;
            count++;
        }
    }

    printf("The sum of the only eleven primes that are both truncatable from left to right and right to left is: %d\n", sum);

    return 0;
}

