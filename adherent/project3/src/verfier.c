#include <stdio.h>
#include <string.h>
#include <verfier.h>

int verifier (char Username[], char Password[])
{
FILE*f;
char login1[20];char password1[20];
int espace;int c=-1,id;

f=fopen("/home/dhia/Projects/project3/src/users.txt","r");
if(f !=NULL) {
while(fscanf(f,"%s %s %d %d\n",login1,password1,&espace,&id)!=EOF)
	{
		if ( strcmp(Username, login1)== 0)
		{
			if ( strcmp(Password, password1)== 0)
			{
				c=espace;
              		}
		}
	}
}

fclose(f);
return c;
}


