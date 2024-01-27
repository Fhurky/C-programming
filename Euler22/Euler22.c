#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20  // Assuming a maximum name length of 20 characters

int score(char *name){
    int scores[26];
    int i;
    for(i=0; i<26; ++i){
        scores[i] = i+1;
    }

    int sum = 0;
    for(i=0; i<strlen(name); ++i){
        sum += scores[name[i] - 'A'];
    }

    return sum;
}

void solve(){
	int i;
    // Load names from a file (assuming p022_names.txt contains names)
    FILE *file = fopen("ames.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Count the number of names in the file
    int numNames = 0;
    char name[MAX_NAME_LENGTH];
    while(fscanf(file, "\"%19[^\"]\",", name) == 1){
        ++numNames;
    }

    // Rewind the file to read names again
    rewind(file);

    // Allocate memory for names
    char **names = (char **)malloc(numNames * sizeof(char *));
    if(names == NULL){
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Read names into the array
    for(i=0; i<numNames; ++i){
        names[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (names[i] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        fscanf(file, "\"%19[^\"]\",", names[i]);
    }

    // Close the file
    fclose(file);

    // Sort names in lexicographical order
    qsort(names, numNames, sizeof(char *), (int (*)(const void *, const void *))strcmp);

    // Calculate the answer
    int answer = 0;
    for(i=0; i<numNames; ++i){
        answer += (i + 1) * score(names[i]);
    }

    // Print the answer
    printf("Answer: %d\n", answer);

    // Free allocated memory
    for(i=0; i<numNames; ++i){
        free(names[i]);
    }
    free(names);
}

int main(){
    solve();
    return 0;
}

