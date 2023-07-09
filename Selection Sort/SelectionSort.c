#include<stdio.h>

void selection_sort(int *arr,int dimension){
	int i,j,min;	
	for(i=0;i<dimension;i++){
		for(j=i;j<dimension;j++){
			if(arr[i] > arr[j]){
				min = arr[i];
				arr[i] = arr[j];
				arr[j] = min;
			}
		}
	}
}
void print_arr(int *arr,int dimension){
	int i;
	for(i=0;i<dimension;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	
	int arr[7] = {4,3,5,7,0,-3,5};
	int dimension = sizeof(arr)/sizeof(arr[0]);
	
	print_arr(arr,dimension);
	selection_sort(arr,dimension);
	print_arr(arr,dimension);
	
	return 0;
}