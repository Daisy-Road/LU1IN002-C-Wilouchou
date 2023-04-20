/* Nous nous interessons a des listes de dates, chaque date est caracterisee par une jour, un mois et une annee, chacune des ces informations etant representee par un entier*/

typedef struct _date date;

typedef struct _date {
  int jour;
  int mois;
  int annee;
  date *suivant;
} date;

/* Ajoute la date dont les caracteristiques sont passsee en parametre en tete de liste (j pour le jour, m pour le mois et a pour l'annee)
Retourne la nouvelle tete de liste */
date* ajouterDateTete(int j, int m, int a, date* listeDates);

/* Affiche les caracteristiques de la date passee en parametre */
void afficherDate(date * la_date);

/* Affiche les caracteristiques de toutes les dates de la liste */
void afficherListe(date* listeDates);

/* Retourne le nombre de dates de la liste correspondant au jour et au mois passes en parametre */
int frequence(int jour, int mois, date * listeDates);

/* Supprime de la liste listeDates toutes les dates d'une annee anterieure a celle passee en parametre 
La fonction doit liberer la memoire.  
Retourne la tete de liste */
date * supprimerDates(int annee, date * listeDates);

/* Retourne 1 si les caracteristiques passees en parametre correspondent a une date de la liste
  0 sinon */
int rechercheDate(int jour, int mois, int annee, date * listeDates);

/* Cree une nouvelle liste et retourne la tete de cette liste.
Cette liste doit contenir toutes les dates de listeDates correspondant a l'annee passee en parametre. La nouvelle liste ne doit pas 
contenir de doublon. Si aucune date ne correspond a l'annee passee en parametre, le fonction retourne NULL */
date * datesAnnee(int anne, date * listeDates);
