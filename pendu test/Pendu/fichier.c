#ifndef FICHIER_C_INCLUDED
#define FICHIER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

/* Fonction permettant de récupérer la chaine de caractère présente à la ligne noLigne */
char* chaineFile(int noLigne,const char* pathFile) {
    /* Déclaration et intialisation du pointeur qui va stocker l'adresse de la chaîne à recupérer */
    char* chaine = NULL;
    /* Test de cohérence noLigne */
    if(noLigne > 0) {
        /* Déclaration d'un pointeur sur FILE et initialisation à NULL */
        FILE* fichier = NULL;
        /* Tentative d'ouverture du fichier en lecture et récupération du pointeur sur FILE */
        fichier = fopen(pathFile, "r");
        /* Test de la tentative d'ouverture du fichier */
        if (fichier != NULL) {
            /* Lecture successive des chaque chaîne du début jusu'à la ligne noLigne*/
            int cptLine = 0;
            chaine = malloc(sizeof(char)*1);
            if(chaine != NULL){
                int cptCar = 0;
                while(cptLine < noLigne) {
                    /* Lecture successives des caractères du fichier */
                    char carSuiv = 'a';
                    while(carSuiv != EOF && carSuiv != '\n'){
                        carSuiv = fgetc(fichier);
                        if(cptLine == noLigne-1){
                            chaine = realloc(chaine, sizeof(char)*(cptCar+1));
                            if(chaine != NULL) {
                                chaine[cptCar] = carSuiv;
                                cptCar++;
                            }
                            else {
                                 /* Redirection vers le flux d'erreur stderr et arrêt du programme */
                                fprintf(stderr, "Erreur re-allocation dynamique :\n - fichier %s\n - taille %d\n - caractere %d\n",pathFile, noLigne,cptCar);
                                exit(-1);
                            }
                        }
                    }
                    cptLine ++;
                }
                chaine[cptCar-1] = '\0';
            }
            else {
                /* Redirection vers le flux d'erreur stderr et arrêt du programme */
                fprintf(stderr, "Erreur allocation dynamique :\n - fichier %s\n - taille %d\n",pathFile, noLigne);
                exit(-2);
            }
            /* Fermeture du fichier en fin de traitement */
            fclose(fichier);
        }
        else {
            /* Redirection vers le flux d'erreur stderr et arrêt du programme */
            fprintf(stderr, "Erreur ouverture :\n - fichier %s\n",pathFile);
            exit(-3);
        }
    }
    else {
        /* Redirection vers le flux d'erreur stderr et arrêt du programme */
        fprintf(stderr, "Erreur noLigne = 0\n - fichier %s\n",pathFile);
        exit(-4);
    }
    /* Fin de fonction */
    return chaine;
}

/* Fonction permettant de récupérer le nombre de ligne du fichier */
int tailleLigneFile(const char* pathFile) {
    /* Déclaration et initialisation de la taille à calculer */
    int nbLigne = -1;
    /* Déclaration d'un pointeur sur FILE et initialisation à NULL */
    FILE* fichier = NULL;
    /* Tentative d'ouverture du fichier en lecture et récupération du pointeur sur FILE */
    fichier = fopen(pathFile, "r");
    /* Test de la tentative d'ouverture du fichier */
    if (fichier != NULL) {
        /* Lecture de chaque caratère et compteur sur '\n' */
        char carSuiv = 'a';
        while(carSuiv != EOF){
            if(carSuiv == '\n') {
                nbLigne++;
            }
            carSuiv = fgetc(fichier);
        }
        nbLigne = nbLigne + 2;
        /* Fermeture du fichier en fin de traitement */
        fclose(fichier);
    }
    else {
        /* Redirection vers le flux d'erreur stderr et arrêt du programme */
        fprintf(stderr, "Erreur ouverture :\n- fichier %s\n",pathFile);
        exit(-5);
    }
    /* Fin de fonction */
    return nbLigne;
}

// AJOUT DE MES FONCTIONS

int motChar() // pour donner le choix a l'utilisateur entre un mot et un charactere. La fonction debouche sur un switch dans la main
{
    int choix = 0;

    while (choix < 1 || choix > 2) // choix doit obligatoirement etre 1 ou 2 sinon on redemande
    {
        // on affiche les instructions et demande a l utilisateur de choisir entre 1 ou 2
        printf("\n\nFaites votre choix :\n");
        printf("1 : mot\n");
        printf("2 : charactere\n\n");
        scanf("%d", &choix);
        while(getchar()!='\n'); // pour nettoyer le buffer
    }

    return choix; // le choix de l utilisateur est retourne dans la fonction main
}

int difficulte () // Cette fonction demande à l'utilisateur de choisir un niveau de difficulté qui decidera du nb de vies
{
    int nivDiff = 0;
    int vies = 0;

    do // boucle enclanchant le choix allant etre definit par l utilisateur
    {
        printf("\nveuillez entrer un niveau de difficulte entre 1 et 3\n");
        printf("\nNiveau 1 : 15 vies\n");
        printf("Niveau 2 : 10 vies\n");
        printf("Niveau 3 : 5 vies\n\n");
        scanf("%d", &nivDiff);
        while(getchar()!='\n'); // pour nettoyer le buffer
        if (nivDiff == 1)
        {
            vies = 15;
        }
        else if (nivDiff == 2)
        {
            vies = 10;
        }
        else
        {
            vies = 5;
        }
    }while (nivDiff != 1 && nivDiff != 2 && nivDiff != 3); // obligation de rentrer 1, 2 ou 3
    return vies; // le nb de vies est retourne dans la fonction main

}



