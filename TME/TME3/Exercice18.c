#include <stdio.h>

void echange(int* a, int* b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void tri(int* a, int* b) {
    if(*a > *b) {
        echange(a, b);
    }
}

void tri_3(int* a, int*b, int* c) {
    tri(a, b);
    tri(a, c); 
    tri(b, c);
}

int main() {
    int a=65; int b=7; int c=63;
    tri_3(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}
