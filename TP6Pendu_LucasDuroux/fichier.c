#ifndef FICHIER_C_INCLUDED
#define FICHIER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

/* Fonction permettant de r�cup�rer la chaine de caract�re pr�sente � la ligne noLigne */
char* chaineFile(int noLigne,const char* pathFile) {
    /* D�claration et intialisation du pointeur qui va stocker l'adresse de la cha�ne � recup�rer */
    char* chaine = NULL;
    /* Test de coh�rence noLigne */
    if(noLigne > 0) {
        /* D�claration d'un pointeur sur FILE et initialisation � NULL */
        FILE* fichier = NULL;
        /* Tentative d'ouverture du fichier en lecture et r�cup�ration du pointeur sur FILE */
        fichier = fopen(pathFile, "r");
        /* Test de la tentative d'ouverture du fichier */
        if (fichier != NULL) {
            /* Lecture successive des chaque cha�ne du d�but jusqu'� la ligne noLigne*/
            int cptLine = 1;
            while(cptLine < noLigne) {
                /* Lecture successives des caract�res de la ligne jusqu'� EOL */
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
                            /* Redirection vers le flux d'erreur stderr et arr�t du programme */
                            fprintf(stderr, "Erreur re-allocation dynamique :\n - fichier %s\n - taille %d\n - caractere %d\n",pathFile, noLigne,cptCar);
                            exit(-1);
                        }
                    }
                    carSuiv = fgetc(fichier);
                }
                chaine[cptCar] = '\0';
            }
            else {
                /* Redirection vers le flux d'erreur stderr et arr�t du programme */
                fprintf(stderr, "Erreur allocation dynamique :\n - fichier %s\n - taille %d\n",pathFile, noLigne);
                exit(-2);
            }
            /* Fermeture du fichier en fin de traitement */
            fclose(fichier);
        }
        else {
            /* Redirection vers le flux d'erreur stderr et arr�t du programme */
            fprintf(stderr, "Erreur ouverture :\n - fichier %s\n",pathFile);
            exit(-3);
        }
    }
    else {
        /* Redirection vers le flux d'erreur stderr et arr�t du programme */
        fprintf(stderr, "Erreur noLigne = 0\n - fichier %s\n",pathFile);
        exit(-4);
    }
    /* Fin de fonction */
    return chaine;
}

/* Fonction permettant de r�cup�rer le nombre de ligne du fichier */
int tailleLigneFile(const char* pathFile) {
    /* D�claration et initialisation de la taille � calculer */
    int nbLigne = -1;
    /* D�claration d'un pointeur sur FILE et initialisation � NULL */
    FILE* fichier = NULL;
    /* Tentative d'ouverture du fichier en lecture et r�cup�ration du pointeur sur FILE */
    fichier = fopen(pathFile, "r");
    /* Test de la tentative d'ouverture du fichier */
    if (fichier != NULL) {
        /* Lecture de chaque carat�re et compteur sur '\n' */
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
        /* Redirection vers le flux d'erreur stderr et arr�t du programme */
        fprintf(stderr, "Erreur ouverture :\n- fichier %s\n",pathFile);
        exit(-5);
    }
    /* Fin de fonction */
    return nbLigne;
}

#endif // FICHIER_C_INCLUDED
