#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "fonction.h"
#include "rendezvous.h"

void
on_button2y_clicked (GtkButton *objet_graphique, gpointer  user_data)
{
gtk_main_quit();
}


void
on_button1y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
GtkWidget *window1y;
GtkWidget *window2y;
GtkWidget *identifiant1y;
GtkWidget *motpasse1y;
GtkWidget *output1y;

char name[30],login[30];
int ver;

identifiant1y=lookup_widget(objet_graphique, "entry1y");
motpasse1y=lookup_widget(objet_graphique, "entry2y");
output1y=lookup_widget(objet_graphique, "label5y");

strcpy(name,gtk_entry_get_text(GTK_ENTRY(identifiant1y)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(motpasse1y)));
gtk_label_set_text(GTK_LABEL(output1y),login);

ver=verifier(name,login);

      if(ver==1)
            {
            window1y=lookup_widget(objet_graphique, "window1y");
             window2y = create_window2y ();
             gtk_widget_show(window2y);
             gtk_widget_hide(window1y);
            }  
gtk_label_set_text(GTK_LABEL(output1y),"authentification _non_valide");
}


void
on_button3y_clicked (GtkButton *objet_graphique, gpointer user_data)
{  
             GtkWidget *window2y;
             GtkWidget *window3y;

             window2y=lookup_widget(objet_graphique, "window2y");
             window3y = create_window3y ();
             gtk_widget_show(window3y);
             gtk_widget_hide(window2y);

}


void
on_button7y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void
on_button8y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
             GtkWidget *window3y;
             GtkWidget *window4y;

             window3y=lookup_widget(objet_graphique, "window3y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window3y);
}


void
on_button10y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
            GtkWidget *window3y;
            GtkWidget *window2y;

             window3y=lookup_widget(objet_graphique, "window3y");
             window2y = create_window2y ();
             gtk_widget_show(window2y);
             gtk_widget_hide(window3y);
}


void
on_checkbutton1y_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{

   GtkWidget *entry2y;
  entry2y= lookup_widget(GTK_WIDGET(togglebutton),"entry2y");
   
    if( gtk_entry_get_visibility(GTK_ENTRY(entry2y))==FALSE)
  
     gtk_entry_set_visibility(GTK_ENTRY(entry2y),TRUE);
      

}


void
on_button11y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
            GtkWidget *window4y;
            GtkWidget *window5y;


             window4y=lookup_widget(objet_graphique, "window4y");
             window5y = create_window5y ();
             gtk_widget_show(window5y);
             gtk_widget_hide(window4y);

}


void
on_button16y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
        
	GtkWidget *window2y,*window5y;
        GtkWidget *nom, *prenom, *cin , *regime, *taille, *poids,  *imc ;
        GtkWidget *combobox1y, *combobox2y,*combobox3y, *combobox4y,*combobox5y;
    
	personne p;
        

	nom=lookup_widget(objet_graphique,"entry3y");
	prenom=lookup_widget(objet_graphique,"entry4y");
	cin=lookup_widget(objet_graphique,"entry5y");
        taille=lookup_widget(objet_graphique, "entry6y");
        poids=lookup_widget(objet_graphique, "entry7y");
        imc=lookup_widget(objet_graphique, "entry8y");
        regime=lookup_widget(objet_graphique,"entry9y");
	
       
        window5y=lookup_widget(objet_graphique, "window5y");
        combobox1y=lookup_widget(objet_graphique, "combobox1y");
        combobox2y=lookup_widget(objet_graphique, "combobox2y");
        combobox3y=lookup_widget(objet_graphique, "combobox3y");
        combobox4y=lookup_widget(objet_graphique, "combobox4y");
        combobox5y=lookup_widget(objet_graphique, "combobox5y");
        strcpy(p.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1y)));
        strcpy(p.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2y)));
        strcpy(p.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3y)));
        strcpy(p.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4y)));
        strcpy(p.clas,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5y)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(p.regime,gtk_entry_get_text(GTK_ENTRY(regime)));
        strcpy(p.taille,gtk_entry_get_text(GTK_ENTRY(taille)));
	strcpy(p.poids,gtk_entry_get_text(GTK_ENTRY(poids)));
        strcpy(p.imc,gtk_entry_get_text(GTK_ENTRY(imc)));
        ajouter_y(p);
         
             window2y = create_window2y ();
             gtk_widget_show(window2y);
             gtk_widget_hide(window5y);

}


