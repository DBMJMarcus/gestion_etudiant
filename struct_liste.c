#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_etd.h"
#include "struct_liste.h"

// creation de la liste
Liste nouvelle_liste(void)
{
    return NULL;
}

// ajout en début de liste
Liste inserer_etudiant(Liste list, Etudiant nouvel_etudiant)
{

    ListeEtudiant *element;
    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        fprintf(stderr, "l'allocation dynamique a echouer");
    }

    if (liste_vide(list))
    {
        element->etudiant = nouvel_etudiant;
        element->next = NULL;
    }
    else
    {
        element->etudiant = nouvel_etudiant;
        element->next = list;
    }

    return element;
}

Bool liste_vide(Liste list) // verifier si la liste est vide
{
    if (list == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void afficher_liste(Liste list) // afficher liste
{

    while (list != NULL)
    {
        printf("%s \n", list->etudiant.nom);
        list = list->next;
    }
}

Liste inserer_etudiants(Liste liste, Etudiant *tableau_etudiant, int nombre_etudiant)
{
    // insertion de chaque etudiant du tableau dans la liste
    for (int i = 0; i < nombre_etudiant; i++)
    {
        liste = inserer_etudiant(liste, tableau_etudiant[i]);
    }
    return liste;
}

void recherche(Liste liste, int nombre_etudiant)
{
    int nombre_a_rechercher = 20 % nombre_etudiant;
    for (int i = (-2 * nombre_a_rechercher); i < 2 * (nombre_a_rechercher); i++)
    {
        Liste temp = liste;
        while (temp != NULL)
        {
            if (temp->etudiant.matricule == i)
            {
                break;
            }
            temp = temp->next;
        }
    }
}

void mise_a_jour(Liste liste, int nombre_etudiant)
{

    int nombre_a_rechercher = 10 % nombre_etudiant;

    for (int i = 0; i < nombre_a_rechercher; i++)
    {
        Liste temp = liste;
        while (temp != NULL)
        {
            if (temp->etudiant.matricule == i)
            {
                strcat(temp->etudiant.nom, "MAJ");
                break;
            }
            temp = temp->next;
        }
    }
}

void supprimer_etudiants(Liste liste, int nombre_etudiant)
{
    int nombre_a_rechercher = 10 % nombre_etudiant;
    for (int i = 0; i < nombre_a_rechercher; i++)
    {
        Liste temp = liste;
        while (temp != NULL)
        {
            if (temp->etudiant.matricule == (nombre_a_rechercher))
            {
                free(temp->next);
                temp->next = NULL;
                // temp = NULL;
                break;
            }
            temp = temp->next;
        }
    }
}