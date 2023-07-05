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
        fprintf(file, "Temps d'exécution pour l'insertion de %d Etudiant : %f secondes\n", n,cpu_time_used);
        fclose(file); // Ferme le fichier
        printf("Le temps d'exécution a été enregistré dans le fichier 'temp.txt'.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    int N = n;
    int matricule_recherche = rand() % (4 * N + 1) - (2 * N); // Matricule aléatoire dans [-2N; 2N]

    printf("Matricule recherché : %d\n", matricule_recherche);

    int nbre_etd_recherches;
   

    start = clock(); // Enregistre le temps de début

    // Votre instruction à mesurer ici
     Etudiant* etudiants_recherches = rechercher_etudiants(tableau_etudiant, n, matricule_recherche, &nbre_etd_recherches);


    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    file = fopen("temp.txt", "a"); // Ouvre le fichier en mode ajout le fichier doit exister au préalable
    
    if (file != NULL) {
        fprintf(file, "Temps d'exécution de la recherche pour %d Etudiant : %f secondes\n", n,cpu_time_used);
        fclose(file); // Ferme le fichier
        printf("Le temps d'exécution de la recherche a été enregistré dans le fichier 'temp.txt'.\n");
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

     printf("Nombre d'étudiants trouvés : %d\n", nbre_etd_recherches);
    for (int i = 0; i < nbre_etd_recherches; i++) {
        printf("Étudiant %d - Matricule: %s, Moyenne: %.2f\n", i+1, etudiants_recherches[i].nom, etudiants_recherches[i].moyenne);
    }

     int N = n;
    int matricule_debut = rand() % N; // Matricule aléatoire dans [0, N[

    printf("Matricule de début : %d\n", matricule_debut);

    start = clock(); // Enregistre le temps de début
    
    mettre_a_jour_etudiants(tableau_etudiant, n, matricule_debut);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    if (file != NULL) {
        fprintf(file, "Temps d'exécution de la mise à jour de %d Etudiant : %f secondes\n", n,cpu_time_used);
        fclose(file); // Ferme le fichier
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    free(etudiants_recherches);
    free(tableau_etudiant);

    return 0;
}

