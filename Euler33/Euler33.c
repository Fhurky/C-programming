#include <stdio.h>

int gcd(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplifyFraction(int *numerator, int *denominator){
    int commonFactor = gcd(*numerator, *denominator);
    *numerator /= commonFactor;
    *denominator /= commonFactor;
}

int main(){
    int productNumerator = 1;
    int productDenominator = 1;
    int numerator, denominator;
    for(numerator=10; numerator<=99; numerator++){
        for(denominator=numerator+1; denominator<=99; denominator++){
            int num1 = numerator / 10;
            int num2 = numerator % 10;
            int den1 = denominator / 10;
            int den2 = denominator % 10;

            if(num2 == 0 && den2 == 0){
                continue; // Skip trivial examples
            }

            if(num1 == den1 && numerator * den2 == denominator * num2){
                productNumerator *= num2;
                productDenominator *= den2;
            }else if(num1 == den2 && numerator * den1 == denominator * num2){
                productNumerator *= num2;
                productDenominator *= den1;
            }else if(num2 == den1 && numerator * den2 == denominator * num1){
                productNumerator *= num1;
                productDenominator *= den2;
            }else if(num2 == den2 && numerator * den1 == denominator * num1){
                productNumerator *= num1;
                productDenominator *= den1;
            }
        }
    }

    simplifyFraction(&productNumerator, &productDenominator);

    printf("The value of the denominator in its lowest common terms: %d\n", productDenominator);

    return 0;
}

