#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEPARATOR "#<ab@17943918#@>#"

int compare_tab(int* tab1, int* tab2) {
    int i = 0;
    while (tab1[i] != -1) {
        if (tab1[i] != tab2[i]) return -1;
        i++;
    }
    return (tab2[i] == -1 && tab1[i] == -1) ? 0 : -1;
}

int main() {
    {
        int tab1[] = {1, 1, 5, 4, 7, -1};
        int tab2[] = {1, 1, 5, 4, 7, -1};
        printf("%d\n", compare_tab(tab1, tab2));
        ;
    }
    printf("%s\n", SEPARATOR);
    {
        int tab1[] = {1, 1, 5, -1};
        int tab2[] = {1, 1, 5, 4, 7, -1};
        printf("%d\n", compare_tab(tab1, tab2));
        ;
    }
    printf("%s\n", SEPARATOR);
    {
        int tab1[] = {1, 1, 5, 4, 7, -1};
        int tab2[] = {1, 1, -1};
        printf("%d\n", compare_tab(tab1, tab2));
        ;
    }
    printf("%s\n", SEPARATOR);
    {
        int tab1[] = {1, 1, 5, 4, 8, -1};
        int tab2[] = {1, 1, 5, 4, 7, -1};
        printf("%d\n", compare_tab(tab1, tab2));
        ;
    }
    printf("%s\n", SEPARATOR);
    {
        int tab1[] = {-1};
        int tab2[] = {-1};
        printf("%d\n", compare_tab(tab1, tab2));
        ;
    }
    return 0;
}
