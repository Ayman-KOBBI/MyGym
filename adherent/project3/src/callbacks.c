#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verfier.h"
#include "rendezvous.h"
#include "infoperso.h"
#include "fonct.h"
#include "dispo.h"








void
on_button1_clicked                     (GtkWidget        *button , gpointer         user_data)

{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *input;
GtkWidget *input2;
GtkWidget *output;
char x[20];char y[20];
char ext[50];
int verif;int a;
 
window1=lookup_widget(button,"window1");
input=lookup_widget(button,"entry1");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input)));
input2=lookup_widget(button,"entry2");
strcpy(y,gtk_entry_get_text(GTK_ENTRY(input2)));
verif=verifier(x,y);
if( verif==1){gtk_widget_hide(window1);
window=create_admin();
gtk_widget_show_all(window);
FILE *f;
FILE *f1;
int c1,d1;
char a1[20],b1[20];
f=fopen("/home/dhia/Projects/project3/src/users.txt","r");
f1=fopen("/home/dhia/Projects/project3/src/tempo.txt","w");
while (fscanf(f,"%s %s %d %d \n",a1,b1,&c1,&d1)!=EOF)
{
   if ((strcmp(x, a1)== 0) && (strcmp(y, b1)== 0))
    {
     fprintf(f1,"%s %s %d %d \n",x,y,c1,d1);
     break;
    }
}
fclose(f1);
fclose(f);
}
else if( verif==2){gtk_widget_hide(window1);
window=create_adherent();
gtk_widget_show_all(window);
FILE *f;
FILE *f1;
int c1,d1;
char a1[20],b1[20];
f=fopen("/home/dhia/Projects/project3/src/users.txt","r");
f1=fopen("/home/dhia/Projects/project3/src/tempo.txt","w");
while (fscanf(f,"%s %s %d %d \n",a1,b1,&c1,&d1)!=EOF)
{
   if ((strcmp(x, a1)== 0) && (strcmp(y, b1)== 0))
    {
     fprintf(f1,"%s %s %d %d \n",x,y,c1,d1);
     break;
    }
}
fclose(f1);
fclose(f);
}

else if( verif==3){gtk_widget_hide(window1);
window=create_coach();
gtk_widget_show_all(window);}
else if( verif==4){gtk_widget_hide(window1);
window=create_nutritionniste();
gtk_widget_show_all(window);}
else if( verif==5){gtk_widget_hide(window1);
window=create_dieteticien();
gtk_widget_show_all(window);}
else if( verif==6){gtk_widget_hide(window1);window=create_kine();
gtk_widget_show_all(window);}
else if( verif==-1){strcpy(ext,"erreur:user name/ password uncorrect");
output=lookup_widget(button,"label8");
gtk_label_set_text(GTK_LABEL(output),ext);}
}


void
on_button2_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window");
gtk_widget_hide(window);
window1=create_window2();
gtk_widget_show_all(window1);
}


void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}
void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"adherent");
gtk_widget_hide(window);
window1=create_window1();
gtk_widget_show_all(window1);
}

void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview1;
window=lookup_widget(button,"info");
gtk_widget_hide(window);
window1=create_rendezvous();
gtk_widget_show_all(window1);
treeview1=lookup_widget(window1,"treeview23");
afficher_dispo(treeview1);
}


void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rendezvous");
gtk_widget_hide(window);
window1=create_adherent();
gtk_widget_show_all(window1);
}


void
on_button8_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *combobox1;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *combobox2;
GtkWidget *output;
FILE *f;
FILE *f2;
FILE *f3;
combobox1=lookup_widget(button, "combobox1");
spinbutton1=lookup_widget(button, "spinbutton1");
spinbutton2=lookup_widget(button, "spinbutton2");
spinbutton3=lookup_widget(button, "spinbutton3");
combobox2=lookup_widget(button, "combobox2");

