#include <stdio.h>

int recherche_iter(int* tab, int len, int val) {
    for (int i = 0; i < len; i++) {
        if (tab[i] == val) return i;
    }
    return -1;
}

int recherche_rec(int* tab, int len, int val) {
    if (len == 0) return -1;
    if (*(tab + len - 1) == val) return len - 1;
    return recherche_rec(tab, len - 1, val);
}

int recherche_rec_aux(int* tab, int len, int i, int val) {
    if (len == 0) return -1;
    if (*tab == val) return i;
    return recherche_rec_aux(tab + 1, len - 1, i + 1, val);
}

int est_deb(char* s1, char* s2) {
    if (*s1 == '\0') return 1;
    if (*s1 != *s2 || *s2 == '\0') return 0;
    else return est_deb(s1 + 1, s2 + 1);
}

int est_incluse(char* s1, char* s2) {
    if (*s2 == '\0') return 0;
    if (est_deb(s1, s2)) return 1;
    else return est_incluse(s1, s2 + 1);
}

int main() {
    printf("%d\n", est_incluse("ber", "alphabet"));
    return 0;
}
