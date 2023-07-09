#include<stdio.h>
#define N 16

void signedBinary_to_decimal(int *arr){

	int sonuc = 0,i,j;
	
	for(i=0;i<N;i++){
		for(j=N-1-i;j>0;j--){
			arr[i] = arr[i]*2;
		}
	}
	for(i=0;i<N;i++){
		if(i!=0){
			sonuc = sonuc + arr[i];
		}
		else{
			sonuc = sonuc - arr[i];
		}
	}
	printf("\nDecimal: %d\n",sonuc);		
}

int main(){
	int i;
	int signed_number[N];
	printf("\nEnter the binary number and start with most significant bit\n");
	for(i=0;i<N;i++){
		scanf_s("%d", &signed_number[i]);
	}
	
	signedBinary_to_decimal(signed_number);
	
	return 0;
}