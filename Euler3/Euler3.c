#include <stdio.h>

long long largestPrimeFactor(long long n) {
    long long largestFactor = -1;
    
    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }
    long long i;
    
    for (i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }
    
    if (n > 2) {
        largestFactor = n;
    }
    
    return largestFactor;
}

int main() {
    long long number = 600851475143;
    long long largestPrime = largestPrimeFactor(number);
    
    printf("The largest prime factor of %lld is: %lld\n", number, largestPrime);
    
    return 0;
}
