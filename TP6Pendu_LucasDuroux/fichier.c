#ifndef FICHIER_C_INCLUDED
#define FICHIER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
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
            /* Lecture successive des chaque chaîne du début jusqu'à la ligne noLigne*/
            int cptLine = 1;
            while(cptLine < noLigne) {
                /* Lecture successives des caractères de la ligne jusqu'à EOL */
                    while(fgetc(fichier)!='\n');
                    cptLine++;
            }
            // allocation dynamique du mot de la ligne
            // -> reallocation dynamique a chaque lettre de la ligne
            chaine = malloc(sizeof(char)*1);
            if(chaine != NULL){
                int cptCar = 0;
                char carSuiv = fgetc(fichier);
                while(carSuiv != EOF && carSuiv != '\n' && carSuiv != '\r'){
                    if(cptLine == noLigne){ // test inutile ?
                        chaine[cptCar] = carSuiv;
                        cptCar++;
                        chaine = realloc(chaine, sizeof(char)*(cptCar+1));
                        if(chaine == NULL) {
                            /* Redirection vers le flux d'erreur stderr et arrêt du programme */
                            fprintf(stderr, "Erreur re-allocation dynamique :\n - fichier %s\n - taille %d\n - caractere %d\n",pathFile, noLigne,cptCar);
                            exit(-1);
                        }
                    }
                    carSuiv = fgetc(fichier);
                }
                chaine[cptCar] = '\0';
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

#endif // FICHIER_C_INCLUDED
