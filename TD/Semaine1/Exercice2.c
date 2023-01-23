#include <stdio.h>

float multi(int k, float x);

int main() {
    int op1 = 3;
    float op2 = 2.7;

    printf("%d * %.2f = %.2f\n", op1, op2, multi(op1, op2));

    return 0;
}

float multi(int k, float x) {
    return k * x;
}
