#include <stdio.h>
#include <string.h>

// Convert a string to a number
unsigned long long str2num(const char *x){
    // Process string from left to right
    unsigned long long result = 0;
    while(*x != '\0'){
        // Shift digits
        result *= 10;
        // Add new digit on the right-hand side
        result += *x - '0'; // was ASCII
        x++;
    }
    return result;
}

int main(){
    // Available digits
    char pan[] = "0123456789"; // Unlike other problems, zero is allowed this time

    // Remove a few digits if the test case requires this
    unsigned int maxDigit;
    scanf("%u", &maxDigit);
    pan[maxDigit + 1] = '\0';

    // All divisors
    const unsigned int primes[] = {2, 3, 5, 7, 11, 13, 17};

    // Result
    unsigned long long sum = 0;

    // Look at all permutations
    do{
        // Let's assume it's a great number ;-)
        int ok = 1;

        // Check each 3-digit substring for divisibility
        for (unsigned int i = 0; i + 2 < maxDigit; i++)
        {
            // Check pan[1..3] against primes[0],
            // Check pan[2..4] against primes[1],
            // Check pan[3..5] against primes[2] ...
            char check[4];
            strncpy(check, pan + i + 1, 3);
            check[3] = '\0';

            if (str2num(check) % primes[i] != 0)
            {
                // Nope...
                ok = 0;
                break;
            }
        }

        // Passed all tests, it's great indeed!
        if (ok)
            sum += str2num(pan);
    }while (next_permutation(pan, pan + strlen(pan)));

    printf("%llu\n", sum);
    return 0;
}

