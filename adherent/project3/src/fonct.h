#include <gtk/gtk.h>
int verif( char login[],char password[]);
typedef struct
{  
char nom[50]; 
char prenom[20];
char tel[50] ; 
int age; 
char sexe[50] ; 
char adress[50] ; 
char mail[50] ;
}kprofil;
void ajouter(char nom[],char prenom[],int age ,char sexe[],char tel[],char adress[], char mail[] );
void ajoute(char login[],char password[], int role,char cin[]);
void afficher(GtkWidget *plistview);
int verifcin(char cin[]);
int verifentry(char a[]);