void
on_button18y_clicked (GtkButton *objet_graphique, gpointer    user_data)
{           GtkWidget *window6y;
            GtkWidget *window7y;
            GtkWidget *input16y, *output16y;
	    personne p;
            char ch[50];
            FILE* f ;
            window6y=lookup_widget(objet_graphique, "window6y");
            input16y=lookup_widget(objet_graphique,"entry21y");
            output16y=lookup_widget(objet_graphique,"label59y");
            strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input16y)));
f=fopen("/home/yassmine/Projects/project1/src/ajout.txt","r");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime)!=EOF)
{ 
if (strcmp(ch,p.cin)==0)
{
             window7y = create_window7y ();
             gtk_widget_show(window7y);
             gtk_widget_hide(window6y);
}
else
{gtk_label_set_text(GTK_LABEL(output16y),"cin incompatible");}
}
}

void
on_button19y_clicked (GtkButton *objet_graphique, gpointer user_data)
{    
            GtkWidget *window4y;
            GtkWidget *window6y;


             window6y=lookup_widget(objet_graphique, "window6y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window6y);


}


void
on_button20y_clicked (GtkButton *objet_graphique, gpointer         user_data)
{
GtkWidget *input1y, *input2y,*input3y,*input4y,*input5y, *input6y,*input7y,*input8y,*input9y, *input10y,*input11y,*input12y;
GtkWidget *window7y,*window4y;


personne p;
personne m;

window7y=lookup_widget(objet_graphique,"window7y");
input1y=lookup_widget(objet_graphique,"entry9y");
input2y=lookup_widget(objet_graphique,"entry10y");
input3y=lookup_widget(objet_graphique,"entry11y");
input4y=lookup_widget(objet_graphique,"entry12y");
input5y=lookup_widget(objet_graphique,"entry13y");
input6y=lookup_widget(objet_graphique,"entry14y");
input7y=lookup_widget(objet_graphique,"entry15y");
input8y=lookup_widget(objet_graphique,"entry16y");
input9y=lookup_widget(objet_graphique,"entry17y");
input10y=lookup_widget(objet_graphique,"entry18y");
input11y=lookup_widget(objet_graphique,"entry19y");
input12y=lookup_widget(objet_graphique,"entry20y");
strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(input1y)));
strcpy(m.prenom,gtk_entry_get_text(GTK_ENTRY(input2y)));
strcpy(m.cin,gtk_entry_get_text(GTK_ENTRY(input3y)));
strcpy(m.jour,gtk_entry_get_text(GTK_ENTRY(input4y)));
strcpy(m.mois,gtk_entry_get_text(GTK_ENTRY(input5y)));
strcpy(m.annee,gtk_entry_get_text(GTK_ENTRY(input6y)));
strcpy(m.sexe,gtk_entry_get_text(GTK_ENTRY(input7y)));
strcpy(m.taille,gtk_entry_get_text(GTK_ENTRY(input8y)));
strcpy(m.poids,gtk_entry_get_text(GTK_ENTRY(input9y)));
strcpy(m.imc,gtk_entry_get_text(GTK_ENTRY(input10y)));
strcpy(m.clas,gtk_entry_get_text(GTK_ENTRY(input11y)));
strcpy(m.regime,gtk_entry_get_text(GTK_ENTRY(input12y)));
modifier_y(p ,m );
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window7y);
}



void
on_button21y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
            GtkWidget *window4y;
            GtkWidget *window7y;


             window7y=lookup_widget(objet_graphique, "window7y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window7y);

}
void
on_button13y_clicked  (GtkButton *objet_graphique, gpointer         user_data)
{
            GtkWidget *window4y;
            GtkWidget *window6y;


             window4y=lookup_widget(objet_graphique, "window4y");
             window6y = create_window6y ();
             gtk_widget_show(window6y);
             gtk_widget_hide(window4y);
}




void
on_button12y_clicked (GtkWidget *objet, gpointer  user_data)
{
GtkWidget *window4y;
GtkWidget *window8y;
GtkWidget *treeview1y;

window4y=lookup_widget(objet,"window4y");


gtk_widget_destroy(window4y);
window8y=lookup_widget(objet,"window8y");
window8y=create_window8y();
gtk_widget_show(window8y);
gtk_widget_hide(window4y);

treeview1y=lookup_widget(window8y,"treeview1y");

afficher_y(treeview1y); 


}


