#include "ex2.h"
#include <stdio.h>

#define SEP printf("----\n\n")
#define MTEST 2
#define JTEST 2
#define ANNEE 2004

/* programme de test */
int main() {

    int bool;
    int jour;
    int mois;
    int annee;

    date* list = NULL;
    printf("-----[TEST]-----\n");
    printf("Choisir la liste préfaite ou en générer une nouvelle ?\n1 - Liste "
           "préfaite \n0 - Nouvelle génération\n");
    scanf("%d", &bool);
    if (bool) {
        list = ajouterDateTete(15, 04, 2004, list);
        list = ajouterDateTete(12, 04, 2004, list);
        list = ajouterDateTete(23, 05, 2014, list);
        list = ajouterDateTete(20, 04, 2023, list);
        list = ajouterDateTete(02, 02, 2002, list);
        list = ajouterDateTete(23, 05, 2048, list);
        list = ajouterDateTete(02, 02, 2021, list);
        list = ajouterDateTete(03, 02, 2002, list);
        list = ajouterDateTete(15, 04, 2004, list);
        list = ajouterDateTete(02, 02, 2002, list);
    } else {
        int size;
        printf("Combien de dates souhaitez vous rensigner dans la liste ? ");
        scanf("%d", &size);
        for (int i = 0; i < size; i++) {
            printf("Jour: ");
            scanf("%d", &jour);
            printf("Mois: ");
            scanf("%d", &mois);
            printf("Annee: ");
            scanf("%d", &annee);
            list = ajouterDateTete(jour, mois, annee, list);
        }
    }
    afficherListe(list);
    if (!list)
        printf("L'affichage de la liste a été fait mais elle est vide...\n");
    SEP;
    // Nombre d'occurrence d'une date choisi
    printf("Pour quelles dates souhaitez-vous mesurer la fréquence ?\n");
    printf("Jour: ");
    scanf("%d", &jour);
    printf("Mois: ");
    scanf("%d", &mois);
    printf("Il y a %d apparitions dans la liste du %d/%d\n",
           frequence(jour, mois, list), jour, mois);
    SEP;
    printf(
        "Pour quelles dates souhaitez-vous supprimer les éléments antérieurs "
        "?\n");
    printf("Annee: ");
    scanf("%d", &annee);
    list = supprimerDates(annee, list);
    afficherListe(list);
    if (!list)
        printf("L'affichage de la liste a été fait mais elle est vide...\n");
    SEP;
    printf("Indiquez une date à rechercher...\n");
    printf("Jour: ");
    scanf("%d", &jour);
    printf("Mois: ");
    scanf("%d", &mois);
    printf("Annee: ");
    scanf("%d", &annee);
    rechercheDate(jour, mois, annee, list)
        ? printf("Oui, cette date est dans la liste !\n")
        : printf("Non cette date n'est pas dans la liste...\n");
    SEP;
    printf("Indiquez une année pour laquelle une nouvelle liste sera créée\n");
    printf("Annee: ");
    scanf("%d", &annee);
    date* new_l = datesAnnee(annee, list);
    afficherListe(new_l);
    if (!new_l)
        printf("L'affichage de la liste a été fait mais elle est vide...\n");
    return 0;
}
