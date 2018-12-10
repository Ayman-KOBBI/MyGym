#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonct.h"
#include "string.h"

void
on_button1n_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *label4n;


	char login[30];
	char password[30];
	int r;
	


	input1=lookup_widget(objet_graphique,"entry1n");
	input2=lookup_widget(objet_graphique,"entry2n");
	label4n=lookup_widget(objet_graphique,"label4n");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
	
	r=verif(login,password);
	
	

	
	if (r==1)
	{	
		GtkWidget *window;
		GtkWidget *window1;
	        window= create_Admin();
  	        gtk_widget_show (window);
		window1=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(window1);
		FILE *f;
FILE *f1;
int c1,d1;
char a1[20],b1[20];
f=fopen("/home/noura/Projects/project7/src/users.txt","r");
f1=fopen("/home/noura/Projects/project7/src/tempo.txt","w");
while (fscanf(f,"%s %s %d %d \n",a1,b1,&c1,&d1)!=EOF)
{
   if ((strcmp(login, a1)== 0) && (strcmp(password, b1)== 0))
    {
     fprintf(f1,"%s %s %d %d \n",login,password,c1,d1);
     break;
    }
}
fclose(f1);
fclose(f);
} 
	else if (r==2)
	{	GtkWidget *login;
		GtkWidget *medecin;
	 	medecin= create_medecin ();
  	        gtk_widget_show (medecin);
		login=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(login);
	}

	else if (r==3)
	{	
		GtkWidget *login;
		GtkWidget *dieteticien;
	        dieteticien= create_dieteticien();
  	        gtk_widget_show (dieteticien);
		login=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(login);
	}

	 else if (r==5)
    	{	GtkWidget *login;
		GtkWidget *kinesitherapeute;
		kinesitherapeute= create_kinesitherapeute ();
  	        gtk_widget_show (kinesitherapeute);
		login=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(login);
	}
	 else if (r==4)
	{
		GtkWidget *login;
		GtkWidget *coach;
		coach= create_coach ();
  	        gtk_widget_show (coach);
		login=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(login);

	}
	else if (r==6)
	{
		GtkWidget *login;
		GtkWidget *adherent;
		adherent= create_adherent ();
  	        gtk_widget_show (adherent);
		login=lookup_widget(objet_graphique,"login");
		gtk_widget_hide(login);

	}

	else 
{gtk_label_set_text(GTK_LABEL(label4n),"authentification non validée");}
}





void
on_button3n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *ProfilAdmin;
Admin= create_Admin();
gtk_widget_show (Admin);
ProfilAdmin= lookup_widget(objet_graphique,"ProfilAdmin");
gtk_widget_hide(ProfilAdmin);
}


void
on_button5n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *agee;
GtkWidget *combobox1n;

GtkWidget *ProfilAdmin;


FILE* f1;
kprofil p;



ProfilAdmin=lookup_widget(objet_graphique,"ProfilAdmin");
input1= lookup_widget(objet_graphique,"entry3n");
input2= lookup_widget(objet_graphique,"entry4n");
input3= lookup_widget(objet_graphique,"entry5n");
input4= lookup_widget(objet_graphique,"entry6n");
input5= lookup_widget(objet_graphique,"entry7n");

agee=lookup_widget(GTK_WIDGET(objet_graphique),"spinbutton1n");
combobox1n=lookup_widget(objet_graphique, "combobox1n");
f1=fopen("/home/noura/Projects/project7/src/profil.txt","r");
fscanf(f1,"%s %s %d %s %s %s %s",p.nom,p.prenom,&p.age,p.sexe,p.tel,p.adress,p.mail);

gtk_entry_set_text (GTK_ENTRY(input1),p.nom);
gtk_entry_set_text (GTK_ENTRY(input2),p.prenom);
gtk_entry_set_text (GTK_ENTRY(input3),p.tel);
gtk_entry_set_text (GTK_ENTRY(input4),p.adress);
gtk_entry_set_text (GTK_ENTRY(input5),p.mail);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(agee),p.age);

if(strcmp(p.sexe,"homme")==0)
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1n),0);
 else 
 gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1n),1);
