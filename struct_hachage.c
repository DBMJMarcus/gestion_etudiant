#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_etd.h"
#include "struct_hachage.h"

void ajouter_table_de_hachage_tableau(Etudiant ***table_hashage, Etudiant *simon, int nombre_etudiant, int taille_tableau_h)
{
    int index = fonction_de_hachage(simon->matricule, taille_tableau_h), i = 0;

    // recherche de position libre pour inserer un etudiant
    while (i < nombre_etudiant && table_hashage[index][i] != NULL)
    {
        i++;
    }

    if (table_hashage[index][i] == NULL)
    {
        // insertion de l'etudiant lorsqu'on a trouver la position libre
        table_hashage[index][i] = simon;
    }
}

int fonction_de_hachage(int matricule, int taille_table)
{
    return matricule % taille_table;
}

void rechercher(Etudiant ***table_hachage, int nombre_etudiant, Etudiant *tableau_etudiant, int taille_table_hach)
{
    int nombre_a_rechercher = 20 % nombre_etudiant;
    for (int i = 0; i < nombre_a_rechercher; i++)
    {
        int index = fonction_de_hachage(tableau_etudiant[i].matricule, taille_table_hach);

        for (int j = 0; j < nombre_etudiant; j++)
        {
            if (table_hachage[index][j]->matricule == tableau_etudiant[i].matricule)
            {
                break;
            }
        }
    }
}

Etudiant ***init_table_de_hachage_tableau(int nombre_etudiant, int taille)
{
    Etudiant ***tableau_etudiant = malloc(sizeof(Etudiant **) * taille);

    for (int i = 0; i < taille; i++)
    {
        tableau_etudiant[i] = malloc(sizeof(Etudiant *) * nombre_etudiant);
        for (int j = 0; j < nombre_etudiant; j++)
        {
            tableau_etudiant[i][j] = NULL;
        }
    }
    return tableau_etudiant;
}

void maj_nom_tableau(Etudiant ***table_hachage, int nombre_etudiant, int taille_table)
{
    char *sim;
    for (int k = 0; k < (10 % nombre_etudiant); k++)
    {
        int position = fonction_de_hachage(k, taille_table);

        for (int j = 0; j < nombre_etudiant; j++)
        {

            if (table_hachage[position][j]->matricule == k)
            {
                strcat(table_hachage[position][j]->nom, "MAJ");
                break;
            }
        }
    }
}

void afficher_table_de_hachage_tableau(Etudiant ***table_hashage, int nombre_etudiant, int taille_tableau_h)
{

    printf("Nom \tMoyenne \tMatricule");
    printf("\n\n");
    for (int i = 0; i < taille_tableau_h; i++)
    {
        for (int j = 0; j < nombre_etudiant; j++)
        {
            if (table_hashage[i][j] != NULL)
            {
                printf("%s\t", table_hashage[i][j]->nom);
                printf("%.2f\t", table_hashage[i][j]->moyenne);
                printf("%d\t\t", table_hashage[i][j]->matricule);

                printf("\n");
            }
        }
        printf("__________________________________________________________\n");
    }
}

void supp_etudiant_tableau(Etudiant ***table_hachage, int taille_table, int nombre_etudiant)
{
    for (int i = 0; i < (10 % nombre_etudiant); i++)
    {
        int position = fonction_de_hachage(i, taille_table);
        for (int j = 0; j < nombre_etudiant; j++)
        {
            // on verifie que la case n'est pas null et que le matricule correspond
            if (table_hachage[position][j] != NULL && table_hachage[position][j]->matricule == i)
            {
                table_hachage[position][j] = NULL;
                break;
            }
        }
    }
}