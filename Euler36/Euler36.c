#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is palindromic in base 10
bool isPalindromicDecimal(int n){
    int original = n;
    int reverse = 0;

    while(n>0){
        reverse = reverse*10 + n%10;
        n /= 10;
    }

    return original == reverse;
}

// Function to check if a number is palindromic in base 2
bool isPalindromicBinary(int n){
    int original = n;
    int reverse = 0;

    while(n>0){
        reverse = reverse << 1 | n % 2;
        n /= 2;
    }

    return original == reverse;
}

int main(){
    int limit = 1000000;
    int sum = 0, i;

    for(i=1; i<limit; i++){
        if(isPalindromicDecimal(i) && isPalindromicBinary(i)){
            sum += i;
        }
    }

    printf("The sum of all numbers, less than one million, "
           "which are palindromic in both base 10 and base 2 is: %d\n", sum);

    return 0;
}

