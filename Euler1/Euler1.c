#include<stdio.h>
#define N 1000

int main(){
    int count = 0;
    int i;

    for(i=0;i<N;i++){
        if((i%3==0)||(i%5==0)){
            count = count + i;
        }
    }
    printf("%d", count);
    return 0;
}