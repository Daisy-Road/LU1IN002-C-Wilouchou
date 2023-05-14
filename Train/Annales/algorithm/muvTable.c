#include <stdio.h>

void moveRight(int t[], size_t n);
void moveLeft(int t[], size_t n);
void printTable(int t[], size_t n);

int main() {
    int tab[5] = {1, 2, 3, 4, 5};
    printTable(tab, 5);
    moveRight(tab, 5);
    printTable(tab, 5);
    moveLeft(tab, 5);
    printTable(tab, 5);
}

void moveRight(int t[], size_t n) {
    int start = t[n - 1];
    for (int i = n - 1; i > 0; i--)
        t[i] = t[i - 1];
    t[0] = start;
}

void moveLeft(int t[], size_t n) {
    int end = t[0];
    for (int i = 0; i < n - 1; i++)
        t[i] = t[i + 1];
    t[n - 1] = end;
}

void printTable(int t[], size_t n) {
    // Unsafe with empty table
    printf("{");
    for (int i = 0; i < n - 1; i++)
        printf("%d, ", t[i]);
    printf("%d}\n", t[n - 1]);
}
