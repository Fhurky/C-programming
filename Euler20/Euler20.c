#include <stdio.h>

#define MAX_DIGITS 300 // Adjust the size based on the expected result length

void multiply(int result[], int multiplier){
    int carry = 0;
    int i;
    for(i=0; i<MAX_DIGITS; i++){
        int product = result[i] * multiplier + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
}

int main(){
	int i;
    int result[MAX_DIGITS] = {0};
    result[0] = 1;

    // Calculate 100!
    for (i = 2; i <= 100; i++) {
        multiply(result, i);
    }

    // Calculate the sum of the digits
    int sum = 0;
    for(i=0; i<MAX_DIGITS;i++){
        sum += result[i];
    }

    printf("Sum of the digits in 100!: %d\n", sum);

    return 0;
}

