#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int nombreDeChiffres = 0, i = 0;
    int* tab = NULL; // Ce pointeur va servir de tableau apr�s l'appel du malloc
    int max = 99;
    int min = 0;

    // On demande le nombre d'amis � l'utilisateur
    printf("Combien de chiffres voulez vous inclure dans le tableau ? ");
    scanf("%d", &nombreDeChiffres);

    if (nombreDeChiffres > 0) // Il faut qu'il ait au moins un ami (je le plains un peu sinon :p)
    {
        tab = malloc(nombreDeChiffres * sizeof(int)); // On alloue de la m�moire pour le tableau
        if (tab == NULL) // On v�rifie si l'allocation a march� ou non
        {
            exit(0);
        }


        for (i = 0 ; i < nombreDeChiffres ; i++)
        {
            *(tab+i)=rand()%(max-min)+min;
        }

        printf("\n\nle tableau est le suivant :\n");
        for (i = 0 ; i < nombreDeChiffres ; i++)
        {
            printf("%d \n", tab[i]);
        }

        // On lib�re la m�moire allou�e avec malloc, on n'en a plus besoin
        free(tab);
    }

    return 0;
}

