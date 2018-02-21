// Jeu du pendu, auteur : Alexandre Arnaud

/* règles du jeu du pendu: l utilisateur doit choisir un niveau de difficulte lui donnant un certain nb de vies
Le programme va trouver un mot aleatoire dans le dictionnaire en .txt
Ce mot reste le meme tout au long de la partie mais change a chaque nouvelle partie
a chaque tour, l utilisateur se voit proposer le choix entre deviner le mot ou un caractere du mot
le but du jeu est de deviner le mot.
La partie se termine de la facon suivante : soit l utilisateur a trouve tous les caracteres, soit il a trouve le mot exact,
soit il ne possede plus de vie

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fichier.h"

const char pathDico[] = "dico.txt";


int main(int argc, char *argv[])
{

// declaration de toutes les variables
    int tailleMot = 1;
    char motTente[40];
    int nbVies = 0;
    int recommencer = 0;
    int pendu = 0;




do{ // boucle pour relancer le jeu
    printf("\nBIENVENUE DANS LE JEU DU PENDU`\n\n");


    nbVies = difficulte(); // la 1ere fonction demande a l utilisateur de definir un niveau de difficulte donnant droit a un certain nb de vies


    printf("\nLe niveau choisi vous donne %d vies\n\n", nbVies);


// pour trouver un mot aleatoire du dictionnaire
    srand(time(NULL));
    int nbLigne = tailleLigneFile(pathDico);


    int i = 0;
    int a = (rand()%nbLigne)+rand();
    char* motMystere = chaineFile(a,pathDico);
    tailleMot = strlen(motMystere); // pour trouver la taille du mot afin d'insérer le bon nb de _ _ _ _
    printf("\nLe mot a trouver fait %d caracteres :\n", tailleMot);
    //printf("%s\n", motMystere); //pour vérifier le mot mystere enlever les premiers // (actuellement non visible par l utilisateur)

    char tabUnderscores[40]; // car mot francais le plus long = 39 characteres


    for (i = 0; i < tailleMot; i++) // cree un tableau de underscore de la meme taille que le mot
    {
        tabUnderscores[i] = '_';
    }


    tabUnderscores[i] = '\0';
    printf("%s\n", tabUnderscores); // permet d afficher le tableau d underscore avec le nombre de caracteres desire
    // ces caracteres seront par la suite remplaces par des lettres si l utilisateur choisit le mode caractere

    do{ // effectue la boucle de choix de mot tant que le joueur n a pas epuise toutes ses vies ou trouve le motMystere
      switch (motChar())
    {
        case 1: // Cela appelle la fonction pour deviner le mot entier.
            if (!mot(motMystere, motTente))
            {
                nbVies = cptVies(nbVies); // appel de la fonction pour decrementer le nb de vies
            }

            break;

        case 2: // appel de la fonction pour deviner un caractere
            if (!chara(motMystere, tabUnderscores))
            {
                nbVies = cptVies(nbVies); // appel de la fonction pour decrementer le nb de vies
            }
            else
            {
                printf(tabUnderscores); // met a jour avec le tableau de underscore avec les lettres trouvees par le joueur
            }

            break;

    }
    }while (strcmp(motTente, motMystere) != 0 && nbVies > 0 && strcmp(tabUnderscores, motMystere) != 0);


    victoireDefaite(motMystere, nbVies); // appel de la fonction permettant d afficher les message de victoire ou defaite


}while (recommencerPartie(recommencer) == 1); // si l utilisateur n a pas selectionne 1 le jeu s arrete


    return 0;
}