int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton1));
int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton2));
int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton3));
char role[20];
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
char HH[20];
strcpy(HH,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
f=fopen("/home/dhia/Projects/project3/src/rendezvous.txt","a+");
f2=fopen("/home/dhia/Projects/project3/src/dispo.txt","a+");
f3=fopen("/home/dhia/Projects/project3/src/tempo.txt","r");
int x;
char t[50];
if(strcmp(role, "kine")== 0) x=3;
else if (strcmp(role, "coach")== 0) x=4;
else if (strcmp(role, "nutritionniste")== 0) x=5;
else if (strcmp(role, "dietitian")== 0) x=6;
int a,b,c,e,g;
char d[20];
int e1,g1,h;
int y=0;
char a4[20],b4[20],c3[20];
int c4,d4;
fscanf(f3,"%s %s %d %d \n",a4,b4,&c4,&d4);
while(fscanf(f2,"%d %d %d %s %d %d \n",&a,&b,&c,d,&e,&g)!=EOF)
{
  if ((a==JJ) && (b==MM) && (c==AA) && (strcmp(d, HH)== 0) && (e==x))
     {
	fprintf(f,"%d %d %d %s %d %d %d \n",JJ, MM,AA,HH,e,g,d4);
      y=1;
      break;
      	
     }
}
             
if (y==0)
{ strcpy(t,"il faut choisir un autre rendez vous");
output=lookup_widget(button,"label88");
gtk_label_set_text(GTK_LABEL(output),t);
}
else if (y==1)
{
     fclose(f2);
     fclose(f);
     fclose(f3);
     window=lookup_widget(button,"rendezvous");
     gtk_widget_hide(window);
     window1=create_adherent();
     gtk_widget_show_all(window1);
}
}


void
on_button10_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview1;
window=lookup_widget(button,"adherent");
gtk_widget_hide(window);
window1=create_info();
gtk_widget_show_all(window1);
treeview1=lookup_widget(window1,"treeview1");
afficher_rendezvous(treeview1);
}


void
on_button11_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"info");
gtk_widget_hide(window);
window1=create_adherent();
gtk_widget_show_all(window1);
}


void
on_button12_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *window2;
window=lookup_widget(button,"adherent");
gtk_widget_hide(window);
window1=create_modifierinfo();
gtk_widget_show_all(window1);
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;


FILE* t1;
FILE* t2;
input1= lookup_widget(button,"entry1000");
input2= lookup_widget(button,"entry2000");
input3= lookup_widget(button,"entry3000");
input4= lookup_widget(button,"entry5000");
input5= lookup_widget(button,"entry6000");
input6= lookup_widget(button,"entry7000");
t1=fopen("/home/dhia/Projects/project3/src/profiles.txt","r");
t2=fopen("/home/dhia/Projects/project3/src/tempo.txt","r");
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
on_button14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"information");
gtk_widget_hide(window);
window1=create_adherent();
gtk_widget_show_all(window1);
}


void
on_button15_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview22;
window=lookup_widget(button,"information");
gtk_widget_hide(window);
window1=create_modifierinfo();
gtk_widget_show_all(window1);
treeview22=lookup_widget(window1,"treeview22");
afficher_rendezvous(treeview22);
}


void
on_button17_clicked                    (GtkWidget       *button,
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
GtkWidget *combobox4000;
FILE *t;
FILE *f1;
FILE *ftemp;
char a[20], b[20], c[20], d[20], e[20], f[20], g[20];
input1=lookup_widget(button,"entry1000");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"entry2000");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"entry3000");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input3)));
combobox4000=lookup_widget(button, "combobox4000");
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4000)));
input4=lookup_widget(button,"entry5000");
strcpy(e,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"entry6000");
strcpy(f,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(button,"entry7000");
strcpy(g,gtk_entry_get_text(GTK_ENTRY(input6)));
t=fopen("/home/dhia/Projects/project3/src/tempo.txt","r");
f1=fopen("/home/dhia/Projects/project3/src/profiles.txt","a+");
ftemp=fopen("/home/dhia/Projects/project3/src/temp.txt","a+");


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
remove ("/home/dhia/Projects/project3/src/profiles.txt");
rename ("/home/dhia/Projects/project3/src/temp.txt","/home/dhia/Projects/project3/src/profiles.txt");

}

