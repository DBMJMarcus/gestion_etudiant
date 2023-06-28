#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct_etd.h"

float generateRandomFloat(float x, float y) {
    srand(time(NULL));
    float randomValue;
    int intValue;

    // Générer une valeur entière aléatoire dans l'intervalle [x * 100, y * 100]
    intValue = rand() % ((int)(y * 100) - (int)(x * 100) + 1) + (int)(x * 100);

    // Convertir l'entier en float et diviser par 100 pour obtenir le format XX.XX
    randomValue = (float)intValue / 100.0;

    return randomValue;
}
int generateRandomInt(int min, int max) {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    // Génération d'un nombre aléatoire entre min et max
    int nombre = (rand() % (max - min + 1)) + min;

    return nombre;
}

Etudiant *insertion_tableau(Etudiant *tab_etd, int nbre_etd) {
    for (int i = 0; i < nbre_etd; i++) {
        Etudiant new_etd;
        new_etd.matricule = i;
        new_etd.moyenne = generateRandomFloat(0, 20);

        sprintf(new_etd.nom, "Etd%06d", new_etd.matricule);

        tab_etd[i] = new_etd;
    }
    return tab_etd;
}

Etudiant *rechercher_etudiants_tableau(Etudiant *tab_etd, int nbre_etd, int mat) {
    int m = nbre_etd * 0.2; // Calcul de M = 20%N
    int debut = mat - 2 * nbre_etd;
    int fin = mat + 2 * nbre_etd;

    // Vérification des bornes
    if (debut < 0) debut = 0;
    if (fin >= nbre_etd) fin = nbre_etd - 1;

    Etudiant *resultat = malloc(m * sizeof(Etudiant));
    int index_resultat = 0;

    for (int i = debut; i <= fin; i++) {
        if (tab_etd[i].matricule == mat) {
            resultat[index_resultat] = tab_etd[i];
            index_resultat++;

            if (index_resultat >= m) {
                // On a trouvé tous les M étudiants recherchés, on quitte la boucle
                break;
            }
        }
    }

    // Redimensionnement du tableau de résultats
    //resultat = realloc(resultat, index_resultat * sizeof(Etudiant));

    return resultat;
}
