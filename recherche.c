#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int recherche(char* motA,char* motC,int x)
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
