#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    char motSaisi[100];
    int decallage;
    int i=0;
    int counter=0;
    char myChar;
    int retourA = 26;

    //on demande a l'utilisateur d'entrer un mot
    printf("Veuillez entrer un mot\n\n");
    scanf("%s", motSaisi);

    int tailleMot = strlen(motSaisi);
    printf("le mot fait %d caracteres\n\n", tailleMot);

    // si le mot saisi est en minuscule, il passe en majuscule
    while (motSaisi[counter]){
		myChar=motSaisi[counter];
		motSaisi[counter]=toupper(myChar);
		counter++;
	}

    // Si le mot en maj n'est pas compose que de lettres en majuscules, alors non valide
	for (i=0; i<tailleMot; i++){
        if(motSaisi[i]<65||motSaisi[i]>90){
            printf("non valide\n\n");
            return 0;
        }
    }
	printf("donc en majuscules : %s\n\n", motSaisi);

	// on dde a l'utilisateur de saisir l'espacement a effectuer
	printf("Saisissez le decallage \n\n");
    scanf("%d", &decallage);

    //Si le mot est supérieur à 'Z' alors cela retourne a 'A'+ decallage
    for (i=0; i<tailleMot; i++){
        motSaisi[i]=motSaisi[i]+decallage;
        if (motSaisi[i]>90){
            motSaisi[i]=motSaisi[i]-retourA;
        }
    }

    // On affiche le nouveau mot code
    printf("%s\n\n", motSaisi);
}
