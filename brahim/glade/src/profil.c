#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "profil.h"
#include <gtk/gtk.h>

enum   
{       
        NOM,
	PRENOM,
        AGE,
        SEXE,
	ADRESSE,
	NTEL,
	EMAIL,
	//ROLE,
	//ID,
	
        COLUMNS
};

//Ajouter une personne

void ajouter_profil(Profil t)
{

 FILE *f1;
  f1=fopen("profil.txt","w+");
  if(f1!=NULL) 
  {
  fprintf(f1,"%s %s %s %s %s %s %s %s \n",t.nom,t.prenom,t.age,t.sexe,t.adresse,t.ntel,t.email);
  fclose(f1);

}

}


//Afficher une personne


void afficher_profil(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char age[20];
	char sexe[20];
	char adresse[20];
	char ntel[12];
	char email[20];
	//char role[20];
	//char id[20];
        store=NULL;

       FILE *f1;
	
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
		column = gtk_tree_view_column_new_with_attributes("  age", renderer, "text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  sexe", renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  ntel", renderer, "text",NTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  email", renderer, "text",EMAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		//renderer = gtk_cell_renderer_text_new ();
		//column = gtk_tree_view_column_new_with_attributes("  role", renderer, "text",ROLE, NULL);
		//gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		//renderer = gtk_cell_renderer_text_new ();
		//column = gtk_tree_view_column_new_with_attributes("  id", renderer, "text",ID, NULL);
		//gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	
	
	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f1 = fopen("profil.txt", "r");
	
	if(f1==NULL)
	{

		return;
	}
	else 

	{ f1 = fopen("profil.txt", "a+");
              while(fscanf(f1,"%s %s %s %s %s %s %s \n",nom,prenom,age,sexe,adresse,ntel,email)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom,AGE,age,SEXE,sexe,ADRESSE,adresse,NTEL,ntel,EMAIL,email, -1); 
		}
		fclose(f1);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}





	//}		
