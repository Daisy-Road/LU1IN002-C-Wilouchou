#include <stdio.h>

void permute(int* a, int* b);
void permute_circulaire(int* a, int* b, int* c);

int main() {
    int a, b, c;
    a=10; b=20; c=30;
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    permute_circulaire(&a, &b, &c);
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    return 0;
}

void permute(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute_circulaire(int* a, int* b, int* c) {
    permute(a, b);
    permute(b, c);
}
