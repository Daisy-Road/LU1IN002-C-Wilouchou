/* Nous souhaitons calculer la position a laquelle un caractere apparait pour la
premiere fois dans une chaine de caracteres.

- Completez la fonction indCarac pour qu'elle retourne l'indice de la permiere
apparition d'un caractere donne dans une chaine de caractere. La fonction doit
prendre en parametres la chaine de caracteres et le caractere recherche. Elle
retourne -1 si le caractere n'apparait pas dans la chaine.

- Completez la fonction main pour afficher le resultat. Le message affiche doit
dependre du resultat de l'appel a la fonction indCarac. N'oubliez pas de
remplacer les ... en parametre des appels a printf.

La valeur de la chaine et le caractere recherche sont definis par des primitives
#define, ces valeurs seront modifiees pour tester votre programme. Vous pouvez
les modifier pour effectuer des tests.
*/

#include <stdio.h>

#define VALCHAINE "azertyuiop"
#define CARACT 't'

int indCarac(char* s, char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) return i;
        i++;
    }
    return -1;
}

int main() {
    /* NE MODIFIEZ PAS L'INSTRUCTION SUIVANTE
    ELLE PERMET D'INITIALISER LE TABLEAU */
    char s[] = VALCHAINE;
    int index = indCarac(s, CARACT);
    if (index != -1)
        printf(
            "Le caractere %c apparait pour la premiere fois en position %d\n",
            CARACT, index);
    else printf("Le caractere %c n'apparait pas dans la chaine\n", CARACT);

    return 0;
}
