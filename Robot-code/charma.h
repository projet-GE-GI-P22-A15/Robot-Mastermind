/*
 * charma.h
 *
 *  Created on: 2015-11-19
 *      Author: blood
 */

#ifndef CHARMA_H_
#define CHARMA_H_

#define sepO 15
#define sigO 16
#define delai_ms 2
#define HIGH 1
#define LOW 0

//Couleurs 27
#define NOIR 		0
#define INDIGO		1		//a
#define BLEU 		8		//b
#define FORET		2		//c
#define TURQUOISE	3		//d
#define CIEL		10		//e
#define VERT 		16		//f
#define CORAIL		17		//g
#define CYAN 		24		//h
#define BOURGOGNE	4		//i
#define POURPRE		5		//j
#define MAUVE		12		//k
#define VOMIT		6		//l
#define GRIS		7		//m
#define ACIER		14		//n
#define FLUO		20		//o
#define HOPITAL		21		//p
#define POUDRE		28		//q
#define ROUGE 		32		//r
#define ROSE		33		//s
#define MAGENTA 	40		//t
#define ORANGE		34		//u
#define CHAIR		35		//v
#define GOMME		42		//w
#define JAUNE 		48		//x
#define CREME		49		//y
#define BLANC 		56		//z

#define eNOIR 	0
#define eBLEU 	1
#define eVERT 	2
#define eCYAN 	3
#define eROUGE 	4
#define eROSE 	5
#define eJAUNE 	6
#define eBLANC 	7
#define eORANGE 8

void charmaEcrire(char buf[]);
void transfererChar(char c);
void transmettreEssai(int numero, char essai[]);
void transmettreMot(int yPosition, char mot[]);
void InitCouleurs();
char randomCouleur();
void afficherMot();
void afficherJeu();

extern char* couleurs;

#endif /* CHARMA_H_ */