fclose(f1);

}




void
on_button4n_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
char nom[50];char prenom[50];int x;char sexe[50];char tel[50];char adress[50];char mail[50]; 
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *ProfilAdmin;
GtkWidget *age;
GtkWidget *combobox1n;


ProfilAdmin=lookup_widget(objet_graphique,"ProfilAdmin");
input1= lookup_widget(objet_graphique,"entry3n");
input2= lookup_widget(objet_graphique,"entry4n");
input3= lookup_widget(objet_graphique,"entry5n");
input4= lookup_widget(objet_graphique,"entry6n");
input5= lookup_widget(objet_graphique,"entry7n");



age=lookup_widget(objet_graphique,"spinbutton1n");
combobox1n=lookup_widget(objet_graphique, "combobox1n"); 
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(adress,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(mail,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1n))); 

ajouter(nom,prenom,x,sexe,tel,adress,mail);
}


void
on_button2n__clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *ProfilAdmin;
ProfilAdmin= create_ProfilAdmin();
gtk_widget_show (ProfilAdmin);
Admin= lookup_widget(objet_graphique,"Admin");
gtk_widget_hide(Admin);
}


void
on_button6n_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin,*List_View;
GtkWidget *GestionCompte;
GestionCompte= create_GestionCompte();
Admin= lookup_widget(objet_graphique,"Admin");
gtk_widget_hide(Admin);
gtk_widget_show (GestionCompte);
List_View=lookup_widget(GestionCompte,"treeview1n");
afficher(List_View);
}


void
on_button7n_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionCompte;
GtkWidget *AjouterCompte;
AjouterCompte= create_AjouterCompte();
gtk_widget_show (AjouterCompte);
GestionCompte= lookup_widget(objet_graphique,"GestionCompte");
gtk_widget_hide(GestionCompte);
}


