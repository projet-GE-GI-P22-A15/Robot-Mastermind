/*
 * codeLettres.h
 *
 *  Created on: 2015-11-15
 *      Author: blood
 */

#ifndef CODELETTRES_H_
#define CODELETTRES_H_

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

class CODELETTRES {
public:
	void ecrire1(int color, int position, int yPosition);
	void ecrire2(int color, int position, int yPosition);
	void ecrire3(int color, int position, int yPosition);
	void ecrire4(int color, int position, int yPosition);
	void ecrire5(int color, int position, int yPosition);
	void ecrire6(int color, int position, int yPosition);
	void ecrire7(int color, int position, int yPosition);
	void ecrire8(int color, int position, int yPosition);
	void ecrire9(int color, int position, int yPosition);
	void ecrire0(int color, int position, int yPosition);

	void ecrireQ(int color, int position, int yPosition);
	void ecrireW(int color, int position, int yPosition);
	void ecrireE(int color, int position, int yPosition);
	void ecrireR(int color, int position, int yPosition);
	void ecrireT(int color, int position, int yPosition);
	void ecrireY(int color, int position, int yPosition);
	void ecrireU(int color, int position, int yPosition);
	void ecrireI(int color, int position, int yPosition);
	void ecrireO(int color, int position, int yPosition);
	void ecrireP(int color, int position, int yPosition);
	void ecrireA(int color, int position, int yPosition);
	void ecrireS(int color, int position, int yPosition);
	void ecrireD(int color, int position, int yPosition);
	void ecrireF(int color, int position, int yPosition);
	void ecrireG(int color, int position, int yPosition);
	void ecrireH(int color, int position, int yPosition);
	void ecrireJ(int color, int position, int yPosition);
	void ecrireK(int color, int position, int yPosition);
	void ecrireL(int color, int position, int yPosition);
	void ecrireZ(int color, int position, int yPosition);
	void ecrireX(int color, int position, int yPosition);
	void ecrireC(int color, int position, int yPosition);
	void ecrireV(int color, int position, int yPosition);
	void ecrireB(int color, int position, int yPosition);
	void ecrireN(int color, int position, int yPosition);
	void ecrireM(int color, int position, int yPosition);

private:

};

#endif /* CODELETTRES_H_ */
