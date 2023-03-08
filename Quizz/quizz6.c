#include <stdio.h>

int i = 0;

int fiboRec(int n) {
    i++;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fiboRec(n - 1) + fiboRec(n - 2);
    }
}

int main() {
    printf("%d\n", fiboRec(5));
    printf("%d\n", i);
    float tab[3] = {1.2, 2.3, 3.4};
    printf("%f\n", *(tab + 2));
    return 0;
}
