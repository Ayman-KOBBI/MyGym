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
//////////////////////////////////////////////////////////////////////
void ajoute(char login[],char password[], int role,char cin[])
{
FILE*f;
f=fopen("/home/noura/Projects/project7/src/users.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %s\n",login,password,role,cin);

fclose(f);}
}
void modifier3(char login[],char password[],char role[],char id[])
{ 	
	char logink[20],passwordk[20],rolek[20],idk[20];

	FILE *f , *tmp;
	f=fopen("/home/noura/Projects/project7/src/users.txt","r");
	tmp=fopen("/home/noura/Projects/project7/src/users.tmp","a+");
	while(fscanf(f,"%s %s %s %s\n",logink,passwordk,rolek,idk)!=EOF){
if(!strcmp(login,logink) && !strcmp(role,rolek) && !strcmp(id,idk)){fprintf(tmp,"%s %s %s %s\n",login,password,role,id);}
else fprintf(tmp,"%s %s %s %s\n",logink,passwordk,rolek,idk);
}
fclose(f);
fclose(tmp);
rename("/home/noura/Projects/project7/src/users.tmp","/home/noura/Projects/project7/src/users.txt");
}
void supprimer3(char login[],char password[],char role[],char id[])
{ 	
	char logink[20],passwordk[20],rolek[20],idk[20],nomk[20],prenomk[20],agek[20],sexek[20],adressk[20],telk[20],emailk[20];

  FILE *f1;
  FILE *tmp1;
	
FILE *f , *tmp;
	f=fopen("/home/noura/Projects/project7/src/users.txt","r");
	tmp=fopen("/home/noura/Projects/project7/src/users.tmp","a+");
	while(fscanf(f,"%s %s %s %s\n",logink,passwordk,rolek,idk)!=EOF){
		if( !strcmp(login,logink) && !strcmp(role,rolek) && !strcmp(id,idk) ){continue;}
else fprintf(tmp,"%s %s %s %s\n",logink,passwordk,rolek,idk);
}
fclose(f);
fclose(tmp);
rename("/home/noura/Projects/project7/src/users.tmp","/home/noura/Projects/project7/src/users.txt");

        f1=fopen("/home/noura/Projects/project7/src/profiles.txt","a+");
	tmp1=fopen("/home/noura/Projects/project7/src/profiles.tmp","w");
 while(fscanf(f1,"%s %s %s %s %s %s %s %s %s\n",nomk,prenomk,agek,sexek,adressk,telk,emailk,rolek,idk)!=EOF){
		if( !strcmp(id,idk) && !strcmp(role,rolek) ){continue;}
else fprintf(tmp1,"%s %s %s %s %s %s %s %s %s\n",nomk,prenomk,agek,sexek,adressk,telk,emailk,rolek,idk);
}
fclose(f1);
fclose(tmp1);
rename("/home/noura/Projects/project7/src/profiles.tmp","/home/noura/Projects/project7/src/profiles.txt");
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
///////////////////controle de saisie//////////////////////////////////////////////////////////////////////////////
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
///////////////// Event///////////////////////////
void ajouter1(char id[],char nom[], int jour,int mois,int annee,char frais[])
{
FILE*f;
f=fopen("/home/noura/Projects/project7/src/event.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %d %d %s\n",id,nom,jour,mois,annee,frais);

fclose(f);}
}
void afficher1(GtkWidget *plistview)
{ 
enum { 
       COL_ID,
       COL_NOM,
       COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       COL_FRAIS,
       NUM_COLS
      };
char id[20],nom[20],frais[20];
int jour,mois,annee;

GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
FILE *f1;
f1=fopen("/home/noura/Projects/project7/src/event.txt","r");
if(f1!=NULL){
       while(fscanf(f1,"%s %s %d %d %d %s\n",id,nom,&jour,&mois,&annee,frais)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_ID, id,
		          COL_NOM, nom,
		          COL_JOUR, jour,
			  COL_MOIS, mois,
 			COL_ANNEE, annee,
			COL_FRAIS, frais,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("identifiant",celrender,"text",COL_ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
        
       celrender = gtk_cell_renderer_text_new(); 
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);  
       
       celrender = gtk_cell_renderer_text_new(); 
	col = gtk_tree_view_column_new_with_attributes("frais d inscription",celrender,"text",COL_FRAIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

   
      gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f1);
} 
///////////////
void modifier1(char id[],char nom[],int jour,int mois,int annee,char frais[])
{ 	
	char idn[20],nomn[20],fraisn[20];
int journ,moisn,anneen;
	FILE *f , *tmp;
	f=fopen("/home/noura/Projects/project7/src/event.txt","r");
	tmp=fopen("/home/noura/Projects/project7/src/event.tmp","a+");
	while(fscanf(f,"%s %s %d %d %d %s\n",idn,nomn,&journ,&moisn,&anneen,fraisn)!=EOF){
		if(!strcmp(id,idn) ){fprintf(tmp,"%s %s %d %d %d %s\n",id,nom,jour,mois,annee,frais);}
else fprintf(tmp,"%s %s %d %d %d %s\n",idn,nomn,journ,moisn,anneen,fraisn);
}
fclose(f);
fclose(tmp);
rename("/home/noura/Projects/project7/src/event.tmp","/home/noura/Projects/project7/src/event.txt");
}                  

///////
void supprimer1(char id[],char nom[],int jour,int mois,int annee,char frais[])
{ 	
	char idn[20],nomn[20],fraisn[20];
int journ,moisn,anneen;
	FILE *f , *tmp;
	f=fopen("/home/noura/Projects/project7/src/event.txt","r");
	tmp=fopen("/home/noura/Projects/project7/src/event.tmp","a+");
	while(fscanf(f,"%s %s %d %d %d %s\n",idn,nomn,&journ,&moisn,&anneen,fraisn)!=EOF){
		if(!strcmp(id,idn) ){continue;}
else fprintf(tmp,"%s %s %d %d %d%s\n",idn,nomn,journ,moisn,anneen,fraisn);
}
fclose(f);
fclose(tmp);
rename("/home/noura/Projects/project7/src/event.tmp","/home/noura/Projects/project7/src/event.txt");
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////                 
void afficher2(GtkWidget *pListView,int rol)
{

enum {

   
       NOM,
       PRENOM,
       AGE,
       SEXE,
       ADRESS,
       TEL,
       EMAIL, 
       ROLE,	
       N_COLUMN
};


GtkWidget  *Profils;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_tree_view_get_model(GTK_TREE_VIEW(pListView));

FILE *f;char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];int var8;char var9[8];
f=fopen("/home/noura/Projects/project7/src/profiles.txt","r");


if (pListStore == NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom",pCellRenderer,"text", NOM,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom",pCellRenderer,"text", PRENOM,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("age",
pCellRenderer,
"text", AGE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("sexe",
pCellRenderer,
"text", SEXE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("adress",
pCellRenderer,
"text", ADRESS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("tel",
pCellRenderer,
"text", TEL,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("email",
pCellRenderer,
"text", EMAIL,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("role",
pCellRenderer,
"text", ROLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

}

pListStore=gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT);


while(fscanf(f,"%s %s %s %s %s %s %s %d %s",var1,var2,var3,var4,var5,var6,var7,&var8,var9)!=EOF)
	{

if (rol!=var8)
continue;

GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,NOM,var1,PRENOM,var2,AGE,var3,SEXE,var4,ADRESS,var5,TEL,var6,EMAIL,var7,ROLE,var8,-1);
	}



fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);	

}


