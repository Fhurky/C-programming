#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define TRIANGULARS_MAX 1000 

int triangulars[TRIANGULARS_MAX];

void generateTriangulars(){
	int n;
    for(n=1; n<TRIANGULARS_MAX; ++n){
        triangulars[n] = n * (n + 1) / 2;
    }
}

int isTriangleWord(const char *word){
    int value = 0;
    int i;
    while(*word){
        if(*word >= 'A' && *word <= 'Z'){
            value += (*word - 'A' + 1);
        }
        word++;
    }
    
    for(i=1; i<TRIANGULARS_MAX; ++i){
        if(value == triangulars[i]){
            return 1;  // True
        } else if (value < triangulars[i]){
            break;  // Stop if the value is smaller than the current triangular number
        }
    }

    return 0;  // False
}

int solve(){
    generateTriangulars();

    FILE *file = fopen("words.txt", "r");
    if(!file){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    int triangleWordCount = 0;

    while(fscanf(file, "\"%49[^\"]\",", buffer) == 1){
        if(isTriangleWord(buffer)){
            printf("Triangle Word: %s\n", buffer);
            triangleWordCount++;
        }
    }

    fclose(file);
    return triangleWordCount;
}

int main(){
    int result = solve();
    printf("Number of triangle words: %d\n", result);

    return 0;
}

