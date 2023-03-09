#include <stdio.h>

// Objectif: Récursion sur les tableaux

// Maximum dans un tableau

int max(int tab[], int n) {
    if (n == 1) return tab[0];
    int m = max(tab + 1, n - 1);
    if (tab[0] > m) return tab[0];
    else return m;
}

// Somme des éléments d'un tableau

int somme(int tab[], int n) {
    if (n == 1) return tab[0];
    return tab[0] + somme(tab + 1, n - 1);
}

// Evaluation d'un palindrome

int palindrome(char* s, int n) {
    if (n == 1) return 1;
    if (n == 2) return s[0] == s[1];
    if (s[0] != s[n - 1]) return 0;
    return palindrome(s + 1, n - 2);
}

int main() { return 0; }
