#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mot()
{
FILE* fichier=NULL;
int compteur=0,n=1;
fichier=fopen("dict.txt","r");
if(fichier!=NULL)
{
    do
    {
        compteur=fgetc(fichier);
        if(compteur=='\n') n+=1;
    }while(compteur!=EOF);
}
else printf("impossible d'ouvrir le fichier");
return n;
}
