#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verify.h"
#include "patientkine.h"
#include "profil.h"
#include "reservation.h"
#include "dispo.h"

void
on_button1b_clicked                    (GtkWidget *button1, gpointer user_data)
{
	GtkWidget *windowb;
	GtkWidget *window1b;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *output;
	char username[20];char password[30];
	char erreur[30];
	int verif ;

	window1b=lookup_widget(button1,"window1b");
	input1=lookup_widget(button1,"entry1");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
	input2=lookup_widget(button1,"entry2");
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
	verif=verify(username,password);



if (verif==2){gtk_widget_hide(window1b);
windowb=create_window3b();
gtk_widget_show_all(windowb);
FILE *f;
FILE *f1;
int c1,d1;
char a1[20],b1[20];
f=fopen("/home/brahim/Projet/glade/users.txt","r");
f1=fopen("/home/brahim/Projet/glade/tempo.txt","w");
while (fscanf(f,"%s %s %d %d \n",a1,b1,&c1,&d1)!=EOF)
{
   if ((strcmp(username, a1)== 0) && (strcmp(password, b1)== 0))
    {
     fprintf(f1,"%s %s %d %d \n",username,password,c1,d1);
     break;
    }
}
fclose(f1);
fclose(f);
}

else if (verif==-1){strcpy(erreur,"erreur");
output=lookup_widget(button1,"label7");
gtk_label_set_text(GTK_LABEL(output),erreur);}


}


void
on_button2b_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3b;
GtkWidget *fenetre_ajoutb;


fenetre_ajoutb=create_fenetre_ajoutb();
gtk_widget_show(fenetre_ajoutb);
gtk_widget_hide(window3b);


}

void
on_button3b_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3b;
GtkWidget *window10b;


window10b=create_window10b();
gtk_widget_show(window10b);
gtk_widget_hide(window3b);
}
void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


}

void
on_button5b_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *comboboxentry3;
GtkWidget *comboboxentry2;

char nom_salle[100][5];
Date dt_resr;
int i,n,hr_resr;
char stringNum[20];
int num=100;

// associé les objets avec des variables
comboboxentry3=lookup_widget(objet_graphique, "comboboxentry3");
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");


comboboxentry2=lookup_widget(objet_graphique, "comboboxentry2");


