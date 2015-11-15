#ifndef LETTERS_H
#define LETTERS_H

#include "matrice.h"
#include "mbed.h"

#define LETTER_POS_HAUT 0
#define LETTER_POS_BAS 	1


/**
 * @brief Classe de création de lettres
 * @details Classe de création de lettres en modifiant la memeoire graphique de matrice.h
 * 
 * position = 0 = left; = 2 = left+6; = 3 = left+12; = 4 = left+18; = 5 = left+24;
 * yPosition = 0 = haut; = 1 = bas;
 * 
 * Explication de la ligne de commande ci-dessous: (Pixel+(position sur laxe des x), Pixel+(position haut ou bas), couleur * pixel 1 ou 0)
 * m.Pset(2+(position * 6),2+(yPosition * 8),color*1);
 * 
 */

class LETTERS {
public:
	void Init(MATRICE *mat);
	void chiffre0(int color, int position, int yPosition);
	void chiffre2(int color, int position, int yPosition);
	void chiffre4(int color, int position, int yPosition);
	
private:

};

#endif