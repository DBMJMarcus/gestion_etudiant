#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "struct_etd.h"
#include "tri.h"

void tri_bulle(Etudiant *tab, int taille) {
    int i, j;
    Etudiant temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tab[j].moyenne > tab[j + 1].moyenne) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void tri_insertion(Etudiant *tab, int taille) {
    int i, j;
    Etudiant temp;
    for (i = 1; i < taille; i++) {
        temp = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j].moyenne > temp.moyenne) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }
}

void tri_selection(Etudiant *tab, int taille) {
    int i, j, min;
    Etudiant temp;
    for (i = 0; i < taille - 1; i++) {
        min = i;
        for (j = i + 1; j < taille; j++) {
            if (tab[j].moyenne < tab[min].moyenne) {
                min = j;
            }
        }
        if (min != i) {
            temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }
    }
}

void tri_fusion(Etudiant *tab, int debut, int fin) {
    if (debut < fin) {
        int milieu = (debut + fin) / 2;
        tri_fusion(tab, debut, milieu);
        tri_fusion(tab, milieu + 1, fin);
        fusion(tab, debut, milieu, fin);
    }
}

void fusion(Etudiant *tab, int debut, int milieu, int fin) {
    Etudiant *tabFusion = malloc((fin - debut + 1) * sizeof(Etudiant));
    int i = debut;
    int j = milieu + 1;
    int k = 0;
    while (i <= milieu && j <= fin) {
        if (tab[i].moyenne < tab[j].moyenne) {
            tabFusion[k] = tab[i];
            i++;
        } else {
            tabFusion[k] = tab[j];
            j++;
        }
        k++;
    }
    while (i <= milieu) {
        tabFusion[k] = tab[i];
        i++;
        k++;
    }
    while (j <= fin) {
        tabFusion[k] = tab[j];
        j++;
        k++;
    }
    for (k = 0; k < fin - debut + 1; k++) {
        tab[debut + k] = tabFusion[k];
    }
    free(tabFusion);
}