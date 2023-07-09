#include<stdio.h>

void binary_search(int *arr,int dimension,int number){
	int right = dimension;
	int left=0,middle = 0,found = 1;
	
	while (found && left<=right){
		
		middle = (left+right)/2;
		
		if(number == arr[middle]){
			found = 0;
			printf("Found the number at %d place",middle+1);
			return;
		}
		else if(number<arr[middle]){
			right = middle-1;
		}
		else if(number>arr[middle]){
			left = middle+1;
		}		
	}
	printf("\nThere is not the number in the array...\n");
}

int main(){
	
	int arr[10] = {1,3,10,21,24,32,50,100,101,121};
	int dimension = sizeof(arr)/sizeof(arr[0]);
	int number;
	
	printf("Enter the number...\t");scanf("%d", &number);
	
	binary_search(arr,dimension,number);
	
	return 0;
}