void
on_button16_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"modifierinfo");
gtk_widget_hide(window);
window1=create_adherent();
gtk_widget_show_all(window1);
}


void
on_button1n_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button2n_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window= create_modifierinfo();
gtk_widget_show (window);
window1= lookup_widget(objet_graphique,"admin");
gtk_widget_hide(window1);
}

void
on_button6n_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *admin,*List_View;
GtkWidget *GestionCompte;
GestionCompte= create_GestionCompte();
admin= lookup_widget(objet_graphique,"admin");
gtk_widget_hide(admin);
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



void
on_button191_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"info");
gtk_widget_hide(window);
window1=create_annulation();
gtk_widget_show_all(window1);
}


void
on_button192_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *spinbutton4;
GtkWidget *window;
GtkWidget *window1;
spinbutton4=lookup_widget(button, "spinbutton4");
int x=0;
int num=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton4));
FILE *f1;
FILE *ftemp;
FILE *t;
f1=fopen("/home/dhia/Projects/project3/src/rendezvous.txt","r");
ftemp=fopen("/home/dhia/Projects/project3/src/temp.txt","a+");
t=fopen("/home/dhia/Projects/project3/src/tempo.txt","r");
char a[20],b[20],c[20],d[20];
fscanf(t,"%s %s %s %s \n",a,b,c,d);
char a2[20],b2[20],c2[20],d2[20],e2[20],f2[20],g2[20];
while(fscanf(f1,"%s %s %s %s %s %s %s \n",a2,b2,c2,d2,e2,f2,g2)!=EOF)
{
				if ((strcmp(d,g2))==0) {x=x+1;}
				if(num!=x)
					{
                                        fprintf(ftemp,"%s %s %s %s %s %s %s\n",a2,b2,c2,d2,e2,f2,g2);
					}
}
			
fclose(f1);
fclose(ftemp);
fclose(t);
remove ("/home/dhia/Projects/project3/src/rendezvous.txt");
rename ("/home/dhia/Projects/project3/src/temp.txt","/home/dhia/Projects/project3/src/rendezvous.txt");

window=lookup_widget(button,"annulation");
gtk_widget_hide(window);
window1=create_info();
gtk_widget_show_all(window1);
treeview1=lookup_widget(window1,"treeview1");
afficher_rendezvous(treeview1);
}



void
on_button193_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview1;
window=lookup_widget(button,"annulation");
gtk_widget_hide(window);
window1=create_info();
gtk_widget_show_all(window1);
treeview1=lookup_widget(window1,"treeview1");
afficher_rendezvous(treeview1);
}


void
on_modifierinfo_show                   (GtkWidget       *button,
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
input1= lookup_widget(button,"entry1000");
input2= lookup_widget(button,"entry2000");
input3= lookup_widget(button,"entry3000");
input4= lookup_widget(button,"entry5000");
input5= lookup_widget(button,"entry6000");
input6= lookup_widget(button,"entry7000");
t1=fopen("/home/dhia/Projects/project3/src/profiles.txt","r");
t2=fopen("/home/dhia/Projects/project3/src/tempo.txt","r");
char a2[20],b2[20],c2[20],d2[20],e2[20],f2[20],g2[20],h2[20],i2[20],a[20],b[20],c[20],d[20];
fscanf(t2,"%s %s %s %s",a,b,c,d);
int x=0;
while(fscanf(t1,"%s %s %s %s %s %s %s %s %s \n",a2,b2,c2,d2,e2,f2,g2,h2,i2)!=EOF)
{
				if(strcmp(d,i2)==0)
					{
					x=1;
                                        break;
					}

}
if (x==1){
gtk_entry_set_text(GTK_ENTRY(input1),a2);
gtk_entry_set_text(GTK_ENTRY(input2),b2);
gtk_entry_set_text(GTK_ENTRY(input3),c2);
gtk_entry_set_text(GTK_ENTRY(input4),e2);
gtk_entry_set_text(GTK_ENTRY(input5),f2);
gtk_entry_set_text(GTK_ENTRY(input6),g2);
}
else if (x==0){
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
}
fclose(t1);
fclose(t2);
}
