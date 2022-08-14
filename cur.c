#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"saisie.h"
int cur()
{
    int m=0, s=mot();
    int x=nbAlea(s);
    FILE* fichier=NULL;
    int compteur=0;
    fichier=fopen("dict.txt","r");
    if(fichier!=NULL)
    {
        rewind(fichier);
    do
    {
        compteur=fgetc(fichier);
        if(compteur=='\n') x--;
    }while(x!=1);
    m=ftell(fichier);
    fclose(fichier);
    }
    return m;
}
