#include <string.h>
#include "fonct.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
int verif( char login[],char password[])
{	
	char loginn[30];
	char modp[30];
	int role=0;
	int re=0;

	FILE* f;

	f=fopen("/home/noura/Projects/project7/src/users.txt","r");

while(fscanf(f,"%s %s %d ",loginn,modp,&role)!=EOF)    
{
	if  ((strcmp(loginn,login)==0) && (strcmp(password,modp)==0))
	{
		
		re=role;
	}
	
}

fclose(f);
return(re);
}
void ajouter(char nom[],char prenom[],int age,char sexe[],char tel[],char adress[], char mail[] )
{FILE*f;

f=fopen("/home/noura/Projects/project7/src/profil.txt","w");

fprintf(f,"%s %s %d %s %s %s %s",nom,prenom,age,sexe,tel,adress,mail);
fclose(f);
}
void ajoute(char login[],char password[], int role,char cin[])
{
FILE*f;
f=fopen("/home/noura/Projects/project7/src/users.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %s\n",login,password,role,cin);

fclose(f);}
}
void afficher(GtkWidget *plistview)
{ 
enum { 
       COL_LOGIN,
       COL_PASSWORD,
       COL_ROLE,
       COL_CIN,
       NUM_COLS
      };
char login[20],password [20];
char role[20],cin[50];

GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f1;
f1=fopen("/home/noura/Projects/project7/src/users.txt","r");
if(f1!=NULL){
       while(fscanf(f1,"%s %s %s %s",login,password,role,cin)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_LOGIN, login,
		          COL_PASSWORD, password,
		          COL_ROLE, role,
			  COL_CIN, cin,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("login",celrender,"text",COL_LOGIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("password",celrender,"text",COL_PASSWORD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("role",celrender,"text",COL_ROLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("cin",celrender,"text",COL_CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f1);
}
///////////////////controle de saisie/////////////////////
int verifcin(char cin[])
{
	for(int i=0;i<strlen(cin);i++)
	{
		if ( (strlen(cin)==0) || (cin[i] < '0') || (cin[i] > '9') || (strlen(cin)!=8) )
		{return 0;
		}
		else
		 return 1;
	}
}
int verifentry(char a[])
{
 if (strlen(a)==0)
{return 0;}
else return 1;

}

