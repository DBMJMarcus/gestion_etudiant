#include "struct_etd.h"


int fonction_de_hachage(int matricule,int taille_table);
Etudiant ***init_table_de_hachage_tableau(int nombre_etudiant, int taille);
void maj_nom_tableau(Etudiant ***table_hachage,int nombre_etudiant,int taille_table);
void supp_etudiant_tableau(Etudiant ***table_hachage, int taille_table, int nombre_etudiant);
void afficher_table_de_hachage_tableau(Etudiant ***table_hashage, int nombre_etudiant, int taille_tableau_h);
void rechercher(Etudiant ***table_hachage,int nombre_etudiant,Etudiant *tableau_etudiant,int taille_table_hach);
void ajouter_table_de_hachage_tableau(Etudiant ***table_hashage, Etudiant *simon, int nombre_etudiant, int taille_tableau_h);