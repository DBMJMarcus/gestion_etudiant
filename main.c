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

    free(etudiants_recherches);
    
    
    Liste liste = nouvelle_liste();//initialisation de la liste chainée

    start = clock();
        //insertion des étudiants dans la liste chainée
        liste = inserer_etudiants(liste, tableau_etudiant, n);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

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
