#include <stdio.h>
#include <math.h>
#define MAX 100

int main() {
    const int lowerLimitA = 2;
    const int upperLimitA = MAX;
    const int lowerLimitB = 2;
    const int upperLimitB = MAX;
    int i,j,a,b;
    long long distinctTerms[MAX*MAX + 1] = { 0 };  // Index 0 is not used
    int count = 0;
    long long int result;

    for(a=2; a<=100; a++){
        for(b=2; b<=100; b++) {
            result = pow(a,b);
            distinctTerms[count++] = result;
        }
    }

    // Sort the array
    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(distinctTerms[i] > distinctTerms[j]){
                // Swap
                long long temp = distinctTerms[i];
                distinctTerms[i] = distinctTerms[j];
                distinctTerms[j] = temp;
            }
        }
    }

    // Count distinct terms
    int distinctCount = 1;
    for(i=1; i<count; i++){
        if(distinctTerms[i] != distinctTerms[i-1]){
            distinctCount++;
        }
    }

    // Print the number of distinct terms
    printf("Distinct terms: %d\n", distinctCount);

    return 0;
}

