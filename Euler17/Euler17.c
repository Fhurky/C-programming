#include <stdio.h>
#include <string.h>

// Function to convert a number to words
void numberToWords(int num, char *result) {
    // Array of words for numbers 1 to 19
    char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    // Array of words for multiples of 10
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (num < 20) {
        sprintf(result, "%s", ones[num]);
    } else if (num < 100) {
        sprintf(result, "%s%s", tens[num / 10], ones[num % 10]);
    } else if (num < 1000) {
        if (num % 100 == 0) {
            sprintf(result, "%s hundred", ones[num / 100]);
        } else {
            char remainder[50];
            numberToWords(num % 100, remainder);
            sprintf(result, "%s hundred and %s", ones[num / 100], remainder);
        }
    } else {
        sprintf(result, "one thousand");
    }
}

int main() {
    int totalLetters = 0;

    for (int i = 1; i <= 1000; i++) {
        char words[100];
        numberToWords(i, words);

        // Count the letters, ignoring spaces and hyphens
        for (int j = 0; words[j] != '\0'; j++) {
            if (words[j] != ' ' && words[j] != '-') {
                totalLetters++;
            }
        }
    }

    printf("Total letters used for numbers 1 to 1000: %d\n", totalLetters);

    return 0;
}

