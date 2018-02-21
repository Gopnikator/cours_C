
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fichier.h"

/* D�claration et initialisation du chemin vers le dico utilis�, pour la g�n�ration al�atoire du mot myst�re.
Un dictionnaire en informatique est un fichier contenant un ensemble de mots stock�s ligne par ligne.
Pour r�cup�rer un mot, il suffit de lire la ligne correspondante. */
const char pathDico[] = "dico.txt";

int main() {

    /* R�cup�ration du nombre de lignes du dico */
    int nbLigne = tailleLigneFile(pathDico);
    /* R�cup�ration du 1er mot stock� dans dico (par allocation dynamique) */
    char* motMystere = chaineFile(1,pathDico);
    /* Lib�ration de la m�moire allou�e dynamiquement pour le stockage du mot myst�re */
    free(motMystere);
	
    return 0;
}