#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include "struct_etd.h"
#include "struct_liste.h"
#include "struct_hachage.h"
#include "struct_tableau.h"

int main()
{
    // Initialiser le générateur de nombres aléatoires avec le temps actuel

    clock_t start, end;
    double cpu_time_used;
    int n;
    

    Etudiant *tableau_etudiant;
    printf("Entrez le nombre d'etudiant : ");
    scanf("%d", &n);
    tableau_etudiant = malloc(sizeof(Etudiant) * n);
    insertion_tableau(tableau_etudiant,n);
    Liste liste = nouvelle_liste();//initialisation de la liste chainée

    start = clock();
        //insertion des étudiants dans la liste chainée
        liste = inserer_etudiants(liste, tableau_etudiant, n);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    FILE *file = fopen("temp.txt", "a"); // Ouvre le fichier en mode ajout le fichier doit exister au préalable

    if (file != NULL)
    {
        fprintf(file, "Partie  listes chaînées\n");
        fprintf(file, "Temps d'insertion pour une liste de %d Etudiants est : %f secondes\n", n, cpu_time_used);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    // calcule du temps de recherche dans la liste
    start = clock();

        recherche(liste, n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de recherche de %d Etudiants est : %f secondes\n", (20 % n), cpu_time_used);

     // clacule du temps de mise a jour dans la liste
    start = clock();

        mise_a_jour(liste, n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de mise a jour de %d Etudiants est : %f secondes\n", (10 % n), cpu_time_used);

    // calcule du temps de suppression
    start = clock();

        supprimer_etudiants(liste, n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de suppression de %d Etudiants est : %f secondes\n", (10 % n), cpu_time_used);

    free(liste);//liberation de la memoire

    // partie table de hachage

    Etudiant ***table_hachage = init_table_de_hachage_tableau(n, 20);

    fprintf(file, "Partie table de hachage\n");

    start = clock(); // calcule du temps d'insertion
    //insertion des etudiants
    for (int i = 0; i < n; i++)
    {
        ajouter_table_de_hachage_tableau(table_hachage, &tableau_etudiant[i], n, 20);
    }

    end = clock(); // calcule du temps d'insertion
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // Enregistrement
    fprintf(file, "Temps d'insertion  de %d Etudiants est : %f secondes\n", n, cpu_time_used);

    //calcule du temps de recherche
    start = clock();

        rechercher(table_hachage, n, tableau_etudiant, 20);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de recherche de %d Etudiants est : %f secondes\n", (20 % n), cpu_time_used);

    // clacule du temps de mise a jour
    start = clock();

        maj_nom_tableau(table_hachage, n, 20);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de mise a jour de %d Etudiants est : %f secondes\n", (10 % n), cpu_time_used);

        // calcule du temps de suppression
    start = clock();

        supp_etudiant_tableau(table_hachage,20,n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // enregistrement du temps dans le fichier
    fprintf(file, "Temps de suppression de %d Etudiants est : %f secondes\n", (10 % n), cpu_time_used);

    free(table_hachage);
    free(tableau_etudiant);
    fclose(file);
    return 0;
}
