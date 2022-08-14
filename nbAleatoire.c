#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int nbAlea(int nb)
{
    srand(time(NULL));
    return(rand()% nb);
}
