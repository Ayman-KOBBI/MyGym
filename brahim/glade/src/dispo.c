#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "dispo.h"


enum
{ 

  JOUR,
  MOIS,
  ANNEE,
  HORAIRES,
  SALLE,
  COLUMNS
};
void afficher_dispo(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;

  char jour[20];
  char mois[20];
  char annee[20];
  char horaires[20];
  char salle[20];
  store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if(store==NULL)
  {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" horaires",renderer,"text",HORAIRES,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("sallesReserve.txt","r");
    if(f==NULL)
    {
       return;
    }
    else
    {
      f=fopen("sallesReserve.txt","a+");
        while(fscanf(f,"%s %s %s %s %s \n" ,jour,mois,annee,horaires,salle)!=EOF)
        {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,JOUR,jour,MOIS,mois,ANNEE,annee,HORAIRES,horaires,SALLE,salle,-1);
        }
          fclose(f);
           gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
           g_object_unref(store);
     }
   }
} 


  
