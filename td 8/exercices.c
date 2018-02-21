#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char *argv[])
{
    char motSaisi[100];

    printf("Veuillez entrer une chaine de caracteres (maxi 100 characteres)\n\n");
    fgets(motSaisi, sizeof motSaisi, stdin);
    //purger();
    printf("Vous avez tape : %s", motSaisi);

    int taille = strlen(motSaisi)-1;
    printf("la chaine fait %d caracteres\n\n", taille);

    estUnMot(motSaisi,taille);

        int pal=estUnPalindrome(motSaisi,0,taille);
    if(pal==1){
        printf("Le mot saisi est un palindrome :)\n\n");
    }else{
        printf("Le mot saisi n'est pas un palindrome :(\n\n");
    }
    return 0;

}




void estUnMot (char *motSaisi, int taille)
{
    int i = 0;


    while (i<taille)
    {
        if (motSaisi[i] == ' ')
        {
            printf("Ce n'est pas un mot\n\n");
            return 0;
        }
        i++;
    }

    printf("C'est un mot\n\n");

}

int estUnPalindrome (char *motSaisi, int d, int f)
{
    if (d==0 || d>f){
        return (1);
    }
    if(motSaisi[d]!=motSaisi[f]){
        return (0);
    }
    int pal=estUnPalindrome(motSaisi,d+1,f-1);
    return (pal);
}


int sontDesAnagrammes (char *motSaisi, )

   /*void purger(void)
    {
        int c;

        while ((c = getchar()) != '\n' && c != EOF)
        {}
    }*/
