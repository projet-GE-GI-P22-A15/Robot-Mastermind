#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include "mbed.h"
#include "letters.h"
#include "matrice.h"

class AFFICHAGE {
public:
	AFFICHAGE(MATRICE *matr);
	void rafraichirJeu();
	void majMatrice(char* lettres);
	void majJeu(char* lettres);
	void majLettresHaut(char* lettres);
	void majLettresBas(char* lettres);
	void rafraichirMatrice();
	char** getLettresBas();
	char** getLettresHaut();
	char** getEtatJeu();
	char** trouverLettre(char lettre);
	
	void alterner();
	char transformerCouleur(char couleurOriginale);
	//char trouverCouleur(char couleur);
private:
};

#endif