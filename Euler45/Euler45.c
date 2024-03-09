#include <stdio.h>
#include <math.h>

int is_square(int n) {
    int root = (int)sqrt(n);
    return n == root * root;
}

typedef struct {
    int current;
} Pentagonals;

Pentagonals createPentagonals() {
    Pentagonals p;
    p.current = 1;
    return p;
}

int nextPentagonal(Pentagonals *p) {
    int result = p->current * (3 * p->current - 1) / 2;
    p->current++;
    return result;
}

int solve() {
    Pentagonals pentagonals = createPentagonals();

    int next_n = 143 + 1;
    int next_y = 4 * next_n - 1;

    for (int y = next_y;; y++) {
        if (!is_square(3 * y * y - 2)) {
            continue;
        }
        int x = (int)sqrt(3 * y * y - 2);
        if ((x + 1) % 6 == 0 && (y + 1) % 4 == 0) {
            int m = (x + 1) / 6;
            return nextPentagonal(&pentagonals);
        }
    }
}

int main() {
    int result = solve();
    printf("Result: %d\n", result);
    return 0;
}

