#include <stdio.h>
#include <stdbool.h>

bool isPandigital(int a, int b, int c) {
    int digits[10] = {0};
    int i;
    while (a > 0) {
        digits[a % 10]++;
        a /= 10;
    }

    while (b > 0) {
        digits[b % 10]++;
        b /= 10;
    }

    while (c > 0) {
        digits[c % 10]++;
        c /= 10;
    }

    // Check if all digits from 1 to 9 are used exactly once
    for(i=1; i<=9; i++){
        if(digits[i] != 1){
            return false;
        }
    }

    return true;
}

int main(){
    int sum = 0, a, b, i;
    bool products[10000] = {false};
  
    for(a=1; a<=9999; a++){
        for(b=1; b<=9999; b++){
            int product = a * b;
            if(product > 9999){
                break; // No need to continue searching for this a
            }

            if(isPandigital(a, b, product)){
                products[product] = true;
            }
        }
    }

    // Sum all unique pandigital products
    for(i=1; i<10000; i++){
        if(products[i]){
            sum += i;
        }
    }

    printf("Sum of pandigital products: %d\n", sum);

    return 0;
}

