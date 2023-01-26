#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define NULL ((void *)0) // NULL is a pointer to nothing


void swap(int* a, int* b);
void swap_none(int a, int b);

int main() {
    int i = 4;
    int* pNull = NULL; // pNull is a pointer to nothing
    int* p = &i; // p is a pointer to the i integer
    printf("P is the pointer of i\n\ni is at %p (p) and p is at %p (&p), the value of i is %d (*p)\n", p, &p, *p);

    int a = 4;
    int b = 5;
    printf("a is %d and b is %d\n", a, b);
    swap_none(a, b);
    printf("swap_none >> a is %d and b is %d\n", a, b);
    swap(&a, &b);
    printf("swap >> a is %d and b is %d\n", a, b);

    return 0;
}

void swap(int* a, int* b) {
    //Permutes the values of a and b
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_none(int a, int b) {
    //Permutes the values of a and b
    // Doesn't work because the values are copied
    int temp = a;
    a = b;
    b = temp;
}
