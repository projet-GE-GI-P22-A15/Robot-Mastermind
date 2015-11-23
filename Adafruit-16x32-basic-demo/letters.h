#ifndef LETTERS_H_
#define LETTERS_H_

#include "matrice.h"
#include "mbed.h"

#define LETTER_POS_HAUT 0
#define LETTER_POS_BAS 	1
#define LOW 0
#define HIGH 1



/**
 * @brief Classe de création de lettres
 * @details Classe de création de lettres en modifiant la memeoire graphique de matrice.h
 *
 * position = 0 = left; = 2 = left+6; = 3 = left+12; = 4 = left+18; = 5 = left+24;
 * yPosition = 0 = haut; = 1 = bas;
 *
 * Explication de la ligne de commande ci-dessous: (Pixel+(position sur laxe des x), Pixel+(position haut ou bas), couleur * pixel 1 ou 0)
 * m->Pset(2+(position * 6),2+(yPosition * 8),color*1);
 *
 */

 class LETTERS {
 public:
	void Init();

 	char** creer1();
 	char** creer2();
 	char** creer3();
 	char** creer4();
 	char** creer5();
 	char** creer6();
 	char** creer7();
 	char** creer8();
 	char** creer9();
 	char** creer0();

 	char** creerQ();
 	char** creerW();
 	char** creerE();
 	char** creerT();
 	char** creerY();
 	char** creerR();
 	char** creerU();
 	char** creerI();
 	char** creerO();
 	char** creerP();

 	char** creerA();
 	char** creerS();
 	char** creerD();
 	char** creerF();
 	char** creerG();
 	char** creerH();
 	char** creerJ();
 	char** creerK();
 	char** creerL();

 	char** creerZ();
 	char** creerX();
 	char** creerC();
 	char** creerV();
 	char** creerB();
 	char** creerN();
 	char** creerM();
 	
private:

};

#endif /* LETTERS_H_ */
