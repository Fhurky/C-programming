#include <stdio.h>
#include <stdlib.h>

int findReciprocalCycleLength(int d){
    int remainder = 1, i;
    int position = 0;
    int *remainders = (int *)malloc(d * sizeof(int));

    for(i=0; i<d; ++i){
        remainders[i] = -1;
    }

    while(remainders[remainder] == -1 && remainder != 0){
        remainders[remainder] = position;
        remainder = (remainder * 10) % d;
        position++;
    }

    free(remainders);

    if(remainder == 0){
        return 0; // Non-repeating decimal
    }else{
        return position - remainders[remainder];
    }
}

int findLongestReciprocalCycle(int limit){
    int longestCycle = 0;
    int result = 0;
    int d, cycleLength;
    for(d=2; d<limit; ++d){
        cycleLength = findReciprocalCycleLength(d);
        if(cycleLength > longestCycle){
            longestCycle = cycleLength;
            result = d;
        }
    }

    return result;
}

int main(){
    int limit = 1000;
    int result = findLongestReciprocalCycle(limit);

    printf("The value of d < %d with the longest recurring cycle is: %d\n", limit, result);

    return 0;
}

