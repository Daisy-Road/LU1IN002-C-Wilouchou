#include <assert.h>
#include <stdio.h>

int plusGrand(int a, int b, int c);

int main() {
    assert(plusGrand(10, 9, 10) == 10);
    assert(plusGrand(1, 3, 2) == 3);
    assert(plusGrand(2, 2, 2) == 2);
    assert(plusGrand(3, 2, 1) == 3);
    assert(plusGrand(2, 1, 3) == 3);
    int a = 5;
    int b = 8;
    int c = 1;
    int d = 19;
    int e = 7;
    printf("La variable la plus grande est: %d\n",plusGrand(plusGrand(a, b, c), d, e));
    return 0;
}

int plusGrand(int a, int b, int c) {
    if(a > b && a > c) {
        return a;
    }
    else if(b > c) {
        return b;
    }
    return c;
}

