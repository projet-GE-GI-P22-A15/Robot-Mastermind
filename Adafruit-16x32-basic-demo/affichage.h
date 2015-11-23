#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include "mbed.h"
#include "letters.h"
#include "matrice.h"

class AFFICHAGE {
public:
	void Init(MATRICE* matr);
	void afficherMot(char yPosition);
	char** getLettresBas();
	char** getLettresHaut();
	char** getEtatJeu();
	void majTableauMot(char lettres[]);
	char** trouverLettre(char lettre);
	char trouverCouleur(char couleur);
	void alterner();
	char transformerCouleur(char couleurOriginale);
private:
};

#endif