// Ecrit par Lucas Duroux, version du 10/10/17

/* Ce programme propose a un utilisateur de trouver un mot present dans le fichier dico.txt avec un nombre de vie (fixé dans la constante nbVie)
 * Le mot est cache et l on affiche seulement des '_' à la place de chaque lettre
 * On propose a l'utilisateur de chercher par lettre ou de proposer directement un mot a chaque etape
 *  1) il propose une lettre, on verifie dans le mot si elle presente:
 *      a) si elle n est pas presente : l'utilisateur perd une vie et on verifie si le nombre de vie n atteind pas 0 auquel cas c est perdu
 *      b) si elle est presente: on dévoile la lettre et on vérifie si tout le mot a ete trouve auquel cas c est gagne
 *  2) il propose un mot, soit il a gagne, soit il perd une vie et on verifie si le nombre de vie n atteind pas 0 auquel cas c est perdu
 * On stock toutes les lettres proposees par l utilisateur afin de les afficher et l utilisateur ne perd pas de vie en proposant une lettre deja proposee
 */
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "fichier.h"
#include <string.h>
#include <time.h>

const int nbVie=10; // nb erreur autorisee
// etant donne que je suis sur le terminal Linux, j ai enleve tout les mots accentues du dictionnaire 
const char pathDico[] = "dico.txt";

int main()
{
    srand(time(NULL));
    //recupere le mot mystere dans le dictionnaire
    int nbLigne = tailleLigneFile(pathDico);
    int numeroLigne= (rand() % nbLigne) +1;
    char *motMystere=chaineFile( numeroLigne, pathDico);

    //creer le mot mystere avec lettres cachees
    int longMot=strlen(motMystere);
    char motCache[longMot+1];
    RempliMotMystereCache( motCache, longMot);
    printf("Mot mystere: %s (en %d lettres)\n", motCache, longMot);

    int isFound=0; // indique si le mot a ete trouve
    int nbVieRestante = nbVie;
    char lettreDejaDonne[100]=""; //lettre(s) deja proposee(s)
    do {
        char lettre;
        int choix=0;
        printf("Tu veux proposer une lettre(!2) ou un mot(2)? ");
        scanf("%i", &choix);
        while(getchar()!='\n'); // cleaning input
        // l utilisateur propose une lettre
        if (choix !=2) {
            lettre=DemandeLettre();

            // on rempli le tableau des lettres déjà utilisées
            int isLettreAlreadyGiven = EstDejaDonne( lettre, lettreDejaDonne, 100);
            if (!isLettreAlreadyGiven) {

                //regarde si la lettre proposee est dans le mot
                int isLettreMot = IsLettreDansMot( lettre, motMystere, longMot);

                // si l utilisateur a trouve une lettre alors on revele la lettre dans le mot cache 
                // et on regarde si le mot en entier a ete trouve
                if (isLettreMot) {
                    // cherche si le mot complet a ete trouve et decouvre les lettres dans motCache
                    isFound=IsMotFound( lettre, motMystere, motCache, longMot);
                    printf("Vrai!\t");
                } else { // si la lettre n est pas bonne alors le nombre de vie baisse
                    nbVieRestante--;
                    printf("Faux!\t");
                }
                printf("Vies restantes: %d\t", nbVieRestante);
                printf("Lettres utilisees: %s\n", lettreDejaDonne);
                printf("Mot mystere: %s (en %d lettres)\n", motCache, longMot);
            } else {
                printf("Tu as deja propose ces lettres: %s \n", lettreDejaDonne);
            }
        } else { // l utilisateur propose un mot
            //demande mot
            char mot[100]="";
            DemandeMot( mot);

            // si c est le bon mot termine, sinon continue le jeu
            if ( !strcmp( mot, motMystere) ) {
                isFound=1;
            } else {
                nbVieRestante--;
                printf("Faux!\t");
                printf("Vies restantes: %d\t", nbVieRestante);
                printf("Lettres utilisees: %s\n", lettreDejaDonne);
                printf("Mot mystere: %s (en %d lettres)\n", motCache, longMot);
            }
        }
    }while(!isFound && nbVieRestante>0); // on recommence tant qu on a des vies et que le mot n a pas ete trouve

    if (isFound) {
        printf("\nTrouve avec %d/%d vie(s) restante(s)!\n", nbVieRestante, nbVie);
    } else{
        printf("\nPerdu! Le mot mystere etait %s.\n", motMystere);
    }

    free(motMystere);
    return 0;
}

