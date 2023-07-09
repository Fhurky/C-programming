#include<stdio.h>

void GCD(numb1,numb2){
	int min,counter=1,gcd=1;
	if(numb1<numb2){
		min = numb1;
	}
	else{
		min = numb2;
	}
	while(counter<=min){
		if((numb1%counter == 0)&& (numb2%counter == 0)){
			gcd=counter;
			
		
		}
		counter++;
	}
	printf("\nGCD:  %d", gcd);
}

int main(){
    
	int numb1,numb2;
	
	printf("Enter two numbers:\t");scanf("%d %d",&numb1,&numb2);
	GCD(numb1,numb2);
			
	return 0;
}