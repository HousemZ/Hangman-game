#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
int nbAlea(int nb); // Nb aleatoire
char lire_caractere();
int mot(); // nb totale des mots dans le fichier
int cur(); // positionner le curseur
int verif(char* motA,char* motC,int x); //verification  du caractere saisie
int main()
{
    int choix=0;
    do
    {
    int coup=10,x=0,r=0;
    char motaffich[30]="";
    char motcache[30]="";
    FILE* fichier=NULL;
    fichier=fopen("dict.txt","r");
    if(fichier!=NULL)
    {
    fseek(fichier,cur(),SEEK_SET);
    fgets(motaffich,30,fichier);
    motaffich[strlen(motaffich)-1]='\0';
    strcpy(motcache,motaffich);
    for(int i=0;i<strlen(motcache);i++) motcache[i]='*';
  printf("\tBienvenu,dans le jeu\n");
  printf("Il vous reste %d coups a jouer\n",coup);
  printf("Quel est le mot secret ? ");
  printf("%s\n",motcache);
  do
  {
    printf("proposer une lettre: ");
    x=lire_caractere();
    r=verif(motaffich,motcache,x);
    if(strchr(motcache,'*')==NULL)
    {
        printf("Gagne ! le mot secret etait bien %s\n",motaffich);
        break;
    }
    if(r==0)
    {
        coup--;
        printf("Il vous reste %d coups a jouer\n",coup);
    }
  }while(coup!=0);
  fclose(fichier);
    }
    printf("voulez-vous encore jouer?\n1-->Oui\n0-->Non\n");
    scanf("%d",&choix);
    }while(choix);
    return 0;
}
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
int nbAlea(int nb)
{
    srand(time(NULL));
    return(rand()% nb);
}
int verif(char* motA,char* motC,int x)
{
    int r=0;
    char* rech=NULL;
    rech=strchr(motA,x);
    if(rech!=NULL)
    {
        for(int i=0;i<strlen(motA);i++)
        {
            if(motA[i]==x) motC[i]=x;
        }
        printf("%s\n",motC);
        r=1;
    }
    return r;

}
char lire_caractere()
{
    int c=getchar();
    c=toupper(c);
    while(getchar()!='\n');
    return c;
}
