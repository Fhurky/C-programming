#include <stdio.h>

long long gcd(long long int a, long long int b){
	long long int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

int main() {
    long long result = 1;
    int i;
    
    for (i=2;i<=20;i++){
        result = lcm(result, i);
    }
    printf("The smallest positive number divisible by all numbers from 1 to 20 is: %lld\n", result);
    
    return 0;
}
