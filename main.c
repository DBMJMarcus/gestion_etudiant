#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include "tri.h"
#include "struct_tableau.h"

int main()
{
    // Initialiser le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));
    int n;
    FILE *file = fopen("temp.txt", "a");
    Etudiant *tableau_etudiant;
    
    int tab_valeur[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};

    for (int i = 0; i < 7; i++)
    {
        /* code */

    int nombre_etudiant = tab_valeur[];
    FILE *file = fopen("temp.txt", "a"); // Ouvre le fichier en mode ajout le fichier doit exister au préalable

    clock_t start, end;
    double cpu_time_used;

    tableau_etudiant = malloc(sizeof(Etudiant) * nombre_etudiant);
    insertion_tableau(tableau_etudiant, nombre_etudiant);

    fprintf(file, "N = %d \n", nombre_etudiant);
    fprintf(file, "Partie tri bulle\n");

    start = clock(); // Enregistre le temps de début

    tri_bulle(tableau_etudiant, nombre_etudiant);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(file, "Temps de tri de %d Etudiant : %f secondes\n", nombre_etudiant, cpu_time_used);

    fprintf(file, "Partie tri insertion\n");
    start = clock(); // Enregistre le temps de début

    tri_insertion(tableau_etudiant, nombre_etudiant);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(file, "Temps de tri de %d Etudiant : %f secondes\n", nombre_etudiant, cpu_time_used);

    fprintf(file, "Partie tri selection\n");
    start = clock(); // Enregistre le temps de début

    tri_selection(tableau_etudiant, nombre_etudiant);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(file, "Temps de tri de %d Etudiant : %f secondes\n", nombre_etudiant, cpu_time_used);

    fprintf(file, "Partie tri fusion\n");
    start = clock(); // Enregistre le temps de début

    tri_fusion(tableau_etudiant, 0, nombre_etudiant - 1);

    end = clock(); // Enregistre le temps de fin

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(file, "Temps de tri de %d Etudiant : %f secondes\n", nombre_etudiant, cpu_time_used);
    free(tableau_etudiant);
    fclose(file);
    }
    
    
    
    return 0;
}
