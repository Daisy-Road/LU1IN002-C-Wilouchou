#include <stdio.h>
#include <stdlib.h>

#define D1 3
#define D2 2
#define D3 5

size_t compte(char* s);
size_t compte_recu(char* s);

void affiche(int tab[D1][D2]) {
    // On peut écrire aussi: void affiche(int tab[][D2]) car D1 est implicite
    // pour obtenir l'élément par l'adresse
    for (int i = 0; i < D1; i++) {
        for (int j = 0; j < D2; j++) {
            printf("tab[%d][%d] = %d \n", i, j, tab[i][j]);
        }
    }
}

int main(int argc, char* argv[]) {

    if (argc != 1) { printf("Usage: %s\n", argv[0]); }

    int tab[D1][D2] = {
        {1, 2}, {3, 4}, {5, 6}}; // Un tableau de int a 2 dimensions

    // On a que: tab[1][1] = 4 qui est donné par l'adresse tab + 1 * D2 + 1

    // En C les tableaux sont empilés lignes par lignes (row-major order)
    // D'autres langages les empiles colonnes après colonnes (column-major
    // order)

    float tab2[2][2][2] = {
        {{1, 2}, {2, 3}},
        {{1, 2}, {2, 3}}}; // Un tableau de float a 3 dimensions

    affiche(tab);

    for (char c = '0'; c <= '9'; c++) {
        printf("%d -> %c\n", c, c);
        // affiche les codes ASCII des chiffres et le caractère
    }

    // En C, une chaîne de caractère se termine par le caractère '\0'
    // qui est le code ASCII 0 et codé sur 1 octet comme tous les autres
    // caractères
    char* hw = "Hello World!";
    // Une chaîne de caractère dont le '\0' est implicite
    printf("%s\n", hw);

    char s[8] = "Bonjour"; // Une chaîne de caractère de 8 caractères:
                           // {'b', 'o', 'n', 'j', 'o', 'u', 'r', '\0'}
    printf("%s\n", s);

    char s2[8] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', '\0'}; // Même chose
    printf("%s\n", s2);

    char s3[7] = "Bonjour";
    // Ici la chaîne ne contient pas le '\0' car il n'y a pas assez de place
    // pour le stocker
    printf("%s\n", s3);

    char s4[] = "Hello";
    // Une chaîne de caractère de 6 caractères sous entendu:
    //  {'H', 'e', 'l', 'l', 'o', '\0'}
    printf("%s\n", s4);

    printf("Longueur de \"%s\": %lu\n", argv[1], compte_recu(argv[1]));

    return 0;
}

// Objectif: Compter le nombre de caractères dans une chaîne de caractères
size_t compte(char* s) {
    /* Si la chaîne ne se termine pas par \0, la fonction renvoie -1 */
    char c = s[0];
    size_t i = 0;
    while (c != '\0' && i < 500) {
        ++i;
        c = *(s + i);
    }
    if (i == 500) return -1; // Timeout
    return i;
}

size_t compte_recu(char* s) {
    if (*s == '\0') return 0;
    return 1 + compte_recu(s + 1);
}

// Objectif concaténer deux chaînes de caractères

char* concatenate(char* s1, char* s2) {
    size_t len1 = compte(s1);
    size_t len2 = compte(s2);
    char* res = malloc((len1 + len2 + 1) * sizeof(char));
    for (int i = 0; i < len1; i++)
        res[i] = s1[i];
    for (int i = len1; i < len1 + len2; i++)
        res[i] = s2[i - len1];
    res[len2] = '\0';
    return res;
}

// Utiliser une méthode récursive n'est pas optimisée ici car la mémoire est
// allouée dynamiquement

// Le header <string.h> (utilisez man !)
// strcpy -> Copy the string provided
// strcat -> Concatenate the 2 strings provided inside the first string
// strlen -> Returns the size of the string provided
