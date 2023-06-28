#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct_tableau.h"
#include <time.h>



int main() {
    // Initialiser le générateur de nombres aléatoires avec le temps actuel
    
    int n;

    Etudiant *tableau_etudiant;
    printf("Entrez le nombre d'étudiant : ");
    scanf("%d",&n);
    tableau_etudiant = malloc(sizeof(Etudiant)*n);
    
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Enregistre le temps de début

    // Votre instruction à mesurer ici
    // Exemple : ici je met ma fonction
    insertion_tableau(tableau_etudiant,n);


    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    FILE *file = fopen("temp.txt", "a"); // Ouvre le fichier en mode ajout le fichier doit exister au préalable
    
    if (file != NULL) {
        fprintf(file, "Temps d'exécution pour %d Etudiant : %f secondes\n", n,cpu_time_used);
        fclose(file); // Ferme le fichier
        printf("Le temps d'exécution a été enregistré dans le fichier 'temp.txt'.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    int matricule_recherche = 50;
    Etudiant *resultats = rechercher_etudiants_tableau(tableau_etudiant, n, matricule_recherche);


    int nbre_resultats = sizeof(resultats) / sizeof(Etudiant);
    printf("Résultats de recherche pour le matricule %d :\n", matricule_recherche);
    for (int i = 0; i < nbre_resultats; i++) {
        printf("Étudiant %d - Matricule: %s, Moyenne: %.2f\n", i + 1, resultats[i].nom, resultats[i].moyenne);
    }

    


    

    return 0;
}

