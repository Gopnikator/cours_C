#include <stdio.h>
#include <stdlib.h>


static void purger(void)
{
    int c;


    while ((c = getchar()) != '\n' && c != EOF)
    {}
}


int main(void)
{
    char texte[255] ;
 char codage[255] ;
 long nbrdecalage  ;
 long util = 1 ;
 long i=0 ;
    printf("                          ***********************\n");
    printf("                             ******  Bonjour  ******\n");
 printf("                             ***********************\n\n\n");
 printf("Bienvenue dans le programme de cryptage et de decryptage d'une phrase\n\n");
 printf("Choisissez :\n\n");
 printf("1-Cryptage\n\n");
 printf("2-Decryptage\n\n");
 scanf("%ld", &util);
 printf("\n");
if (util == 1)
{
  printf("Bienvenue dans le programme de cryptage d'une phrase\n\n");
  printf("Choisissez votre decalage :\n\n");
  scanf("%d", &nbrdecalage);
  printf("\n");
  purger();
  printf("Saisissez votre texte\n\n");
  fgets(texte,sizeof texte ,stdin);
   for(i=0;texte[i]!='\0';codage[i] = (texte[i]+nbrdecalage)%256,i++) ;
  printf("Voici le message crypte :\n\n\t%s", codage);
  printf("\n");







}
else if (util == 2)
{
  printf("Bienvenue dans le programme de decryptage d'une phrase\n\n");
  printf("Choisissez votre decalage :\n\n");
  scanf("%d", &nbrdecalage);
  printf("\n");
  purger();
  printf("Saisissez votre texte\n");
  fgets(texte,100 ,stdin);
   for(i=0;texte[i]!='\0';codage[i] = (texte[i]-nbrdecalage)%256,i++) ;
  printf("Voici le message crypte :\n %s", codage);
  printf("\n");




}
else
{
printf("Redemarrez le programme & choisissez une option valide\n\n");
}


    system("PAUSE");
 return 0;
}
