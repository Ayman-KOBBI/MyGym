

void ajouter(kevent a)
{
	FILE *f;
	f = fopen("/home/noura/Projects/project7/src/event.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s %d %d %d\n",a.identifiant,a.nom,a.description,a.jour,a.mois,a.annee);
	}
	fclose(f);

}





void afficher1(GtkWidget *plistview)
{ 
enum { COL_IDENTIFIANT,
	COL_NOM,
       COL_DESCRIPTION,
       COL_JOUR,
	COL_MOIS,
	COL_ANNEE,
       NUM_COLS
      };
char identifiant[20],nom[20],description[20]; int jour,mois,annee;
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
FILE *f;
f=fopen("/home/noura/Projects/project7/src/event.txt","r");

if(f!=NULL){
       while(fscanf(f,"%s %s %s %d %d %d\n",identifiant,nom,description,&jours,&mois,&annee)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
			COL_IDENTIFIANT, identifiant,
			COL_NOM, nom,
       			COL_DESCRIPTION,description,
       			COL_JOUR,jour,
			COL_MOIS,mois,
			COL_ANNEE,annee,
                       -1);}
		
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Identifiant",celrender,"text",COL_IDENTIFIANT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("description",celrender,"text",COL_DESCRIPTION,NULL);
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

	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
  


void modifier(char identifiant[],char nom[],char description[],int jour,int mois,int annee)
{ 	
	char identifiantn[20],nomn[20],descriptionn[20];int journ,moisn,anneen;
int agen,poidsn;
	FILE *f , *tmp;
	f=fopen("/home/noura/Projects/project7/src/event.txt","r");
	tmp=fopen("/home/noura/Projects/project7/src/event.tmp","a+");
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",identifiantn,nomn,n,&agen,&poidsn,tensionn,maladiesn,observationsn)!=EOF){
		if(!strcmp(identifiant,identifiantn) ){fprintf(tmp,"%s %s %s %d %d %s %s %s\n",identifiant,nom,prenom,age,poids,tension,maladies,observations);}
else fprintf(tmp,"%s %s %s %d %d %s %s %s\n",identifiantn,nomn,prenomn,agen,poidsn,tensionn,maladiesn,observationsn);
}
fclose(f);
fclose(tmp);
rename("/home/amel/Projects/project7/src/adherants.tmp","/home/amel/Projects/project7/src/adherants.txt");
}                  


void supprimer(char identifiant[],char nom[],char prenom[],int age,int poids,char tension[],char maladies[],char observations[])
{ 	
	char identifiantn[20],nomn[20],prenomn[20],tensionn[20],maladiesn[20],observationsn[150];
int agen,poidsn;
	FILE *f , *tmp;
	f=fopen("/home/amel/Projects/project7/src/adherants.txt","r");
	tmp=fopen("/home/amel/Projects/project7/src/adherants.tmp","a+");
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",identifiantn,nomn,prenomn,&agen,&poidsn,tensionn,maladiesn,observationsn)!=EOF){
		if(!strcmp(identifiant,identifiantn) ){continue;}
else fprintf(tmp,"%s %s %s %d %d %s %s %s\n",identifiantn,nomn,prenomn,agen,poidsn,tensionn,maladiesn,observationsn);
}
fclose(f);
fclose(tmp);
rename("/home/amel/Projects/project7/src/adherants.tmp","/home/amel/Projects/project7/src/adherants.txt");
} 
