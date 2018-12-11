#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

enum  
{       
        NOM,
        PRENOM,
	AGE,
        SEX,
	ADRESSE,
	TEL,
	EMAIL,
        COLUMNS
};



void afficher_infoperso(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenon [30];
	char age [30];
	char sex [30];
	char adresse [30];
	char tel [30];
	char email [30];
        store=NULL;

       FILE *p;
       FILE *p2;
	
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
		column = gtk_tree_view_column_new_with_attributes("  sex", renderer, "text",SEX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  tel", renderer, "text",TEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  email", renderer, "text",EMAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	char a1[20],b1[20],1c[20],d1[20],r[20],id[20];
	int y=0;
	p= fopen("/home/dhia/Projects/project3/src/profiles.txt", "r");
	p2=fopen("/home/dhia/Projects/project3/src/tempo.txt", "r");
	fscanf(p,"%s %s %s %s  \n",a1,b1,1c,d1)
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",nom,prenon,age,sex,adresse,tel,email,r,id)!=EOF){
		{if(strcmp(id,d1)==0) {break;
					y=1;}
	}
	if (y==1){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, PRENOM, AGE, SEX, ADRESSE, TEL,EMAIL, -1); 
	}
	fclose(P);
	fclose(p2);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
        g_object_unref (store);
}



