#include <stdio.h>

// Function to calculate the sum of proper divisors of a number
int sumOfDivisors(int num){
    int sum = 1, i; // Start with 1 since all numbers have 1 as a divisor
    for(i=2; i*i<=num; i++){
        if (num % i == 0) {
            sum += i;

            // If the divisors are not the same, add the other divisor
            if(i*i!=num){
                sum += num / i;
            }
        }
    }

    return sum;
}

int main(){
    const int limit = 10000;
    int amicableSum = 0, a,b;
    for(a=2; a<limit; a++){
        b = sumOfDivisors(a);
        // Check if a and b form an amicable pair
        if(b>a && sumOfDivisors(b) == a){
            amicableSum += (a + b);
        }
    }
    printf("The sum of amicable numbers under %d is: %d\n", limit, amicableSum);

    return 0;
}