void
on_button8n_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)              
{
GtkWidget *output100;
GtkWidget *output101;
GtkWidget *output102;
GtkWidget *output103;
//
output100=lookup_widget(objet_graphique,"label30n");
output101=lookup_widget(objet_graphique,"label28n");
output102=lookup_widget(objet_graphique,"label29n");
output103=lookup_widget(objet_graphique,"label31n");
//
GtkWidget *combobox2n,*List_View;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
input3=lookup_widget(objet_graphique,"entry8n");
input4=lookup_widget(objet_graphique,"entry9n");
input5=lookup_widget(objet_graphique,"entry10n");
char a[20];char b[20],d[20];
int c;
combobox2n=lookup_widget(objet_graphique, "combobox2n");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(d,gtk_entry_get_text(GTK_ENTRY(input5)));
if(strcmp("adhérent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=6;}
else if(strcmp("médecien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=2;}
else if(strcmp("coach",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=4;}
else if(strcmp("diététicien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=3;}
else if(strcmp("kinésithérapeute",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=5;}
//vrifcin
if(verifcin(d)==0)
{ 

gtk_label_set_text(GTK_LABEL(output100)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output100)," √ ");}
//login pass
if(verifentry(a)==0)
{ gtk_label_set_text(GTK_LABEL(output101)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output101)," √ ");}
//
if(verifentry(b)==0)
{ gtk_label_set_text(GTK_LABEL(output102)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output102)," √ ");}
if((verifcin(d)==1) && (verifentry(b)==1)&& (verifentry(a)==1))
{ajoute(a,b,c,d);
GtkWidget *AjouterCompte;
GtkWidget *GestionCompte;
GestionCompte= create_GestionCompte();
gtk_widget_show (GestionCompte);
AjouterCompte= lookup_widget(objet_graphique,"AjouterCompte");
gtk_widget_hide(AjouterCompte);
List_View=lookup_widget(GestionCompte,"treeview1n");
afficher(List_View);
}
else
{ gtk_label_set_text(GTK_LABEL(output103),"veuillez verifiez vos information svp!");}

}

//////////////////////////Event////////////////////////////

void
on_button9n_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)             
{
GtkWidget *Admin,*List_View;
GtkWidget *GestionEvent;
GestionEvent= create_GestionEvent();
gtk_widget_show (GestionEvent);
Admin= lookup_widget(objet_graphique,"Admin");
gtk_widget_hide(Admin);
List_View=lookup_widget(GestionEvent,"treeview2n");
afficher1(List_View);
}


void
on_button10n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *AjouterEvent;
GtkWidget *GestionEvent;
AjouterEvent= create_AjouterEvent();
gtk_widget_show (AjouterEvent);
GestionEvent= lookup_widget(objet_graphique,"GestionEvent");
gtk_widget_hide(GestionEvent);
}


void
on_button11n_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)            
{
GtkWidget *output200;
GtkWidget *output201;
GtkWidget *output202;

//
output200=lookup_widget(objet_graphique,"label48n");
output201=lookup_widget(objet_graphique,"label49n");
output202=lookup_widget(objet_graphique,"label50n");

GtkWidget *id ,*nom,*jour,*mois,*annee,*frais ,*GestionEvent,*AjouterEvent,*List_View;
char id1[20],nom1[20],frais1[20];int jour1,mois1,annee1;
	
	id=lookup_widget(objet_graphique,"entry11n");
	nom=lookup_widget(objet_graphique,"entry12n");
	
	jour=lookup_widget(objet_graphique,"spinbutton2n");
	mois=lookup_widget(objet_graphique,"spinbutton3n");
        annee=lookup_widget(objet_graphique,"spinbutton4n");
	frais=lookup_widget(objet_graphique,"comboboxentry1n");
	
	

	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(nom)));
        
	jour1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	mois1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
	annee1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

	strcpy(frais1,gtk_combo_box_get_active_text (GTK_COMBO_BOX(frais)));
		//vrifcin
if(verifcin(id1)==0)
{ 

gtk_label_set_text(GTK_LABEL(output200)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output200)," √ ");}
//login pass
if(verifentry(nom1)==0)
{ gtk_label_set_text(GTK_LABEL(output201)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output201)," √ ");}
//
if((verifcin(id1)==1) && (verifentry(nom1)==1))
     {   ajouter1(id1,nom1,jour1,mois1,annee1,frais1);

	GestionEvent=create_GestionEvent();
       gtk_widget_show (GestionEvent);
	AjouterEvent=lookup_widget(objet_graphique,"AjouterEvent");
	gtk_widget_hide(AjouterEvent);
	List_View=lookup_widget(GestionEvent,"treeview2n");
	afficher1(List_View);}
else
{ gtk_label_set_text(GTK_LABEL(output202),"veuillez verifiez vos information svp!");}
    
}


void
on_treeview2n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkWidget *idn,*nomn,*journ,*moisn,*anneen,*fraisn,*GestionEvent,*ModifEvent,*treeview;
gchar *id,*nom,*frais;
gint *jour,*mois,*annee;
	ModifEvent=create_ModifEvent();
	treeview=lookup_widget(objet_graphique,"treeview2n");
	GestionEvent=lookup_widget(objet_graphique,"GestionEvent");
	idn=lookup_widget(ModifEvent,"entry13n");
	nomn=lookup_widget(ModifEvent,"entry14n");
	
	journ=lookup_widget(ModifEvent,"spinbutton5n");
	moisn=lookup_widget(ModifEvent,"spinbutton6n");
 	anneen=lookup_widget(ModifEvent,"spinbutton7n");
	fraisn=lookup_widget(ModifEvent,"comboboxentry2n");
	
	
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&jour,3,&mois,4,&annee,5,&frais,-1);
	printf("%s %s %d %d %d %s",id,nom,jour,mois,annee,frais);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (nomn),_(nom));
        gtk_entry_set_text(GTK_ENTRY (fraisn),_(frais));
	///////////////////////////
	/*gtk_entry_set_text(GTK_ENTRY (journ),_(jour));
	gtk_entry_set_text(GTK_ENTRY (moisn),_(mois));
	gtk_entry_set_text(GTK_ENTRY (anneen),_(annee));*/

	gtk_widget_hide(GestionEvent);
	gtk_widget_show(ModifEvent);

		
}