void
on_button23y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
        GtkWidget *jour,*mois,*annee,*horaire ;

        disponibilite d;

	jour=lookup_widget(objet_graphique,"combobox6y");
	mois=lookup_widget(objet_graphique,"combobox7y");
	annee=lookup_widget(objet_graphique,"combobox8y");
        horaire=lookup_widget(objet_graphique, "combobox9y");
   
       
       strcpy(d.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
       strcpy(d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
       strcpy(d.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));
       strcpy(d.horaire,gtk_combo_box_get_active_text(GTK_COMBO_BOX(horaire)));

        ajouter_d(d);
        
}





void
on_button6y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
            GtkWidget *window2y;
            GtkWidget *window9y;


             window2y=lookup_widget(objet_graphique, "window2y");
             window9y = create_window9y ();
             gtk_widget_show(window9y);
             gtk_widget_hide(window2y);
}


void
on_button26y_clicked (GtkButton *objet_graphique, gpointer user_data)
{     
GtkWidget *input120y;
 personne p;

            char ch1[50];
            FILE *f1 ;
            FILE *Ftemp;
input120y=lookup_widget(objet_graphique,"entry21y");
            strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input120y)));
Ftemp=fopen ("/home/yassmine/Projects/project1/src/temp.txt","a+");
f1=fopen("/home/yassmine/Projects/project1/src/ajout.txt","r");


                       while (fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime)!=EOF)
{ 
if (strcmp(ch1,p.cin)!=0)
{
fprintf(Ftemp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime);
}
} 
fclose(Ftemp);
fclose(f1);
remove ("/home/yassmine/Projects/project1/src/ajout.txt");
rename ("/home/yassmine/Projects/project1/src/temp.txt","/home/yassmine/Projects/project1/src/ajout.txt");
}


          


void
on_button14y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
             GtkWidget *window4y;
             GtkWidget *window6y;


             window4y=lookup_widget(objet_graphique, "window4y");
             window6y = create_window6y ();
             gtk_widget_show(window6y);
             gtk_widget_hide(window4y);
}




void
on_button4y_clicked (GtkButton *objet_graphique, gpointer         user_data)
{
             GtkWidget *window2y;
             GtkWidget *window11y;


             window2y=lookup_widget(objet_graphique, "window2y");
             window11y = create_window11y ();
             gtk_widget_show(window11y);
             gtk_widget_hide(window2y);

}


void
on_button5y_clicked                    (GtkButton *objet_graphique,
                                        gpointer         user_data)
{
             GtkWidget *window2y;
             GtkWidget *window12y;
             GtkWidget *treeview3y;

             window2y=lookup_widget(objet_graphique, "window2y");
             window12y = create_window12y ();
             gtk_widget_show(window12y);
             gtk_widget_hide(window2y);
            treeview3y=lookup_widget(window12y,"treeview3y");
		afficher_rendezvous(treeview3y);
             

}


void
on_button9y_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{       GtkWidget *window3y;
	GtkWidget *window10y; 	
	GtkWidget *treeview2y;
	window3y=lookup_widget(button,"window3y");
	gtk_widget_hide(window3y); 
	window10y=create_window10y();
  	gtk_widget_show (window10y);
	treeview2y=lookup_widget(window10y,"treeview2y"); 
	afficher(treeview2y);  

}


void
on_button15y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
             GtkWidget *window4y;
             GtkWidget *window3y;


             window4y=lookup_widget(objet_graphique, "window4y");
             window3y = create_window3y ();
             gtk_widget_show(window3y);
             gtk_widget_hide(window4y);
}


