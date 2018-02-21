// Ecrit par Lucas Duroux, version du 10/10/17
#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS

//Prototypes
char DemandeLettre();
void DemandeMot(char *mot);
int EstDejaDonne(char lettre, char *lettreDejaDonne, int sizeTab);
void RempliMotMystereCache(char motCache[], int longMot);
int IsLettreDansMot( char lettre, const char motMystere[], int longMot);
int IsMotFound(char lettre, char motMystere[], char motCache[], int longMot);

#endif