void
on_button15n_clicked   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)                 
{
GtkWidget *id,*nom,*jour,*mois,*annee,*frais,*current,*GestionEvent,*ModifEvent,*List_View;
	char idk[20],nomk[20],fraisk[20];
	int jourk,moisk,anneek;
	id=lookup_widget(objet_graphique,"entry13n");
	nom=lookup_widget(objet_graphique,"entry14n");
	
	jour=lookup_widget(objet_graphique,"spinbutton5n");
	mois=lookup_widget(objet_graphique,"spinbutton6n");
	annee=lookup_widget(objet_graphique,"spinbutton7n");
	
	frais=lookup_widget(objet_graphique,"comboboxentry2n");
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(nomk,gtk_entry_get_text(GTK_ENTRY(nom)));
	jourk = gtk_spin_button_get_value_as_int(jour);
	moisk = gtk_spin_button_get_value_as_int(mois);
	anneek = gtk_spin_button_get_value_as_int(annee);
	strcpy(fraisk,gtk_combo_box_get_active_text(GTK_COMBO_BOX(frais)));
	
	supprimer1(idk,nomk,jourk,moisk,anneek,fraisk);
	GestionEvent=create_GestionEvent();
	gtk_widget_show (GestionEvent);
	current=lookup_widget(objet_graphique,"ModifEvent");
	gtk_widget_hide(current);
	List_View=lookup_widget(GestionEvent,"treeview2n");
	afficher1(List_View);
}




void
on_button14n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *id,*nom,*jour,*mois,*annee,*frais,*current,*GestionEvent,*ModifEvent,*List_View;
	char idk[20],nomk[20],fraisk[20];
	int jourk,moisk,anneek;
	id=lookup_widget(objet_graphique,"entry13n");
	nom=lookup_widget(objet_graphique,"entry14n");
	
	jour=lookup_widget(objet_graphique,"spinbutton5n");
	mois=lookup_widget(objet_graphique,"spinbutton6n");
	annee=lookup_widget(objet_graphique,"spinbutton7n");
	
	frais=lookup_widget(objet_graphique,"comboboxentry2n");
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(nomk,gtk_entry_get_text(GTK_ENTRY(nom)));
	jourk = gtk_spin_button_get_value_as_int(jour);
	moisk = gtk_spin_button_get_value_as_int(mois);
	anneek = gtk_spin_button_get_value_as_int(annee);
	strcpy(fraisk,gtk_combo_box_get_active_text(GTK_COMBO_BOX(frais)));
	
	modifier1(idk,nomk,jourk,moisk,anneek,fraisk);
	GestionEvent=create_GestionEvent();
	gtk_widget_show (GestionEvent);
	current=lookup_widget(objet_graphique,"ModifEvent");
	gtk_widget_hide(current);
	List_View=lookup_widget(GestionEvent,"treeview2n");
	afficher1(List_View);
}


void
on_button16n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *Profils,*listeview;
GtkWidget *GestionCompte;
Profils= create_Profils();
gtk_widget_show (Profils);
GestionCompte= lookup_widget(objet_graphique,"GestionCompte");

gtk_widget_hide(GestionCompte);
listeview=lookup_widget(Profils,"treeview3n");
afficher2(listeview,5);
}


void
on_button17n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *Profils,*List_View;
GtkWidget *GestionCompte;
GestionCompte= create_GestionCompte();
gtk_widget_show (GestionCompte);
Profils= lookup_widget(objet_graphique,"Profils");
gtk_widget_hide(Profils);
List_View=lookup_widget(GestionCompte,"treeview1n");
afficher(List_View);
}


