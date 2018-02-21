/* TD n°8 réalisé par Arnaud Alexandre et Besnard Corentin */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichiers.h"
#include <time.h>

int main(){
    char mot [50];
    char mot2 [50];
    char mot3 [50];
    char ch1 [50];
    char ch2 [50];
    printf("Veuillez entrer une premiere chaine de caracteres\n\n");
    fgets(mot, sizeof(mot), stdin);printf("\n");
    clean(mot,stdin);
    int lgmot=strlen(mot);

    test(mot,lgmot);

    printf("Veuillez entrer un second mot\n\n");
    fgets(mot2, sizeof(mot2), stdin);printf("\n");
    clean(mot2,stdin);
    int lgmot2=strlen(mot2);

    test(mot2,lgmot2);

    if(sontDesAnagrammes(mot, mot2, lgmot, lgmot2)==1){
        printf("Les deux mots sont des anagrammes\n\n");
    }else{
        printf("Les deux mots ne sont pas des anagrammes\n\n");
    }

    printf("\n--A partir de maintenant, on utilisera le 1er mot--\n\n");
    printf("Veuillez entrer une chaine de caracteres (inclus dans le mot1 ?)\n\n");
    fgets(ch1, sizeof(ch1), stdin);printf("\n");
    clean(ch1,stdin);
    int lgch1=strlen(ch1);
    int indice = parametreDeuxChaines(mot, ch1, lgmot, lgch1);
    if(indice>=0){
        printf("Veuillez entrer une seconde chaine de caracteres\n   (en substitution de la chaine1)\n\n");
        fgets(ch2, sizeof(ch2), stdin);printf("\n");
        clean(ch2,stdin);
        int lgch2=strlen(ch2);
        if(exercice6(mot, ch2, lgmot, lgch1, lgch2,indice)==0){
            printf("Le nouveau mot est %s ",mot);
        }else{
            printf("Le mot n'est pas changé : %s ",mot);
        }
    }

    // Il est necessaire de recalculer la taille du mot car elle peut etre differente apres transformation
    int lgmot3=strlen(mot);

    if(codeCesar(mot,lgmot3)==0){
        printf("Le nouveau mot est : %s\n\n",mot);
    }else{
        printf("Le code n'a pas marche\n\n");
    }
}
