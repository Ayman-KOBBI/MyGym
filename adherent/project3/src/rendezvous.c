#ifdef HAVE_CONFIG_H
#  include <config.h>
#include <stdlib.h>
#endif




#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

enum   
{       
        JOUR,
        MOIS,
	ANNE,
        HEURE,
	AVEC,
	NUM,
        COLUMNS
};



void afficher_rendezvous(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char jour [30];
	char mois [30];
	char anne [30];
	char heure [30];
	char idd[30];
	char id [30];
	char id2[30];
	char a [30];
	char b [30];
        char d [30];
	int c,r,x=0;
	char u[20];
        store=NULL;

       FILE *f;
       FILE *F;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",MOIS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  anne", renderer, "text",ANNE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  avec", renderer, "text",AVEC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  idd", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("/home/dhia/Projects/project3/src/rendezvous.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/dhia/Projects/project3/src/rendezvous.txt", "r");
	F = fopen("/home/dhia/Projects/project3/src/tempo.txt", "r");
              while( fscanf(F,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
		{
              while(fscanf(f,"%s %s %s %s %d %s %s  \n",jour,mois,anne,heure,&r,idd,id2)!=EOF)
		
		{
		x=x+1;
		if(strcmp(id2,d)==0)
{
	if (r==3) strcpy(u,"kiné");
	else if (r==4) strcpy(u,"coach");
	else if (r==5) strcpy(u,"nutri");
	else if (r==6) strcpy(u,"medecin");
	sprintf(idd, "%d", x);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, JOUR, jour, MOIS, mois, ANNE, anne,HEURE,heure,AVEC,u,NUM,idd, -1); 
		}
		}
		}
		fclose(f);
		fclose(F);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}





