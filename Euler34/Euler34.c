#include <stdio.h>

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int sumOfFactorialOfDigits(int number){
    int sum = 0;
    int temp = number;

    while(temp > 0){
        sum += factorial(temp % 10);
        temp /= 10;
    }

    return sum;
}

int main(){
    int sum = 0;
    int i;
    // Iterate through numbers and check for the condition
    for(i=10; i<100000; i++){
        if(i == sumOfFactorialOfDigits(i)){
            sum += i;
        }
    }

    printf("Sum of numbers which are equal to the sum of the factorial of their digits: %d\n", sum);

    return 0;
}

