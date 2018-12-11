#include<gtk/gtk.h>
#include"fonctions.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int verifier(char name[50], char login[50]) 
{ 
  
  char ch1[50],ch2[50];
  FILE *f;
  int role;
  f =fopen("/home/yassmine/Projects/project1/src/authentification.txt","r");  

if (f!=NULL)
{ 
   while((fscanf(f,"%s %s %d",ch1,ch2,&role)!=EOF))
   { 
      if ((strcmp(ch1,name)==0) && (strcmp(ch2,login)==0))
{
	 return (1) ;
     }

      else {  return (0) ;}  
}        
fclose(f) ;
}
}
void ajouter_y(personne p)
{
FILE *f;


f=fopen("/home/yassmine/Projects/project1/src/ajout.txt","w");  
if (f!=NULL)
{ 
  fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime);
fclose(f);
}

}

void afficher_y(GtkWidget *treeview1y)
{
       GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

       personne p ;
        store=NULL;
        
       FILE *f2;
	
	store=gtk_tree_view_get_model(treeview1y);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);	

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin ", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour ", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" sexe", renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);
     
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" imc", renderer, "text",IMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clas", renderer, "text",CLAS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" regime ", renderer, "text",REGIME , NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1y), column);
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f2 = fopen("/home/yassmine/Projects/project1/src/ajout.txt", "r");
	
	if(f2==NULL)
	{

		return;
	}		
	else 

	{ f2 = fopen("/home/yassmine/Projects/project1/src/ajout.txt", "a+");
              while(fscanf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas, p.regime)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, p.nom, PRENOM, p.prenom, CIN,p.cin,JOUR,p.jour,MOIS,p.mois,ANNEE,p.annee,SEXE,p.sexe,TAILLE,p.taille,POIDS,p.poids,IMC,p.imc,CLAS,p.clas,REGIME,p.regime, -1); 
}
		fclose(f2);
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1y),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void ajouter_d(disponibilite d)
{
FILE *f;


f=fopen("/home/yassmine/Projects/project1/src/dispo.txt","w");  
if (f!=NULL)
{ 
  fprintf(f,"%s %s %s %s\n",d.jour,d.mois,d.annee,d.horaire);
fclose(f);
}

}
void modifier_y(personne p , personne m )
{
FILE *f ;
FILE *ftemp;
f=fopen("/home/yassmine/Projects/project1/src/ajout.txt","r");
ftemp=fopen("/home/yassmine/Projects/project1/src/temp.txt","a+");
if(f !=NULL) 
	{
           while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime)!=EOF)
if ((strcmp(p.cin,m.cin)==0))			
					{
                                         fprintf(ftemp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",m.nom,m.prenom,m.cin,m.jour,m.mois,m.annee,m.sexe,m.taille,m.poids,m.imc,m.clas,m.regime);
					}		
else
{
fprintf(ftemp,"%s %s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime);
}}
fclose(f);
fclose(ftemp);
remove ("/home/yassmine/Projects/project1/src/ajout.txt");
rename ("/home/yassmine/Projects/project1/src/temp.txt","/home/yassmine/Projects/project1/src/ajout.txt");
}

/*enum   
{     
	NOM,
	PRENOM,
	DATE,
	ID,
	COLUMNS
};


void afficher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	char nom [30];
	char prenom [30];
	char date [30];
	char emedical[30];
	char ephysio[30];
	char eana[30];
	char epsych[30];
	char descriptif[50];
	char id[20];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date_naissance", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/yassmine/Projects/project1/src/fichemedicale.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/yassmine/Projects/project1/src/fichemedicale.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,date,emedical,ephysio,eana,epsych,descriptif,id)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,  NOM, nom, PRENOM, prenom,DATE,date,ID,id, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}*/





