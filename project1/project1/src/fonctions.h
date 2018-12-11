#ifndef fonction_H_INCLUDED	
#define fonction_H_INCLUDED
#include"fonctions.h"

typedef struct
{
char jour[50];
char  mois[50];
char  annee[50];
char horaire[50];
}disponibilite;

typedef struct
{

char nom[20];
char prenom[20];
char cin[30];
char jour[50];
char mois[30];
char annee[30];
char sexe[30];
char taille[50];
char poids[50];
char imc[50];
char clas[100];
char regime[100];
}personne;

void ajouter_y(personne p);

//void afficher(GtkWidget *liste);
int verifier(char name[50], char login[50]) ;

void ajouter_d(disponibilite d);
 enum   
{       
        NOM,
	PRENOM,
        CIN,
        JOUR,
        MOIS,
        ANNEE,
        SEXE,
        TAILLE,
        POIDS,
        IMC,
        CLAS,
        REGIME ,
        COLUMNS
};




void afficher_y(GtkWidget *liste);
void modifier_y(personne p , personne m );

#endif
