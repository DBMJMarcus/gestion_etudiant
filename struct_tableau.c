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

Etudiant* rechercher_etudiants(Etudiant* tab_etd, int nbre_etd, int matricule_recherche, int* nbre_etd_recherches) {
    int nbre_etd_recherches_max = nbre_etd * 0.2; // 20% du nombre total d'étudiants
    Etudiant* etudiants_recherches = malloc(nbre_etd_recherches_max * sizeof(Etudiant));
    *nbre_etd_recherches = 0;

    for (int i = 0; i < nbre_etd; i++) {
        if (tab_etd[i].matricule == matricule_recherche) {
            etudiants_recherches[*nbre_etd_recherches] = tab_etd[i];
            (*nbre_etd_recherches)++;

            if (*nbre_etd_recherches == nbre_etd_recherches_max) {
                break; // On a trouvé le nombre maximal d'étudiants recherchés, on arrête la recherche
            }
        }
    }

    return etudiants_recherches;
}


void mettre_a_jour_etudiants(Etudiant* tab_etd, int nbre_etd, int matricule_debut) {
    int nbre_etd_maj = nbre_etd * 0.1; // 10% du nombre total d'étudiants

    for (int i = 0; i < nbre_etd; i++) {
        if (tab_etd[i].matricule >= matricule_debut && tab_etd[i].matricule < (matricule_debut + nbre_etd_maj)) {
            strcat(tab_etd[i].nom, "MAJ");
        }
    }
}
