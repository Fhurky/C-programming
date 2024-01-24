#include <stdio.h>

int main() {
    int a, b, c;

    for(a=1;a<=1000;a++){
        for(b=1;b<=1000;b++){
            c = 1000-a-b;  // Ensure a + b + c = 100

            if (c>0 && a*a + b*b == c*c){
                printf("Values found: a = %d, b = %d, c = %d\n", a, b, c);
                printf("ABC:%d", a*b*c);
                return 0;
            }
        }
    }
    printf("No solution found within the given constraints.\n");
    return 0;
}

