#include<stdio.h>
#define N 20

void decimal_to_hexadecimal(int number){
	int arr[N],found = 1,tmp,i=0;
	
	while(found && number>=0){
		tmp = number/16;
		arr[i] = number%16;
		number = tmp;
		i++;
		if(number == 0){
			found = 0;
		}
	}
	printf("\nHexadecimal:   ");
	for(;i>=1;i--){
		if(arr[i-1]<10){
			printf("%d", arr[i-1]);
		}
		else{
			printf("%c", 55+arr[i-1]);
		}
	}
}

int main(){
    
	int number;
	printf("Enter the number...\t");scanf("%d", &number);	
	decimal_to_hexadecimal(number);
	
	return 0;
}