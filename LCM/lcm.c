#include<stdio.h>

void LCM(int numb1,int numb2){
	int min,max,counter=1,found = 1;
	
	if(numb1>numb2){
		max = numb1;
		min = numb2;
	}
	else{
		max = numb2;
		min = numb1; 
	}
	while(found){
		if((max*counter)%min == 0){
			found = 0;
		}
		counter++;
	}
	printf("\nLCM:   %d",max*(counter-1));
}

int main(){
	int numb1,numb2;
	printf("\nEnter two numbers:\t");scanf("%d %d", &numb1,&numb2);
	LCM(numb1,numb2);
	
	return 0;
}