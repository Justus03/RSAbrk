#define TAILLE 1000001

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ############### By Justus ############### */

#include "RSAbrk.h"

int main(int argc, char **argv)
{
  long long pq=0;
  int p=0,q=0;
  char chaine[TAILLE]="";

  fprintf(stdout,"Entrez pq:\n");
  fgets(chaine,TAILLE,stdin);

  if(!strchr(chaine,'\n'))
    while(getchar()!='\n');
  
  pq=atoll(chaine);

  fprintf(stdout,"pq= %lld!\n",pq);

  if(!RSAbrk(&pq,&p,&q))
    fprintf(stdout,"%lld=%d*%d\n",pq,p,q);
  else
    fprintf(stdout,"Aucun facteur n'a ete trouve pour %lld!\n",pq);
  
  return EXIT_SUCCESS;
}

