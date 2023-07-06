#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct_etd.h"
#include <stdbool.h>

bool recherche_standard(Etudiant* tab_etd, int nbre_etd, int matricule_recherche, int* nbre_etd_recherches) {
    int nbre_etd_recherches_max = nbre_etd * 0.2; // 20% du nombre total d'étudiants

    *nbre_etd_recherches = 0;

    int debut = 0;
    int fin = nbre_etd - 1;
    int milieu;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;

        if (tab_etd[milieu].matricule == matricule_recherche) {
            // Recherché trouvé
            int i = milieu;

            while (i >= 0 && tab_etd[i].matricule == matricule_recherche) {
                (*nbre_etd_recherches)++;
                i--;
            }

            i = milieu + 1;

            while (i < nbre_etd && tab_etd[i].matricule == matricule_recherche) {
                (*nbre_etd_recherches)++;
                i++;
            }

            return true;
        }
        else if (tab_etd[milieu].matricule < matricule_recherche) {
            debut = milieu + 1;
        }
        else {
            fin = milieu - 1;
        }
    }

    return false;
}