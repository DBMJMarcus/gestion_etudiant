#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include "struct_etd.h"
#include "struct_liste.h"
#include "struct_hachage.h"
#include "struct_tableau.h"
#include "tri.h"
#include "recherche.h"

int main() {
    // Initialiser le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));
    int n;
    FILE *file = fopen("temp.txt", "a");
    Etudiant *tableau_etudiant;
    
    int tab_valeur[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    file = fopen("temp.txt", "a");
    fprintf(file, "\nRECHERCHE STANDART  \n");

    for (int i = 0; i < 7; i++)
    {
        /* code */
        
        n = tab_valeur [i];
        

        tableau_etudiant = malloc(sizeof(Etudiant)*n);
    
    clock_t start, end;
    double cpu_time_used;

// deja existant por les tableaux

    start = clock(); // Enregistre le temps de début

    // Votre instruction à mesurer ici
    // Exemple : ici je met ma fonction
    insertion_tableau(tableau_etudiant,n);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//////////////////////////////////////////////////////////////  
    
    int N = n;
    int matricule_recherche = rand() % (4 * N + 1) - (2 * N);

    int nbre_etd_recherches;
    start = clock(); // Enregistre le temps de début

    bool trouve = recherche_standard(tableau_etudiant, N, matricule_recherche, &nbre_etd_recherches);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(file, "Temps de Recherche pour N = %d Etudiant : %f secondes\n", n, cpu_time_used);

        // if (trouve) {
        //     printf("Nombre d'étudiants trouvés : %d\n", nbre_etd_recherches);
        // } else {
        //     printf("Aucun étudiant trouvé.\n");
        // }


    free(tableau_etudiant);
    
    }
 
fclose(file);
    return 0;
}

