#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIERRE 1
#define FEUILLE PIERRE + 1
#define CISEAUX FEUILLE + 1
#define NBESSAIS 3
#define POINTSGAGNANTS 3

/* Il sera probablement nécessaire de modifier les parametres et valeur de
  retour des fonctions choix_ordinateur, choix_joueur, score et jeu */

/* Les declarations actuelles permettent de compiler et d'executer le programme
 */

void affichage_objet(int obj) {
    /* hypothèse : obj = PIERRE ou
       obj = FEUILLE ou obj = CISEAUX

     affiche le nom de l'objet correspondant à obj */

    if (obj == PIERRE) {
        printf("PIERRE");
    } else {
        if (obj == FEUILLE) {
            printf("FEUILLE");
        } else {
            printf("CISEAUX");
        }
    }
}

int choix_ordinateur(void) {
    /* hypothèse : PIERRE < FEUILLE < CISEAUX
      toutes les valeurs comprises entre PIERRE et CISEAUX sont "valables"
      renvoie une valeur choisie aléatoirement entre PIERRE et CISEAUX */
    return (rand() % (CISEAUX - PIERRE + 1)) + PIERRE;
}

int choix_joueur() {
    /* hypothèses : PIERRE < FEUILLE < CISEAUX
      renvoie la valeur choisie par le joueur
      vérifie qu'elle est comprise entre PIERRE et CISEAUX
      redemande la saisie si ce n'est pas le cas

      Si après NBESSAIS le joueur n'a pas saisi de valeur valable,
      cette dernière est tirée au sort */
    int choice;
    for (int i = 0; i < NBESSAIS; i++) {
        printf("Choisissez votre coup !\n");
        printf("%d - Pierre\n%d - Feuille\n%d - Ciseaux\n\n", PIERRE, FEUILLE,
               CISEAUX);
        scanf("%d", &choice);
        if (choice >= PIERRE && choice <= CISEAUX) { return choice; }
    }
    return choix_ordinateur();
}

void score(int coupcpu, int coupjoueur, int* scorecpu, int* scorejoueur) {
    /* hypothèses : le coup du joueur et celui de l'ordinateur sont valables
                    (égaux à PIERRE, FEUILLE ou CISEAUX)
     augmente de 1 le score du joueur si le coup du joueur est gagnant
     augmente de 1 le score de l'ordinateur si le coup de l'ordinateur est
     gagnant */
    if (coupcpu == coupjoueur) return;
    if ((((coupcpu + 1) % (CISEAUX + 1 - PIERRE)) + PIERRE) == coupjoueur) {
        // Si le joueur a joué une valeur plus grande de 1 que le cpu alors il
        // gagne Il faut que cette valeur reste comprise dans les arguments de
        // jeu
        *scorejoueur += 1;
    } else {
        *scorecpu += 1;
    }
}

void jeu() {
    /* boucle de jeu, la partie s'arrête dès qu'un des deux joueurs
     atteint POINTSGAGNANTS points */
    int scorecpu = 0;
    int prevcpu = 0;
    int scorejoueur = 0;
    int prevjoueur = 0;
    int choixjoueur;
    int choixcpu;
    int round = 1;
    while (scorecpu < POINTSGAGNANTS && scorejoueur < POINTSGAGNANTS) {
        printf("=========[Round %d]=========\n", round);
        printf("Le premier arrivé à %d l'emporte !\n", POINTSGAGNANTS);
        printf("CPU: %d/%d \t Vous: %d/%d\n\n", scorecpu, POINTSGAGNANTS,
               scorejoueur, POINTSGAGNANTS);
        choixjoueur = choix_joueur();
        printf("Vous: ");
        if (choixjoueur == PIERRE) {
            printf("PIERRE !\n");
        } else if (choixjoueur == FEUILLE) {
            printf("FEUILLE !\n");
        } else {
            printf("CISEAUX !\n");
        }
        choixcpu = choix_ordinateur();
        printf("CPU: ");
        if (choixcpu == PIERRE) {
            printf("PIERRE !\n");
        } else if (choixcpu == FEUILLE) {
            printf("FEUILLE !\n");
        } else {
            printf("CISEAUX !\n");
        }
        score(choixcpu, choixjoueur, &scorejoueur, &scorecpu);
        if (scorejoueur > prevjoueur) {
            prevjoueur = scorejoueur;
            printf("Vous remportez ce round !\n");
        } else if (scorecpu > prevcpu) {
            prevcpu = scorecpu;
            printf("Le CPU remporte ce round !\n");
        } else {
            printf("Egalité !!\n");
        }
        round++;
    }
    (scorejoueur == 3) ? printf("Félicitations ! Vous avez gagné !\n")
                       : printf("Vous ferez mieux la prochaine fois :c\n");
}

int main() {

    srand(time(NULL));

    jeu();
    return 0;
}
