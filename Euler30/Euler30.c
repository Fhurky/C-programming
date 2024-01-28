#include <stdio.h>
#include <math.h>

#define POWER 5

int sum_of_fifth_powers(int num){
    int sum = 0, digit;
    while(num>0){
        digit = num % 10;
        sum += pow(digit, POWER);
        num /= 10;
    }
    return sum;
}

int main(){
    int result_sum = 0, num;
    const int upper_limit = POWER * pow(9, POWER);  // Upper limit estimation

    for(num=10; num<=upper_limit; num++){
        if(num == sum_of_fifth_powers(num)){
            result_sum += num;
        }
    }

    printf("Sum of numbers: %d\n", result_sum);

    return 0;
}

