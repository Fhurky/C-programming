#include <stdio.h>

int count_solutions(int p){
    int count = 0;
    int a, b;
    for(a=1; a<=p/3; a++){
        for(b=a; b<=(p-a)/2; b++){
            int c = p - a - b;

            // Check if it forms a right-angled triangle
            if(a*a + b*b == c*c){
                count++;
            }
        }
    }

    return count;
}

int find_max_solutions(){
    int max_solutions = 0;
    int result_p = 0;
    int p;
    for(p=1; p<1000; p++){
        int solutions = count_solutions(p);

        if(solutions > max_solutions){
            max_solutions = solutions;
            result_p = p;
        }
    }

    return result_p;
}

int main(){
    int result = find_max_solutions();
    printf("The value of p for which the number of solutions is maximized is: %d\n", result);

    return 0;
}

