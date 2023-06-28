#ifndef __Liste__
#define __Liste__

// #include<stdbool.h>
typedef enum
{
    false,
    true
} Bool;

typedef struct ListeEtudiant
{
    Etudiant etudiant;
    struct ListeEtudiant *next;
} ListeEtudiant, *Liste;

Liste nouvelle_liste(void);
Bool liste_vide(Liste list);
void afficher_liste(Liste list);
void recherche(Liste liste,int nombre_etudiant);
void mise_a_jour(Liste liste, int nombre_etudiant);
void supprimer_etudiants(Liste liste,int nombre_etudiant);
Liste inserer_etudiant(Liste list, Etudiant nouvel_etudiant);
Liste inserer_etudiants(Liste liste,Etudiant *tableau_etudiant,int nombre_etudiant);

#endif