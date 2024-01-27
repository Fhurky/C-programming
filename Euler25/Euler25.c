#include <stdio.h>
#include <stdint.h>

#define MAX_DIGITS 1000

void addArrays(int a[], int b[], int result[], int size){
    int carry=0,i;
    for(i=0; i<size; ++i){
        result[i] = a[i] + b[i] + carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

int findIndexFibonacciWithDigits(int digits){
    int a[1000] = {0};
    int b[1000] = {0};
    int result[1000] = {0};
    int i;
    
    a[0] = 1;
    b[0] = 1;

    int index = 2; // Starting from the 3rd Fibonacci number

    while(result[999] == 0){
        addArrays(a, b, result, 1000);
        index++;

        // Shift the arrays for the next iteration
        for(i=0; i<1000; ++i){
            a[i] = b[i];
            b[i] = result[i];
        }
    }

    return index;
}

int main(){
    int index = findIndexFibonacciWithDigits(MAX_DIGITS);

    printf("The index of the first Fibonacci term with 1000 digits is: %d\n", index);

    return 0;
}

