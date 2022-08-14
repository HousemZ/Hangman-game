#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char lire_caractere()
{
    int c=getchar();
    c=toupper(c);
    while(getchar()!='\n');
    return c;
}
