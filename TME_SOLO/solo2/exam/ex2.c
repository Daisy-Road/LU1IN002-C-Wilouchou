#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

/* Ajoute la date dont les caracteristiques sont passsee en parametre en tete de
liste (j pour le jour, m pour le mois et a pour l'annee) Retourne la nouvelle
tete de liste */
date* ajouterDateTete(int j, int m, int a, date* listeDates) {
    date* new_el = malloc(sizeof(date));
    new_el->jour = j;
    new_el->mois = m;
    new_el->annee = a;
    new_el->suivant = listeDates;
    return new_el;
}
/* Affiche les caracteristiques de la date passee en parametre */
/* NE PAS MODIFIER LA FONCTION */
void afficherDate(date* la_date) {
    printf("%d ", la_date->jour);

    switch (la_date->mois) {
    case 1:
        printf("janvier ");
        break;
    case 2:
        printf("fevrier ");
        break;
    case 3:
        printf("mars ");
        break;
    case 4:
        printf("avril ");
        break;
    case 5:
        printf("mai ");
        break;
    case 6:
        printf("juin ");
        break;
    case 7:
        printf("juillet ");
        break;
    case 8:
        printf("aout ");
        break;
    case 9:
        printf("septembre ");
        break;
    case 10:
        printf("octobre ");
        break;
    case 11:
        printf("novembre ");
        break;
    case 12:
        printf("decembre ");
        break;
    }

    printf("%d\n", la_date->annee);
}

/* Affiche les caracteristiques de toutes les dates de la liste */
void afficherListe(date* listeDates) {
    while (listeDates) {
        afficherDate(listeDates);
        listeDates = listeDates->suivant;
    }
}

/* Retourne le nombre de dates de la liste correspondant au jour et au mois
 * passes en parametre */
int frequence(int jour, int mois, date* listeDates) {
    int res = 0;
    while (listeDates) {
        if (listeDates->jour == jour && listeDates->mois == mois) res++;
        listeDates = listeDates->suivant;
    }
    return res;
}

/* Supprime de la liste listeDates toutes les dates d'une annee anterieure a
celle passee en parametre La fonction doit liberer la memoire. Retourne la tete
de liste */
date* supprimerDates(int annee, date* listeDates) {
    date* prec = NULL;
    date* res = listeDates;
    while (listeDates) {
        if (listeDates->annee < annee) {
            if (prec) {
                // Réassignemment de l'élément précédent au suivant
                prec->suivant = listeDates->suivant;
                free(listeDates);
                listeDates = prec->suivant; // On poursuit le parcours...
            } else {
                // Il n'y a pas d'éléments précédents...
                // La tête de liste est modifiée
                res = listeDates->suivant;
                free(listeDates);
                listeDates = res; // On poursuit le parcours
            }
        } else {
            // Marche normale
            prec = listeDates;
            listeDates = listeDates->suivant;
        }
    }
    return res;
}

/* Retourne 1 si les caracteristiques passees en parametre correspondent a une
  date de la liste 0 sinon */
int rechercheDate(int jour, int mois, int annee, date* listeDates) {
    while (listeDates) {
        if (listeDates->jour == jour && listeDates->mois == mois &&
            listeDates->annee == annee)
            return 1;
        listeDates = listeDates->suivant;
    }
    return 0;
}

/* Cree une nouvelle liste et retourne la tete de cette liste.
Cette liste doit contenir toutes les dates de listeDates correspondant a l'annee
passee en parametre. La nouvelle liste ne doit pas contenir de doublon. Si
aucune date ne correspond a l'annee passee en parametre, le fonction retourne
NULL */
date* datesAnnee(int annee, date* listeDates) {
    date* res = NULL;
    while (listeDates) {
        if (listeDates->annee == annee &&
            !rechercheDate(listeDates->jour, listeDates->mois,
                           listeDates->annee, res)) {
            res = ajouterDateTete(listeDates->jour, listeDates->mois,
                                  listeDates->annee, res);
        }
        listeDates = listeDates->suivant;
    }
    return res;
}
