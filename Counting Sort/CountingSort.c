#include <stdio.h>

void counting_sort(int *arr, int dimension);
void arr_zero(int *arr, int dimension);
void print_arr(int *arr, int dimension);
int find_max(int *arr, int dimension);

int main() {
    int arr[10] = {4, 2, 8, 1, 3,1,3,5,9,7};
    int dimension = sizeof(arr) / sizeof(arr[0]);
    
    counting_sort(arr, dimension);
    print_arr(arr, dimension);
    
    return 0;
}

void counting_sort(int *arr, int dimension) {
    int i;
    int max = find_max(arr, dimension);
    int count_arr[max + 1];  
    
    arr_zero(count_arr, max + 1);  
    
    for (i = 0; i < dimension; i++) {
        count_arr[arr[i]]++;
    }
    
    for (i = 1; i <= max; i++) {
        count_arr[i] += count_arr[i - 1];
    }
    
    int first_arr[dimension];  
    
    for (i = dimension - 1; i >= 0; i--) {
        first_arr[count_arr[arr[i]] - 1] = arr[i];  
        count_arr[arr[i]]--;
    }
    
    for (i = 0; i < dimension; i++) {
        arr[i] = first_arr[i];
    }
}

int find_max(int *arr, int dimension) {
    int max = arr[0], i;
    for (i = 0; i < dimension; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void arr_zero(int *arr, int dimension) {
    int i;
    for (i = 0; i < dimension; i++) {
        arr[i] = 0;
    }
}

void print_arr(int *arr, int dimension) {
    int i;
    for (i = 0; i < dimension; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
