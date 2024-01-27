#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TARGET_PERMUTATION 1000000

// Function to calculate the factorial of a number
long long factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n*factorial(n-1);
}

// Function to find the millionth lexicographic permutation
void findLexicographicPermutation(int digits[], int target, char result[]){
    int remainingDigits[N];
    int i, j;
    int index;

    // Initialize remainingDigits array
    for(i=0; i<N; ++i){
        remainingDigits[i] = digits[i];
    }

    target -= 1; // Adjust for zero-based indexing

    for(i=N; i>0; --i){
        index = target / factorial(i-1);
        target %= factorial(i-1);

        result[N-i] = remainingDigits[index] + '0';  // Convert to character

        // Remove the used digit from remainingDigits array
        for(j=index; j<N-1; ++j){
            remainingDigits[j] = remainingDigits[j+1];
        }
    }

    result[N] = '\0'; // Null-terminate the string
}

int main(){
    int digits[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char result[N+1]; // +1 for null terminator

    findLexicographicPermutation(digits, TARGET_PERMUTATION, result);

    printf("The %d-th lexicographic permutation is: %s\n", TARGET_PERMUTATION, result);

    return 0;
}

