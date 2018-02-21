
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fichier.h"

/* Déclaration et initialisation du chemin vers le dico utilisé, pour la génération aléatoire du mot mystère.
Un dictionnaire en informatique est un fichier contenant un ensemble de mots stockés ligne par ligne.
Pour récupérer un mot, il suffit de lire la ligne correspondante. */
const char pathDico[] = "dico.txt";

int main() {

    /* Récupération du nombre de lignes du dico */
    int nbLigne = tailleLigneFile(pathDico);
    /* Récupération du 1er mot stocké dans dico (par allocation dynamique) */
    char* motMystere = chaineFile(1,pathDico);
    /* Libération de la mémoire allouée dynamiquement pour le stockage du mot mystère */
    free(motMystere);
	
    return 0;
}