void
on_button17y_clicked (GtkButton *objet_graphique, gpointer user_data)
{
             GtkWidget *window5y;
             GtkWidget *window4y;


             window5y=lookup_widget(objet_graphique, "window5y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window5y);
}


void
on_button22y_clicked (GtkButton *objet_graphique, gpointer user_data)
{        
             GtkWidget *window8y;
             GtkWidget *window4y;


             window8y=lookup_widget(objet_graphique, "window8y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window8y);

}


void
on_button24y_clicked (GtkButton *objet_graphique, gpointer  user_data)
{
             GtkWidget *window9y;
             GtkWidget *window4y;


             window9y=lookup_widget(objet_graphique, "window9y");
             window4y = create_window4y ();
             gtk_widget_show(window4y);
             gtk_widget_hide(window9y);

}


void
on_window11y_show                      (GtkButton *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;


FILE* t1;
FILE* t2;
input1= lookup_widget(objet_graphique,"entry22y");
input2= lookup_widget(objet_graphique,"entry23y");
input3= lookup_widget(objet_graphique,"entry24y");
input4= lookup_widget(objet_graphique,"entry25y");
input5= lookup_widget(objet_graphique,"entry26y");
input6= lookup_widget(objet_graphique,"entry27y");
t1=fopen("/home/yassmine/Projects/project1/src/profiles.txt","r");
t2=fopen("/home/yassmine/Projects/project1/src/tempo.txt","r");
char a2[20],b2[20],c2[20],d2[20],e2[20],f2[20],g2[20],h2[20],i2[20],a[20],b[20],c[20],d[20];
fscanf(t2,"%s %s %s %s",a,b,c,d);
while(fscanf(t1,"%s %s %s %s %s %s %s %s %s \n",a2,b2,c2,d2,e2,f2,g2,h2,i2)!=EOF)
{
				if(strcmp(d,i2)==0)
					{

                                        break;
					}
}
gtk_entry_set_text(GTK_ENTRY(input1),a2);
gtk_entry_set_text(GTK_ENTRY(input2),b2);
gtk_entry_set_text(GTK_ENTRY(input3),c2);
gtk_entry_set_text(GTK_ENTRY(input4),e2);
gtk_entry_set_text(GTK_ENTRY(input5),f2);
gtk_entry_set_text(GTK_ENTRY(input6),g2);
fclose(t1);
fclose(t2);
}




void
on_button27y_clicked (GtkButton *objet_graphique,  gpointer user_data)
{
             GtkWidget *window11y;
             GtkWidget *window2y;


             window11y=lookup_widget(objet_graphique, "window11y");
             window2y = create_window2y ();
             gtk_widget_show(window2y);
             gtk_widget_hide(window11y);

}


void
on_button30y_clicked                   (GtkButton *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *combobox10y;
FILE *t;
FILE *f1;
FILE *ftemp;
char a[20], b[20], c[20], d[20], e[20], f[20], g[20];
input1=lookup_widget(objet_graphique,"entry22y");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entry23y");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet_graphique,"entry24y");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input3)));
combobox10y=lookup_widget(objet_graphique, "combobox10y");
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10y)));
input4=lookup_widget(objet_graphique,"entry25y");
strcpy(e,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet_graphique,"entry26y");
strcpy(f,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet_graphique,"entry27y");
strcpy(g,gtk_entry_get_text(GTK_ENTRY(input6)));
t=fopen("/home/yassmine/Projects/project1/src/tempo.txt","r");
f1=fopen("/home/yassmine/Projects/project1/src/profiles.txt","a+");
ftemp=fopen("/home/yassmine/Projects/project1/src/temp.txt","a+");


char a2[20],b2[20],c2[20],d2[20],e2[20],f2[20],g2[20],a1[20],b1[20],c1[20],d1[20],h2[20],i2[20];
fscanf(t,"%s %s %s %s \n",a1,b1,c1,d1);
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s \n",a2,b2,c2,d2,e2,f2,g2,h2,i2)!=EOF)
{
				if(strcmp(i2,d1)!=0)
					{
                                        fprintf(ftemp,"%s %s %s %s %s %s %s %s %s \n",a2,b2,c2,d2,e2,f2,g2,h2,i2);
					}
}
			
fprintf(ftemp,"%s %s %s %s %s %s %s %s %s  \n",a,b,c,d,e,f,g,c1,d1);
fclose(f1);
fclose(t);
fclose(ftemp);
remove ("/home/yassmine/Projects/project1/src/profiles.txt");
rename ("/home/yassmine/Projects/project1/src/temp.txt","/home/yassmine/Projects/project1/src/profiles.txt");


}


void
on_button25y_clicked                   (GtkButton *objet_graphique,
                                        gpointer         user_data)
{
             GtkWidget *window10y;
             GtkWidget *window3y;


             window10y=lookup_widget(objet_graphique, "window10y");
             window3y = create_window3y ();
             gtk_widget_show(window3y);
             gtk_widget_hide(window10y);

}


void
on_button40y_clicked                   (GtkButton *objet_graphique,
                                        gpointer         user_data)
{
             GtkWidget *window12y;
             GtkWidget *window2y;


             window12y=lookup_widget(objet_graphique, "window12y");
             window2y = create_window2y ();
             gtk_widget_show(window2y);
             gtk_widget_hide(window12y);


}

