#include <stdio.h>

#define TNORMAL 11.4
#define TMOINS14 4.5
#define TMOINS26S 4.9
#define TMOINS26WE 7.90
#define TMATIN 7.10

float prixPlace(const int age, const int jour, const float heure);

int main() {
    int age = 25;
    int jour = 6;
    float heure = 9.5;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    age = 6;
    jour = 3;
    heure = 16.7;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    age = 24;
    jour = 2;
    heure = 9.3;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    age = 68;
    jour = 6;
    heure = 20.6;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    age = 23;
    jour = 7;
    heure = 18.5;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    age = 14;
    jour = 6;
    heure = 10.5;
    printf(
        "Age: %d | Jour: %d | Heure Séance: %.1f\nPrix + avantageux: %.2f€\n\n",
        age, jour, heure, prixPlace(age, jour, heure));
    return 0;
}

float prixPlace(const int age, const int jour, const float heure) {
    if (age < 14) {
        return TMOINS14;
    } else if (age < 26 && jour <= 5) {
        return TMOINS26S;
    } else if (heure >= 8 && heure <= 11) {
        return TMATIN;
    } else if (age < 26) {
        return TMOINS26WE;
    } else {
        return TNORMAL;
    }
}
