#include<stdio.h>
#define N 20

void decimal_to_binary(int number){
	int arr[N],tmp,i=0,found = 1;
	
	while(number >= 0 && found){
	    tmp = number/2;
		arr[i]=number%2;
		number = tmp;
		i++;
		if(number == 0){
			found = 0;
		}	
	}
	printf("\nBinary:  ");
	for(;i>=1;i--){
		printf("%d",arr[i-1]);
	}	
}

int main(){
	
	int number;	
	printf("\nEnter the number...\t");scanf("%d", &number);	
	decimal_to_binary(number);
	
	return 0;
}