#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool is_prime(int n){
	int i;
    if(n<2){
        return false;
    }
    for(i=2; i<= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void generate_pandigital(char *str, int start, int end, int *max_pandigital_prime){
	int i;
    if(start == end){
        int num = atoi(str);
        if(is_prime(num) && num > *max_pandigital_prime){
            *max_pandigital_prime = num;
        }
    }else{
        for(i=start; i<=end; i++){
            // Swap characters at positions start and i
            char temp = str[start];
            str[start] = str[i];
            str[i] = temp;

            // Recursively generate pandigital numbers
            generate_pandigital(str, start + 1, end, max_pandigital_prime);

            // Swap back to backtrack
            temp = str[start];
            str[start] = str[i];
            str[i] = temp;
        }
    }
}

int main(){
	int n, i;
    int max_pandigital_prime = 0;

    for(n=9; n>= 1; n--){
        char pandigital_str[n + 1];
        for(i=1; i<=n; i++){
            pandigital_str[i - 1] = '0' + i;
        }
        pandigital_str[n] = '\0';

        generate_pandigital(pandigital_str, 0, n - 1, &max_pandigital_prime);
        if(max_pandigital_prime > 0){
            break;
        }
    }

    printf("The largest n-digit pandigital prime is: %d\n", max_pandigital_prime);

    return 0;
}