void
on_treeview1n_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *logink,*passwordk,*rolek,*idk,*ModifCompte,*GestionCompte;
    gchar *login,*password,*role,*id;

   ModifCompte=create_ModifCompte();
    logink=lookup_widget(ModifCompte,"entry15n");
    passwordk=lookup_widget(ModifCompte,"entry16n");
    idk=lookup_widget(ModifCompte,"entry18n");
    rolek=lookup_widget(ModifCompte,"entry17n");
    GtkTreeIter iter;
    GtkTreeModel *model=gtk_tree_view_get_model (treeview);
    gtk_tree_model_get_iter(model,&iter,path);
    gtk_tree_model_get (model,&iter,0,&login,1,&password,2,&role,3,&id,-1);
    printf("%s %s %s %s",login,password,role,id);
    gtk_entry_set_text(GTK_ENTRY (logink),_(login));
    gtk_entry_set_text(GTK_ENTRY (passwordk),_(password));
    gtk_entry_set_text(GTK_ENTRY (rolek),_(role));
    gtk_entry_set_text(GTK_ENTRY (idk),_(id));
    gtk_widget_show(ModifCompte);

    GestionCompte= lookup_widget(treeview,"GestionCompte");
    gtk_widget_hide(GestionCompte);
}


void
on_button18n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *login,*password,*role,*id,*current,*GestionCompte,*ModifCompte,*List_View;
	char logink[20],passwordk[20],rolek[20],idk[20];
	
	login=lookup_widget(objet_graphique,"entry15n");
	password=lookup_widget(objet_graphique,"entry16n");
	
	role=lookup_widget(objet_graphique,"entry17n");
	id=lookup_widget(objet_graphique,"entry18n");
	
	
	strcpy(logink,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(passwordk,gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(rolek,gtk_entry_get_text(GTK_ENTRY(role)));
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	
	modifier3(logink,passwordk,rolek,idk);
	GestionCompte=create_GestionCompte();
	gtk_widget_show (GestionCompte);
	current=lookup_widget(objet_graphique,"ModifCompte");
	gtk_widget_hide(current);
	List_View=lookup_widget(GestionCompte,"treeview1n");
	afficher(List_View);
}


void
on_button20n_clicked     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)              
{
GtkWidget *login,*password,*role,*id,*current,*GestionCompte,*ModifCompte,*List_View;
	char logink[20],passwordk[20],rolek[20],idk[20];
	
	login=lookup_widget(objet_graphique,"entry15n");
	password=lookup_widget(objet_graphique,"entry16n");
	
	role=lookup_widget(objet_graphique,"entry17n");
	id=lookup_widget(objet_graphique,"entry18n");
	
	
	strcpy(logink,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(passwordk,gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(rolek,gtk_entry_get_text(GTK_ENTRY(role)));
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	
	supprimer3(logink,passwordk,rolek,idk); 
      
	GestionCompte=create_GestionCompte();
	gtk_widget_show (GestionCompte);
	current=lookup_widget(objet_graphique,"ModifCompte");
	gtk_widget_hide(current);
	List_View=lookup_widget(GestionCompte,"treeview1n");
	afficher(List_View);
}


void
on_combobox4n_changed                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox4n;
GtkWidget *Profils;
GtkWidget *listeview;
char role[50];


combobox4n=lookup_widget(objet_graphique, "combobox4n");
Profils=lookup_widget(objet_graphique, "Profils");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4n)));
listeview = lookup_widget(Profils,"treeview3n");

if (strcmp(role,"adherent")==0)
{
afficher2(listeview,6);
}
else if (strcmp(role,"coach")==0)
{
afficher2(listeview,4);
}
else if (strcmp(role,"dieteticien")==0)
{
afficher2(listeview,3);
}
else if (strcmp(role,"medecin")==0)
{
afficher2(listeview,2);
}
else 
{
afficher2(listeview,5);
}
}


void
on_button21n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *Admin;
GtkWidget *GestionCompte;
Admin= create_Admin();
gtk_widget_show (Admin);
GestionCompte= lookup_widget(objet_graphique,"GestionCompte");
gtk_widget_hide(GestionCompte);
}


void
on_button22n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data) 
{
gtk_main_quit();
}


void
on_button23n_clicked    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)               
{
GtkWidget *Admin;
GtkWidget *GestionEvent;
Admin= create_Admin();
gtk_widget_show (Admin);
GestionEvent= lookup_widget(objet_graphique,"GestionEvent");
gtk_widget_hide(GestionEvent);
}


void
on_button24n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button27n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button25n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *login;
login= create_login();
gtk_widget_show (login);
Admin= lookup_widget(objet_graphique,"Admin");
gtk_widget_hide(Admin);
}


void
on_button26n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}

