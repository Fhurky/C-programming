#include <stdio.h>

// Function to calculate the Nth triangle number
long long int getTriangleNumber(int n){
    return (long long int )n * (n+1) / 2;
}

// Function to calculate the number of divisors of a given number
int getDivisorsCount(long long num){
	long long int i;
    int count = 0;
    for(i= 1; i*i<=num; i++){
        if(num % i == 0){
            count += (i*i==num) ? 1 : 2;
        }
    }
    return count;
}

int main(){
    int n = 1;
    long long int triangleNumber;
	int divisorsCount;
	
    while(divisorsCount <= 500){
        triangleNumber = getTriangleNumber(n);
        divisorsCount = getDivisorsCount(triangleNumber);
        n++;
    }
    printf("The first triangle number with over 500 divisors is: %lld\n", triangleNumber);

    return 0;
}

