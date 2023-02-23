#include <stdio.h>
#include <stdlib.h>

int compte(char c, char* s) {
    int res = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) res++;
        i++;
    }
    return res;
}

void affiche_occur(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c apparaît %d fois\n", s[i], compte(s[i], s));
        i++;
    }
}

void affiche_occur_better(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        int j = 0;
        while (j < i && s[j] != s[i]) {
            // On souhaite atteindre i avec j sans que l'élément
            // situé à s[i] qui serait traîté soit égal aux éléments
            // précédent parcouru par j
            j++;
        }
        if (j == i) printf("%c apparaît %d fois\n", s[i], compte(s[i], s));
        i++;
    }
}

int pos_freq(char* s) {
    int i = 0;
    int max = 0;
    int now;
    int res = 0;
    while (s[i] != '\0') {
        int j = 0;
        while (j < i && s[i] != s[j]) {
            j++;
        }
        if (i == j) {
            now = compte(s[i], s);
            if (now > max) {
                max = now;
                res = i;
            }
        }
        i++;
    }
    return res;
}

int main() {
    char* s = "Bonjour comment allez-vous ?";
    affiche_occur_better(s);
    int index = pos_freq(s);
    printf("La lettre la plus répétée est %c en %d\n", s[index], index);
    return 0;
}
