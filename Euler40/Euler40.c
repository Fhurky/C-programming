#include <stdio.h>

int main(){
    int positions[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int product = 1, i;
    char concatenated[1000000];

    // Concatenate positive integers
    int current_length = 0;
    for(i=1; current_length<1000000; i++){
        int length = sprintf(concatenated + current_length, "%d", i);
        current_length += length;
    }

    // Calculate the product of specified digits
    for(i=0; i<7; i++){
        int digit = concatenated[positions[i]-1] - '0';
        product *= digit;
    }

    // Output the result
    printf("The product of the specified digits is: %d\n", product);

    return 0;
}

