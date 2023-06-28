#ifndef _struct_etd_
#define _struct_etd_

typedef struct Etudiant Etudiant;
struct Etudiant
{
    /* data */
    int matricule;
    char nom[12];
    float moyenne;

};
#endif // _struct_etd_