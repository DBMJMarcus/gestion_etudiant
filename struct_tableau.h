#include "struct_etd.h"
#ifndef _structableau_
#define _structableau_

Etudiant *insertion_tableau(Etudiant *tab_etd, int nbre_etd);
float generateRandomFloat(float x, float y);
Etudiant* rechercher_etudiants(Etudiant* tab_etd, int nbre_etd, int matricule_recherche, int* nbre_etd_recherches);

void mettre_a_jour_etudiants(Etudiant* tab_etd, int nbre_etd, int matricule_debut);



#endif // _structableau_

