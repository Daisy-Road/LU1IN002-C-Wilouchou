#include <stdio.h>
#include <stdlib.h>

int somme(int t[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += t[i];
    }
    return s;
}

char *dupliquer(char s[], int n) {

    char *ptr = malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        ptr[i] = s[i];
    }
    return ptr;
}

int main() {
    int *t = (int *)malloc(sizeof(int) * 100);
    free(&t[0]);
    return 0;
}
