#include<stdio.h>

int squareSum(int);
int sumSquare(int);
int betweenSumSquares(int,int);

int main(){
	
	printf("Sum Square and Square Sum Difference: %d", betweenSumSquares(squareSum(100),sumSquare(100)));

	return 0;
}

int squareSum(int number){
	int sum = 0, i;
	sum = number * (number + 1) / 2;
	return sum * sum;
}
int sumSquare(int number){
	int sum = 0, i;
	for(i=1;i<=number;i++){
		sum = sum + i*i;
	}
	return sum;
}
int betweenSumSquares(int number1,int number2){
	if(number1 > number2){
		return number1 - number2;
	}
	else{
		return number2 - number1;
	}
}
