#ifndef FICHIERS_C_INCLUDED
#define FICHIERS_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "fichiers.h"
#include <string.h>

///***** Vidage Buffer *****///
void clean(const char *buffer, FILE *fp){ //Permet d'éliminer le saut de ligne
    char *p = strchr(buffer,'\n');        //après entrée clavier
    if (p != NULL){
        *p = 0;
    }else{
        int c;
        while ((c = fgetc(fp)) != '\n' && c != EOF);
    }
}

///***** Exercice1 *****///
int estUnMot (char *mot, int lgmot){
    int i = 0;
    while (i<lgmot){
        if (mot[i] == ' '){ //Test si la chaine de caractère ne compore qu'un mot
            return 0;
        }i++;
    }
    return 1;
}

///***** Exercice2 *****///
int estUnPalindrome (char *motSaisi, int d, int f){
    if (d==f || d>f){ //Vérifie lettre par lettre en partant du début et de la fin
        return (1);   //du mot et in-dé-crémente parallèlement d et f
    }
    if(motSaisi[d]!=motSaisi[f]){ //Test d'échec
        return (0);
    }
    return (estUnPalindrome(motSaisi,d+1,f-1)); //Appel reccursif
}

///***** Exercice3 *****///
int sontDesAnagrammes (char *motSaisi, char *motSaisi2, int taille, int tailleMot2){
    if (taille != tailleMot2){ //Si les mot ont des tailles différentes ce ne sont pas des anagrammes
        return 0;
    }
    if(strcmp(motSaisi,motSaisi2) == 0){ //Si les deux mots sont les mêmes ce sont des anagrammes
        return 1;
    }
    int i = 0;
    int j = 0;
    while (i<taille){
        while(j<tailleMot2){
            if (motSaisi[i]==motSaisi2[j]){
               motSaisi2[j]=' ';
               j=tailleMot2;
            }
            j++;
        }
        i++;
        j=0;
    }
    i=0;
    while (i<tailleMot2){
        if(motSaisi2[i]!=' '){
            return 0;
        }i++;
    }
    return 1;
}

///***** Exercice4 *****///
// Pour le test du mot, si 0 est retourné alors pas un mot, sinon est un mot
// Pour le test du palindrome, si 1 retourné alors est un palindrome sinon n'est pas un palindrome
void test (char *mot, int lgmot){
    if(estUnMot(mot,lgmot)==0){
        printf("\"%s\" n'est PAS un mot\n\n",mot);
    }else{
        printf("\"%s\" est un mot!\n\n",mot);
        if(estUnPalindrome(mot,0,lgmot-1)==1){
            printf("\"%s\" est un palindrome\n\n",mot);
        }else{
            printf("\"%s\" n'est PAS un palindrome\n\n",mot);
        }
    }
}

///***** Exercice5 *****///
int parametreDeuxChaines (char *nvMot, char *nvMot2, int tailleMot3, int tailleMot4){
    int i;
    int j;
    if (strcmp(nvMot2, nvMot)==0){ // Si le mot comporte les memes caractères c'est le meme mot
        printf("Le mot %s est le meme mot que %s \n\n", nvMot2, nvMot);
        return (0);
    }
    if (tailleMot4>tailleMot3){ // si le mot est plus grand, il ne peut donc pas etre inclu dans l'autre mot
        printf("Le mot %s est plus grand que le mot %s et donc ne peut pas etre inclu \n\n", nvMot2, nvMot);
        return (-1);
    }
    for (i=0; i<=tailleMot3;i++){
        j=0; // on remet l'indice j à 0 a chaque debut de boucle
        while (nvMot[j+i]==nvMot2[j]){  // on incremente l indice j de 1 tant que les lettres des 2 mots sont identiques
             j++;
            if(j==tailleMot4){ // si on atteinte la fin de la boucle, cela signifie que toutes les lettres sont identiques
                printf("Le mot %s est inclu dans %s \n\n", nvMot2, nvMot); // donc le mot est inclu dans l'autre mot
                printf("Il commence a l'indice %d\n\n", i); // i etant la position a partir de laquelle le 2eme mot commence
                return i; // on retourne donc cette position
            }
        }
    }
    printf("Le mot %s n'est pas inclu dans %s \n\n", nvMot2, nvMot); // si on sort de la boucle ou qu on y entre pas alors -->
    return (-1);                                                     // -->le mot n'est pas inclu dans l'autre
}

///***** Exercice6 *****///
int exercice6(char *mot,char *ch2,int lgmot,int lgch1,int lgch2,int indice){
    int cpt=0;
    if(lgch1>=lgch2){
        while(cpt<lgch2){
            *(mot+cpt+indice)=*(ch2+cpt);
            cpt++;
        }
        while(*(mot+cpt+indice-1)!='\0'){
            *(mot+cpt+indice)=*(mot+cpt+indice+lgch1-lgch2);
            cpt++;
        }
        return 0;
    }else{
        while((mot+lgmot-cpt+1)!=(mot+indice+lgch1)){
            *(mot+lgmot-cpt+lgch2-lgch1)=*(mot+lgmot-cpt);
            cpt++;
        }
        cpt=0;
        while(cpt<lgch2){
            *(mot+cpt+indice)=*(ch2+cpt);
            cpt++;
        }
        return 0;
    }
    return -1;
}

///***** Exercice7 *****///
int codeCesar (char *motSaisi, int tailleMot){
    int decalage;
    int i=0;
    int counter=0;
    char myChar;
    int retourA = 26;
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
            return -1;
        }
    }
	printf("donc en majuscules : %s\n\n", motSaisi);

	// on dde a l'utilisateur de saisir l'espacement entre 1 et 25 a effectuer
    do{
	    printf("Saisissez le decallage pour le code Cesar (mini 1, maxi 25)\n\n");
        scanf("%d", &decalage);printf("\n");
	}while(decalage<1 || decalage>25);

    //Si le mot est supérieur à 'Z' alors cela retourne a 'A'+ décalage
    for (i=0; i<tailleMot; i++){
        motSaisi[i]=motSaisi[i]+decalage;
        if (motSaisi[i]>90){
            motSaisi[i]=motSaisi[i]-retourA;
        }
    }
    return 0;
}





#endif // FICHIERS_C_INCLUDED
