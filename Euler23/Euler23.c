#include <stdio.h>
#include <stdbool.h>

#define LIMIT 28123

// Function to calculate the sum of proper divisors for a given number
int sumOfDivisors(int n){
    int sum = 1 , i;  // Include 1 as a proper divisor

    for(i=2; i*i<=n; ++i){
        if(n%i == 0){
            sum += i;

            if(i!= n/i){
                sum += n/i;
            }
        }
    }

    return sum;
}

// Function to check whether a number is abundant or not
bool isAbundant(int n){
    return sumOfDivisors(n) > n;
}

int main(){
    // Generate a list of abundant numbers up to LIMIT
    int abundantNumbers[LIMIT + 1] = {0};
    int i,j;
    for(i=12; i<=LIMIT; ++i){
        if(isAbundant(i)){
            abundantNumbers[i] = 1;
        }
    }

    // Create an array to mark numbers that can be expressed as the sum of two abundant numbers
    int canBeExpressed[LIMIT + 1] = {0};
    
    // Iterate through pairs of abundant numbers, mark their sum
    for(i=12; i<=LIMIT; ++i){
        if(abundantNumbers[i]){
            for(j=i; j<=LIMIT-i; ++j){
                if(abundantNumbers[j]){
                    canBeExpressed[i+j] = 1;
                }
            }
        }
    }

    // Calculate the sum of all positive integers that cannot be written as the sum of two abundant numbers
    int result = 0;
    for(i=1; i<=LIMIT; ++i){
        if(!canBeExpressed[i]){
            result += i;
        }
    }

    printf("Sum of all positive integers that cannot be written as the sum of two abundant numbers: %d\n", result);

    return 0;
}

