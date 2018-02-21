#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char motSaisi[100];
    int taille= 0;
    char C[1];
    //char motSansCaractere[100];

    printf("Veuillez entrer une chaine de caracteres sans espace (maxi 50 characteres)\n\n");
    scanf("%s", motSaisi);
    printf("\n\nVous avez saisi %s\n\n", motSaisi);
    taille = tailleChaine(motSaisi);
    printf("la chaine fait %d caracteres\n\n", taille);


    printf("Veuillez entrer le caractere a retirer\n\n");
    scanf("%s", C);
    retirerCaractere(motSaisi, C);
    printf("Le mot sans le caractere %s est %s \n\n", C, motSaisi);


    return 0;
}

int tailleChaine (char *motSaisi)
{
    int i = 0;
    while (motSaisi[i] != '\0')
    {
        i++;

    }
    return i;
}

void retirerCaractere (char *motSaisi, char *C)

{
    int i=0;

    for (i=0 ; i < tailleChaine(motSaisi) ; i++ )
    {
        if (motSaisi[i] == C[0])
        {
            motSaisi[i] = "";
        }
        else
        {
            motSaisi[i] = C[0];
        }
    printf("%s", motSaisi);
    }

}


/* int tailleChaine (char *motSaisi)
{
    int taille = 0;
    taille = strlen(motSaisi);


    return(taille);

}
*/
