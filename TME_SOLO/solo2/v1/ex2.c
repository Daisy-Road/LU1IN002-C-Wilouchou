#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

/* Ajoute un nouvel adherent (d'identifiant id) en tete de la liste
listeAdherents, le solde et le nombre de vente associes sont initialises a 0
Retourne la nouvelle tete de liste */

adherent* ajouterAdherentTete(int id, adherent* listeAdherents) {
    adherent* new = malloc(sizeof(adherent));
    new->identifiant = id;
    new->solde = 0;
    new->nbVentes = 0;
    new->suivant = listeAdherents;
    return new;
}

/* affiche les caracteristiques d'un adherent */
/* NE PAS MODIFIER LA FONCTION */
void afficherAdherent(adherent* adh) {
    printf("Adherent : %d, solde : %.2f, ventes : %d\n", adh->identifiant,
           adh->solde, adh->nbVentes);
}

/* Affiche les caracteristiques de tous les adherents de la liste
 * listeAdherents*/
void afficherListe(adherent* listeAdherents) {
    while (listeAdherents) {
        afficherAdherent(listeAdherents);
        listeAdherents = listeAdherents->suivant;
    }
}

/* Effectue la vente entre deux adherents, met a jour le solde du vendeur (+
 * somme) et celui de l'acheteur (-somme) et le nombre de ventes du vendeur */
/* Hypothese : le vendeur et l'acheteur sont dans la liste */
void vente(int vendeur, int acheteur, float somme, adherent* listeAdherents) {
    adherent* ptrV = NULL;
    adherent* ptrA = NULL;
    while (!ptrV && !ptrA && listeAdherents) {
        if (listeAdherents->identifiant == vendeur) ptrV = listeAdherents;
        if (listeAdherents->identifiant == acheteur) ptrA = listeAdherents;
        listeAdherents = listeAdherents->suivant;
    }
    ptrV->solde -= somme;
    ptrA->solde += somme;
    ptrA->nbVentes++;
}

/* Retourne le nombre moyen de ventes par vendeur (nombre de ventes / nombre de
 * vendeurs). Un adherent est considere comme vendeur des qu'il a effectue une
 * vente. Retourne 0.0 si aucun adherent n'a effectue de vente */
float nbMoyenVente(adherent* listeAdherents) {
    int sum = 0;
    int vendors = 0;
    while (listeAdherents) {
        if (listeAdherents->nbVentes) {
            vendors++;
            sum += listeAdherents->nbVentes;
        }
        listeAdherents = listeAdherents->suivant;
    }
    return (vendors) ? (float)sum / vendors : 0.0;
}

/* Fusionne les deux adherents passes en parametre, le premier adherent passe en
parametre recupere le solde et le nombre de ventes du second, le second est
supprime de la liste. Retourne la tete de liste. La fonction doit liberer la
memoire */
/* Hypothese : les deux adherents sont dans la liste */
adherent* fusionAdherents(int adh1, int adh2, adherent* listeAdherents) {
    adherent* tmp = listeAdherents;
    adherent* ptr1 = NULL;
    adherent* prev = NULL; // Store the previous pointer of ptr2
    adherent* ptr2 = NULL;
    while (!ptr1 && !ptr2) {
        if (tmp->identifiant == adh1) ptr1 = tmp;
        if (tmp->identifiant == adh2) ptr2 = tmp;
        if (!ptr2) prev = tmp;
        tmp = tmp->suivant;
    }
    ptr1->solde += ptr2->solde;
    ptr1->nbVentes += ptr2->nbVentes;
    if (prev) {
        prev->suivant = ptr2->suivant;
        free(ptr2);
        return listeAdherents;
    }
    tmp = ptr2->suivant;
    free(ptr2);
    return tmp; // Changement de tête
}

/* Cree la liste des adherents non vendeurs (pas de vente), retourne la tete de
la liste creee. Dans la noyfvelle liste, le solde de chaque adherent est le meme
que dans la liste initiale. Ne modifie pas la liste passee en parametre */
adherent* listeNonVendeurs(adherent* listeAdherents) {
    adherent* res = NULL;
    while (listeAdherents) {
        if (!listeAdherents->nbVentes) {
            adherent* new = malloc(sizeof(adherent));
            new->identifiant = listeAdherents->identifiant;
            new->solde = listeAdherents->solde;
            new->nbVentes = 0;
            new->suivant = res;
            res = new;
        }
        listeAdherents = listeAdherents->suivant;
    }
    return res;
}
