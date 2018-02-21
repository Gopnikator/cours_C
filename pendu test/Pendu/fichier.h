#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

char* chaineFile(int noLigne,const char* pathFile);

int tailleLigneFile(const char* pathFile);

int difficulte ();

int motChar();

int chara(char *motMystere, char *tabUnderscores);

int mot(char *motMystere, char *motTente);

void afficherPendu ();

void afficherVictory ();

void victoireDefaite (char *motMystere, int *nbVies);

int recommencerPartie (int *recommencer);

int cptVies (int nbVies);


#endif // FICHIER_H_INCLUDED
