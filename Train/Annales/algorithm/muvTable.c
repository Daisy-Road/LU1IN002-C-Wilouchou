#include <stdio.h>

void moveRight(int t[], size_t n);
void moveRightMultiple(int t[], size_t n, size_t times);
void moveLeft(int t[], size_t n);
void printTable(int t[], size_t n);

int main() {
    int tab[5] = {1, 2, 3, 4, 5};
    printTable(tab, 5);
    moveRight(tab, 5);
    printTable(tab, 5);
    moveLeft(tab, 5);
    printTable(tab, 5);
    moveRightMultiple(tab, 5, 2);
    printTable(tab, 5);
}

void moveRight(int t[], size_t n) {
    int start = t[n - 1];
    for (int i = n - 1; i > 0; i--)
        t[i] = t[i - 1];
    t[0] = start;
}

void moveRightMultiple(int t[], size_t n, size_t times) {
    times = times % n;
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < n - times; i++) {
        tmp = t[i + times];
        t[i + times] = t[j];
        t[j] = tmp;
        if (i + times >= n - times) j++;
    }
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
