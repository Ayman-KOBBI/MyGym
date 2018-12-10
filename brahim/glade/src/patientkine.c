#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "patientkine.h"
#include <gtk/gtk.h>

enum   
{       
	ID,
        NOM,
	PRENOM,
        AGE,
        ETAT,
	MEDICAMENTS,
	AVIS,
	
	//NOM_PATIENT,
	//PRENOM_PATIENT,
        COLUMNS
};

//Ajouter une personne

void ajouter_personne(Personne p)
{

 FILE *f;
  f=fopen("patientkine.txt","a+");
  if(f!=NULL) 
  	{
  fprintf(f,"%s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.age,p.etat,p.medicaments,p.avis);
  fclose(f);

	}

}


//Supprimer une fiche
//void suprimer(char [], char pass [])

//Afficher une personne


void afficher_personne(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char id[20];
	char nom[20];
	char prenom[20];
	char age[20];
	signed char etat[100];
	signed char medicaments[100];
	signed char avis[400];

        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  age", renderer, "text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  etat", renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  medicaments", renderer, "text",MEDICAMENTS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  avis", renderer, "text",AVIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



		//renderer = gtk_cell_renderer_text_new ();
		//column = gtk_tree_view_column_new_with_attributes("  nom_patient", renderer, "text",NOM_PATIENT, NULL);
		//gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		//renderer = gtk_cell_renderer_text_new ();
		//column = gtk_tree_view_column_new_with_attributes(" prenom_patient", renderer, "text",PRENOM_PATIENT, NULL);	
		//gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("patientkine.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("patientkine.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s \n",id,nom,prenom,age,etat,medicaments,avis)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ID,id,NOM,nom,PRENOM,prenom,AGE,age,ETAT,etat,MEDICAMENTS,medicaments,AVIS,avis, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}





