#include <assert.h>

void permute(int* a, int* b);
void permute_circulaire(int* a, int* b, int* c);

int main() {
    int a, b, c;
    a=10; b=20; c=30;
    return 0;
}

void permute(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute_circulaire(int* a, int* b, int* c) {
    int tmp = *a;
    permute(a, b);
    permute(&tmp, c);
}
