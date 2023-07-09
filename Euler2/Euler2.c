#include<stdio.h>

int main(){
    int sum = 0,tmp;
    int a = 1, b = 2;
    while (a <= 4000000){
        if(a%2 == 0){
            sum += a;
        }
        tmp = a;
        a = b;
        b = tmp + b;
    }
    printf("Sum:%d",sum);

    return 0;
}