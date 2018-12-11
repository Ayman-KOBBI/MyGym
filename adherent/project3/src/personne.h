#include <gtk/gtk.h>

typedef struct
{

char cin[20];
char nom[20];
char prenom[30];
char date_naissance[30];
char adresse[10];


}Personne;

void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
