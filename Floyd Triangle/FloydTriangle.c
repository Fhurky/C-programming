#include<stdio.h>
#define MAX 100

void floyd_ucgeni(int satir){
	
	int floyd_numbers[satir];	
	int i,j,counter=1,number=1;
	
	for(i=0;i<satir;i++){
		
		floyd_numbers[i] = number;
		for(j=0;j<counter;j++){
			printf("%d ",number);
			number++;
		}
		printf("\n");
		counter++;
		
	}	
	printf("\n-------Floyd numbers--------\n");	
	for(i=0;i<satir;i++){
		printf("%d ", floyd_numbers[i]);
	}	
}

int main(){

    int satir;
    do{
    	printf("Enter the number of line: ");
    	scanf("%d", &satir);
	}while(satir>MAX);

    floyd_ucgeni(satir);

	return 0;
}