int mot(char *motMystere, char *motTente) // l utilisateur entre un mot et la fonction strcmp permet de comparer avec le motMystere
{
    printf("\nVeuillez entrer un mot\n\n");
    scanf("%s", motTente);
    while(getchar()!='\n'); // pour nettoyer le buffer
    if (strcmp(motTente, motMystere) == 0) // Si chaînes identiques l utilisateur a gagne
    {
        return 1;
    }

    return 0; // si l utilisateur a gagne, 1 est retourne, si il a perdu, 0 est retourne dans la main

}



int chara(char *motMystere, char *tabUnderscores) // l utilisateur entre un caractere.
{
    int i = 0;
    char lettre;
    int retour = 0; // egalement possible de ne pas initialiser un retour en faisant comme pour la fonction mot

    // On demande une lettre a l utilisateur :

    printf("\nVeuillez entrez une lettre\n\n");
    scanf("%c", &lettre);
    while(getchar()!='\n'); // pour nettoyer le buffer


    for (i = 0 ; i < strlen(motMystere) ; i++) // on parcourt le motMystere et compare les valeurs 1 a 1.
    {
        if (lettre == motMystere[i])
        {
            tabUnderscores[i] = lettre; // si on trouve la lettre, alors le underscore du tabUnderscore correspondant est remplace par la lettre trouvee
            retour = 1;
        }

    }


    return retour;

}

void victoireDefaite (char *motMystere, int *nbVies) // cette fonction definit le message de defaite et permet d entrer dans le message victoire si il est atteint
{
    if (nbVies == 0) // si le nbVies atteint 0 l utilisateur a perdu et peut choisir de recommencer
    {
    printf("\nvous avez perdu\n\n");
    printf("le mot a trouver etait : %s\n", motMystere);
    afficherPendu(); // on lance la fonction pour afficher le dessin du pendu lorsque le joueur a perdu
    }
    else
    {
        printf("\n\n VOUS AVEZ GAGNE !!!!!\n\n");
        afficherVictory();// on lance la fonction pour afficher le dessin de la main lorsque le joueur a gagne
    }

}

int recommencerPartie (int *recommencer) // Cette fonction permet de recommencer lors de l appui sur la touche 1
{
    printf("\nTappez 1 pour recommencer une partie, n importe quelle autre touche pour terminer le jeu\n");
    scanf("%d", &recommencer);
    while(getchar()!='\n'); // pour nettoyer le buffer
    return recommencer; // retourne la valeur de recommencer dans la main
}


int cptVies (int nbVies) // il s'agit d un compteur de vie diminuant a chaque mauvais essai et affichant le nb de vies restantes
{
       nbVies--; // permet de decrementer le nb de vies
       printf("\nMauvaise reponse\n");
       printf("Il vous reste %d vies\n", nbVies);
       return nbVies; // retourne le nouveau nb de vies

}

void afficherPendu()
{
    printf("   ,==========Y===\n");
    printf("   ||  /      |\n");
    printf("   || /       |\n");
    printf("   ||/        O\n");
    printf("   ||        /|\ \n" );
    printf("   ||        /|\n");
    printf("   ||\n");
    printf("  /||\n");
    printf(" //||\n");
    printf("============____________________________\n");
}


/* Fonction a implementer + tard pour implementer le pendu a chaque etape

void afficherPendu(int *pendu)
{
    if (pendu == 1)
    {


            printf("   ||       \n");
            printf("   ||        \n");
            printf("   ||        \n");
            printf("   ||         \n" );
            printf("   ||        n");
            printf("   ||\n");
            printf("  /||\n");
            printf(" //||\n");
            printf("============____________________________\n");
    }
    if (pendu == 2)
    {
            printf("   ,==========Y===\n");
            printf("   ||         \n");
            printf("   ||         \n");
            printf("   ||         \n");
            printf("   ||         \n" );
            printf("   ||         \n");
            printf("   ||\n");
            printf("  /||\n");
            printf(" //||\n");
            printf("============____________________________\n");
    }
    if (pendu == 3)
    {
            printf("   ,==========Y===\n");
            printf("   ||  /      |\n");
            printf("   || /       |\n");
            printf("   ||/         \n");
            printf("   ||          \n" );
            printf("   ||          \n");
            printf("   ||\n");
            printf("  /||\n");
            printf(" //||\n");
            printf("============____________________________\n");
    }
    if (pendu == 4)
    {
            printf("   ,==========Y===\n");
            printf("   ||  /      |\n");
            printf("   || /       |\n");
            printf("   ||/        O\n");
            printf("   ||        /|\ \n" );
            printf("   ||        /|\n");
            printf("   ||\n");
            printf("  /||\n");
            printf(" //||\n");
            printf("============____________________________\n");
    }
    if (pendu == 5)
    {
            printf("   ,==========Y===\n");
            printf("   ||  /      |\n");
            printf("   || /       |\n");
            printf("   ||/        O\n");
            printf("   ||        /|\ \n" );
            printf("   ||        /|\n");
            printf("   ||\n");
            printf("  /||\n");
            printf(" //||\n");
            printf("============____________________________\n");
    }
}

*/
void afficherVictory ()
{
    printf("             ");
    printf("    .-.  _ \n"  );
    printf("    | | / ) \n" );
    printf("    | |/ / \n"  );
    printf("   _|__ /_ \n"  );
    printf("  / __)-' ) \n" );
    printf("  \  `(.-') \n" );
    printf("   > ._>-' \n"  );
    printf("  / \/ \n"      );
}
#endif // FICHIER_C_INCLUDED
