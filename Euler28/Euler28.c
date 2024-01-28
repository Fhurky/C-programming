#include <stdio.h>

int main(){
    const int size = 1001;
    long long sum = 1; 
    int current = 1, i, j;
    
    for(i=2; i<= size; i+=2){
        for(j=0; j<4; j++){
            current += i;
            sum += current;
        }
    }

    printf("Sum of the diagonals: %lld\n", sum);

    return 0;
}

