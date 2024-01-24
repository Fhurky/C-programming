#include<stdio.h>
#include<math.h>

int isPrime(int number){
	
	int i = 2, sqr = sqrt(number);
	
	while(i<=sqr){
		if(number % i == 0){
			return 0;
	    }
	    i++;
	}
    return 1;
}

int main(){
	
	int counter = 0, i = 2;
	
	while(counter < 10001){
		if(isPrime(i)){
			counter++;
			if(counter == 10001)
			printf("10001st prime number is: %d\n",i);
		}
		i++;
	}
	
	return 0;
}
