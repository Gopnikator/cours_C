#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

void clean(const char *buffer, FILE *fp);

int estUnMot (char *mot, int lgmot);

int estUnPalindrome (char *motSaisi, int d, int f);

int sontDesAnagrammes (char *motSaisi, char *motSaisi2, int taille, int tailleMot2);

int parametreDeuxChaines (char *nvMot, char *nvMot2, int tailleMot3, int tailleMot4);

int exercice6(char *mot,char *ch2,int lgmot,int lgch1,int lgch2,int indice);

int codeCesar (char *motSaisi,int tailleMot);

#endif // FICHIERS_H_INCLUDED
