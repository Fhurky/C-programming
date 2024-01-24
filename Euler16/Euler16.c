#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplyByTwo(char *number){
    int carry = 0, i,digit,product;
    int length = strlen(number);

    for(i=length-1; i>=0; i--){
        digit = number[i] - '0';
        product = digit*2 + carry;

        number[i] = (product % 10) + '0';
        carry = product / 10;
    }

    if(carry>0){
        // If there is a carry after the leftmost digit, add a new digit
        memmove(number + 1, number, length + 1);
        number[0] = carry + '0';
    }
}

int sumOfDigits(char *number){
    int sum = 0, i;
    int length = strlen(number);

    for(i=0; i<length; i++){
        sum += number[i]-'0';
    }
    return sum;
}

int main() {
    int exponent = 1000, i;
    char number[1000] = "1";  // Initialize with 2^0

    for(i=0;i<exponent; i++){
        multiplyByTwo(number);
    }

    int result = sumOfDigits(number);

    printf("Sum of the digits of 2^1000: %d\n", result);

    return 0;
}

