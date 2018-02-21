// Ecrit par Lucas Duroux, version du 10/10/17
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <string.h>
#include <ctype.h>

// demande une lettre a l'utilisateur tant qu'elle n est pas dans l alphabet [a-z]
// retourne cette lettre
char DemandeLettre() {
    char lettre;
    printf("# Lettre ? ");
    scanf("%c", &lettre);
    while(getchar()!='\n'); // cleaning input
    lettre=tolower(lettre);
    //ask again until it s an alphabetical letter
    char alpha[]="abcdefghijklmnopqrstuvwxyz";
    while( strchr(alpha, lettre) == NULL ) {
        printf("La lettre doit etre une lettre de l alphabet. Lettre ? ");
        scanf("%c", &lettre);
        while(getchar()!='\n'); //cleaning input
        lettre=tolower(lettre);
    }
    return(lettre);
}

// demande une mot a l'utilisateur
// retourne ce mot
void DemandeMot(char *mot) {
    printf("# Mot ? ");
    scanf("%s", mot);
    while(getchar()!='\n'); // cleaning input
    *mot=tolower(*mot);
}

// verifie si la lettre a deja ete proposee, si non elle rempli le tableau des lettres deja donnees en conséquence
// retourne 1 si la lettre a deja ete proposee, sinon 0
int EstDejaDonne(char lettre, char *lettreDejaDonne, int sizeTab) {
    int isLettreAlreadyGiven=0;
    int i=0;
    while( i<sizeTab && lettreDejaDonne[i]!='\0') {
        if (lettreDejaDonne[i]==lettre) {
            isLettreAlreadyGiven=1;
        }
        i++;
    } 
    // si non deja donne, on ajoute la lettre au tableau qui repertorie les lettres deja donnee
    if (!isLettreAlreadyGiven) {
        lettreDejaDonne[i]=lettre;
        lettreDejaDonne[i+1]='\0';
    }
    return(isLettreAlreadyGiven);
}

// remplie le mot mystere cache avec des char '_'
void RempliMotMystereCache(char motCache[], int longMot )
{
    int i=0;
    for (i = 0; i < longMot; i++) {
        motCache[i]='_';
    }
    motCache[longMot]='\0';
}

// retourne 1 si la lettre proposee est bien dans le mot mystere, 0 sinon
int IsLettreDansMot( char lettre, const char motMystere[], int longMot) {
    int isLettreMot=0;
    int i=0;
    // si la lettre fait partie du mot alors elle est trouvee
    while ( i<longMot && !isLettreMot) {
        if ( motMystere[i]==lettre) {
            isLettreMot=1;
        }
        i++;
    }
    return isLettreMot;
}

// cherche si le mot complet a ete trouve et decouvre les lettres dans motCache
// retourne 1 si le mot a ete trouvee, 0 sinon
int IsMotFound(char lettre, char motMystere[], char motCache[], int longMot) {
    int isFound=1;
    int i=0;
    for (i = 0; i < longMot ; i++) {
        if(motMystere[i]==lettre){
            motCache[i]=lettre;
        }
        if(motCache[i]=='_') {
            isFound=0;
        }
    }
    return isFound;
}
