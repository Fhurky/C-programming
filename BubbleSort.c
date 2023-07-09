#include<stdio.h>

void bubble_sort(int *arr,int dimension){
	int i,j,min;
	for(i=0;i<dimension;i++){
		for(j=0;j<dimension-i-1;j++){
			if(arr[j] > arr[j+1]){
                min = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = min;
            }
		}
	}
}
void print_arr(int *arr,int dimension){
	int i;
	for(i=0;i<dimension;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	
	int arr[5] = {7,-1,3,5,2};
	int dimension = sizeof(arr)/sizeof(arr[0]);
	
	print_arr(arr,dimension);
	bubble_sort(arr,dimension);
	print_arr(arr,dimension);
	
	return 0;
}