// récuperer les valeurs 
dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(strcmp("9h==>10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=1;
else
if(strcmp("10h==>11h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=2;
else
if(strcmp("11h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=3;
else
if(strcmp("14h==>15h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=4;
else
if(strcmp("15h==>16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=5;
else
if(strcmp("17h==>18h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
hr_resr=6;

 n=tableau_salle_disponible(nom_salle, dt_resr, hr_resr);
for(i=0;i<n;i++)
{
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry3), _(nom_salle[i]));

}
}

void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button7b_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3b;
GtkWidget *window12b;


window12b=create_window12b();
gtk_widget_show(window12b);
gtk_widget_hide(window3b);



}

void
on_button8b_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3b;
GtkWidget *window11b;


window11b=create_window11b();
gtk_widget_show(window11b);
gtk_widget_hide(window3b);


}                  
void
on_button9b_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
Personne p;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *fenetre_ajoutb;

fenetre_ajoutb=lookup_widget(objet,"fenetre_ajoutb");


input1=lookup_widget(objet,"id");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"age");
input5=lookup_widget(objet,"etat");
input6=lookup_widget(objet,"medicaments");
input7=lookup_widget(objet,"avis");


strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.medicaments,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.avis,gtk_entry_get_text(GTK_ENTRY(input7)));




ajouter_personne(p);
}
void
on_button10b_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{

GtkWidget *fenetre_ajoutb;
GtkWidget *fenetre_afficherb;
GtkWidget *treeview1;

fenetre_ajoutb=lookup_widget(objet,"fenetre_ajoutb");


gtk_widget_destroy(fenetre_ajoutb);
fenetre_afficherb=lookup_widget(objet,"fenetre_afficherb");
fenetre_afficherb=create_fenetre_afficherb();

gtk_widget_show(fenetre_afficherb);
      

treeview1=lookup_widget(fenetre_afficherb,"treeview1");

afficher_personne(treeview1); 

}
void
on_button11_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *fenetre_ajoutb, *fenetre_afficherb;

fenetre_afficherb=lookup_widget(objet,"fenetre_afficherb");


//gtk_widget_destroy(fenetre_afficherb);
fenetre_ajoutb=create_fenetre_ajoutb();
gtk_widget_show(fenetre_ajoutb);
}



void
on_button12b_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{
Profil t;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *window11b;

window11b=lookup_widget(objet,"window11b");

input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"prenom");
input3=lookup_widget(objet,"age");
input4=lookup_widget(objet,"sexe");
input5=lookup_widget(objet,"adresse");
input6=lookup_widget(objet,"ntel");
input7=lookup_widget(objet,"email");


strcpy(t.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(t.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(t.age,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(t.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(t.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(t.ntel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(t.email,gtk_entry_get_text(GTK_ENTRY(input7)));




ajouter_profil(t);
}



void
on_button13b_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *window11b;
GtkWidget *window13b;
GtkWidget *treeview2;

window11b=lookup_widget(objet,"window11b");


gtk_widget_destroy(window11b);
window13b=lookup_widget(objet,"window13b");
window13b=create_window13b();

gtk_widget_show(window13b);
      

treeview2=lookup_widget(window13b,"treeview2");

afficher_profil(treeview2); 

}


//////////////////////////////////////////////////////////////////////////////////////////////
void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	FILE *f1,*f2;
	f1=fopen("/home/brahim/Projet/glade/patientkine.txt","a+");
	f2=fopen("/home/brahim/Projet/glade/temp.txt","a+");

	char nom_patient[20],prenom_patient[20],patient_id[20];
	Personne p;

	input1=lookup_widget(objet,"patient_id");
	strcpy(patient_id,gtk_entry_get_text(GTK_ENTRY(input1)));

	input2=lookup_widget(objet,"nom_patient");
	strcpy(nom_patient,gtk_entry_get_text(GTK_ENTRY(input2)));

	input3=lookup_widget(objet,"prenom_patient");
	strcpy(prenom_patient,gtk_entry_get_text(GTK_ENTRY(input3)));



	while(fscanf(f1,"%s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.age,p.etat,p.medicaments,p.avis)!=EOF)
	{ if ((strcmp(nom_patient,p.nom) != 0) && (strcmp(prenom_patient,p.prenom) != 0)&& (strcmp(patient_id,p.id) != 0))

			{fprintf(f2,"%s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.age,p.etat,p.medicaments,p.avis) ;
			}
	}
	fclose(f1);
	fclose(f2);
	remove("patientkine.txt");
	rename("temp.txt","patientkine.txt");


//ajouter_personne(p);
}



void
on_button15b_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficherb;
GtkWidget *window14b;


window14b=create_window14b();
gtk_widget_show(window14b);
gtk_widget_hide(fenetre_afficherb);


}

void
on_button16b_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *comboboxentry3;
GtkWidget *comboboxentry2;
GtkWidget *label24;
ReservationSalle s;

comboboxentry3=lookup_widget(objet_graphique, "comboboxentry3");
label24=lookup_widget(objet_graphique, "label24");
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");

label24=lookup_widget(objet_graphique, "label24");

comboboxentry3=lookup_widget(objet_graphique, "comboboxentry3");
comboboxentry2=lookup_widget(objet_graphique, "comboboxentry2");
s.dt_res.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_res.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_res.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


if(strcmp("9h==>10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=1;
else
if(strcmp("10h==>11h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=2;
else
if(strcmp("11h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=3;
else
if(strcmp("14h==>15h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=4;
else
if(strcmp("15h==>16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=5;
else
if(strcmp("17h==>18h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)))==0) 
s.hr_resr=6;


strcpy(s.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3)));

reserver_salle( s);


gtk_label_set_text(GTK_LABEL(label24),"Reservation réusite.");
}

void
on_retourfichepatientb_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoutb;
GtkWidget *fenetre_afficherb;

fenetre_afficherb=lookup_widget(objet,"fenetre_afficherb");
gtk_widget_destroy(fenetre_afficherb);
fenetre_ajoutb=create_fenetre_ajoutb();
gtk_widget_show(fenetre_ajoutb);
gtk_widget_destroy(fenetre_afficherb);
}


void
on_retourmenuprincipal_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3b;
GtkWidget *window10b;

window10b=lookup_widget(objet,"window10b");
gtk_widget_destroy(window10b);
window3b=create_window3b();
//gtk_widget_show(window3b);
gtk_widget_destroy(window10b);
}



void
on_button17bb_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *patientamodifier;
GtkWidget *fenetre_afficherb;



patientamodifier=create_patientamodifier();
gtk_widget_show(patientamodifier);
gtk_widget_hide(fenetre_afficherb);


}


void
on_button17ba_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *selectionpatient;
GtkWidget *patientamodifier;



patientamodifier=create_patientamodifier();
gtk_widget_show(patientamodifier);
gtk_widget_hide(selectionpatient);
}


void
on_button18b_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	FILE *f8,*f9;
	f8=fopen("patientkine.txt","a+");
	f9=fopen("temp.txt","a+");

	char nom_patienttt[20],prenom_patienttt[20],age_patient[20],etat_patient[20],medcs_patient[20],avis_patient[20],patient_idd[20];
	Personne p;
	//patient_idd

	input1=lookup_widget(objet,"patient_idd");
	strcpy(patient_idd,gtk_entry_get_text(GTK_ENTRY(input1)));

	input2=lookup_widget(objet,"nom_patienttt");
	strcpy(nom_patienttt,gtk_entry_get_text(GTK_ENTRY(input2)));

	input3=lookup_widget(objet,"prenom_patienttt");
	strcpy(prenom_patienttt,gtk_entry_get_text(GTK_ENTRY(input3)));

	input4=lookup_widget(objet,"age_patient");
	strcpy(age_patient,gtk_entry_get_text(GTK_ENTRY(input4)));

	input5=lookup_widget(objet,"etat_patient");
	strcpy(etat_patient,gtk_entry_get_text(GTK_ENTRY(input5)));

	input6=lookup_widget(objet,"medcs_patient");
	strcpy(medcs_patient,gtk_entry_get_text(GTK_ENTRY(input6)));

	input7=lookup_widget(objet,"avis_patient");
	strcpy(avis_patient,gtk_entry_get_text(GTK_ENTRY(input7)));



	while(fscanf(f8,"%s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.age,p.etat,p.medicaments,p.avis)!=EOF)
	{ if ((strcmp(nom_patienttt,p.nom) != 0) && (strcmp(prenom_patienttt,p.prenom) != 0)&& (strcmp(patient_idd,p.id) != 0))

			{fprintf(f9,"%s %s %s %s %s %s %s\n",patient_idd,nom_patienttt,prenom_patienttt,age_patient,etat_patient,medcs_patient,avis_patient) ;
			}
	else
		continue;
	}
	fclose(f8);
	fclose(f9);
	remove("patientkine.txt");
	rename("temp.txt","patientkine.txt");
}

















void
on_afficherdispo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window10b;
GtkWidget *window1;
GtkWidget *treeview3;

window10b=lookup_widget(objet,"window10b");


gtk_widget_destroy(window10b);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
      

treeview3=lookup_widget(window1,"treeview3");

afficher_dispo(treeview3); 


}

