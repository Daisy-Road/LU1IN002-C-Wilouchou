#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Problem of this course
// Given a sorted array of integers, we need to create an optimized function
// capable of finding the index of a certain value in the table Objectives:
// Understanding complexity and learning basic finding algorithms

int *tab_init(int n);
void affiche(int *tab, int n);
int *tab_init_alea(size_t len);
int find_val(int value, int *t, size_t len);
int find_val_optimized(int value, int *t, size_t len);
int find_val_recursive(int value, int *t, size_t len);

int main(int argc, char *argv[]) {
    // We can now call the program with arguments like so:
    // ./Cours5.out 10 Toto for instance
    // Where argc=3 and argv[0] = ./Cours5.out, argv[1] = 10, argv[2] = Toto

    int *tab;
    srand(time(NULL));

    if (argc != 2) {
        printf("Invalid usage: ./Cours5.out <number of elements>\n");
        return 1; // We return 1 due to an error
    }

    int len = atoi(argv[1]); // atoi converts a string to an int
    printf("Generating a table of %d elements...\n", len);
    // tab = tab_init_alea(len);

    tab = tab_init(len);
    // now the array is sorted

    // affiche(tab, len);
    // int index = find_val(len / 2, tab, len); // We search for the value len/2
    int index = find_val_recursive(len / 2, tab, len);
    if (index != -1) {
        printf("The value %d is at index %d\n", len / 2, index);
    } else {
        printf("The value %d was not found\n", len / 2);
    }

    // If we use time ./Cours5.out <higher values> we can see that the program
    // time complexity is O(n)
    return 0;
}

int *tab_init(int n) {
    int *tab = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        tab[i] = i;
    }
    return tab;
}

void affiche(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

int *tab_init_alea(size_t len) {
    int *tab = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        tab[i] = rand() % len;
    }
    return tab;
}

int find_val(int value, int *t, size_t len) {
    for (int i = 0; i < len; i++) {
        if (t[i] == value)
            return i;
    }
    return -1;
}

int find_val_optimized(int value, int *t, size_t len) {
    // We can use the fact that the table is ordered to optimize the search
    // To do that let's write a dicotomic algorithm
    int start = 0;
    int end = len - 1;
    while (end >= start) {
        int pivot = (start + end) / 2;
        if (value == t[pivot]) {
            return value;
        } else if (t[pivot] > value) {
            // We check for the first half of the table
            end = pivot - 1;
        } else {
            // We check for the second half of the table
            start = pivot + 1;
        }
        printf("start = %d | end = %d\n", start, end);
    }
    return -1;
}

int find_val_recursive(int value, int *t, size_t len) {
    int pivot = len / 2;
    if (len == 0) {
        return -1; // Will not work, because the return value is added to the
                   // pivot
    }
    if (len == 1) {
        return (t[0] == value) ? 0 : -1; // Will not work, because the return
                                         // value is added to the pivot
    }

    if (t[pivot] > value) {
        // We check the first half of the table
        return find_val_recursive(value, t, pivot);
    }
    // We check the second half of the table
    return pivot + find_val_recursive(value, t + pivot, pivot);
}
