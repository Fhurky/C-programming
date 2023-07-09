#include <stdio.h>

int isPalindrome(int number) {
    int originalNumber = number;
    int reverse = 0;
    
    while (number > 0) {
        int remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    }
    
    return (originalNumber == reverse);
}

int findLargestPalindrome() {
    int largestPalindrome = 0;
    
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            
            if (product > largestPalindrome && isPalindrome(product)) {
                largestPalindrome = product;
            }
        }
    }
    
    return largestPalindrome;
}

int main() {
    int largestPalindrome = findLargestPalindrome();
    
    printf("The largest palindrome made from the product of two three-digit numbers is: %d\n", largestPalindrome);
    
    return 0;
}
