#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_pandigital(int n){
    char str[10];
    sprintf(str, "%d", n);
    int i,j;
    // Sorting the string to check if it is pandigital
    for(i=0; str[i] != '\0'; i++){
        for(j=i+1; str[j] != '\0'; j++){
            if(str[i] > str[j]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    // Checking if the sorted string is "123456789"
    return (strcmp(str, "123456789") == 0);
}

int concatenated_product(int num, int n){
    char result[10] = "";
    int length = 0;
    int i;
    for(i=1; i<=n; i++){
        int product = num * i;
        char temp[10];
        sprintf(temp, "%d", product);

        // Concatenating the product to the result
        strcat(result, temp);
        length += strlen(temp);

        // Break if the length exceeds 9
        if(length >= 9){
            break;
        }
    }

    return atoi(result);
}

int find_largest_pandigital(){
    int largest_pandigital = 0;
    int num, n;
    for(num=1; num<10000; num++){
        for(n=2; n<= 9; n++){
            int product = concatenated_product(num, n);

            if (length_of_number(product) == 9 && is_pandigital(product)){
                largest_pandigital = (product > largest_pandigital) ? product : largest_pandigital;
            }
        }
    }

    return largest_pandigital;
}

int length_of_number(int n){
    int length = 0;
    while(n>0){
        n /= 10;
        length++;
    }
    return length;
}

int main(){
    int result = find_largest_pandigital();
    printf("The largest 1 to 9 pandigital 9-digit number is: %d\n", result);

    return 0;
}

