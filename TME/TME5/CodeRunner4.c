#include <stdio.h>

void compress_tab(int tab_brut[], int tab_compress[]) {
    int counted = tab_brut[0];
    int count = 1;
    int i = 1;
    int j = 0;
    while (counted != -1) {
        if (counted != tab_brut[i]) {
            if (count > 1) {
                tab_compress[j] = count;
                j++;
            }
            tab_compress[j] = counted;
            j++;
            count = 0;
        }
        counted = tab_brut[i];
        count++;
        i++;
    }
    tab_compress[j] = -1;
}

void decompress_tab(int tab_brut[], int tab_compress[]) {
    int i = 0;
    int brut = 0;
    while (tab_compress[i] != -1) {
        if (tab_compress[i] <= 1) {
            tab_brut[brut] = tab_compress[i];
            brut++;
            i++;
        } else {
            for (int j = 0; j < tab_compress[i]; j++) {
                tab_brut[brut] = tab_compress[i + 1];
                brut++;
            }
            i += 2;
        }
    }
    tab_brut[brut] = -1;
}

void affiche(int* tab, int len) {
    int not_def = 0;
    printf("tab = [");
    for (int i = 0; i < len; i++) {
        if (not_def) {
            if (i == len - 1) printf("-]");
            else printf("-, ");
        } else if (tab[i] == -1) {
            printf("-1, ");
            not_def = 1;
        } else printf("%d, ", tab[i]);
    }
    printf("\n");
}

int main() {
    int tab_brut[25];
    int tab_compress[20] = {1, 3, 0, 4, 1, 0, 3, 1, 3, 0, 1, 4, 0, 1, -1};
    decompress_tab(tab_brut, tab_compress);
    affiche(tab_brut, 25);
}
