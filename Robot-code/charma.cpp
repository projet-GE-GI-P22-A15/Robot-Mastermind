/*
 * charma.cpp
 *
 *  Created on: 2015-11-19
 *      Author: blood
 */
#include <libarmus.h>
#include "charma.h"

/*Couleurs
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
 #define BLANC 		56		//z*/

int charmaEcrire(unsigned char buf[]) {
	int size = sizeof(buf);
	if (size != 13 && size != 11) {
		return -1;
	}
	if (buf[0] == '#' && buf[size - 1] == '~') {
		if (buf[1] != '1' || buf[1] != '2') {
			if (size == 13) {
				//code ecrire lettres
				//format: "#1cfcfcfcfcf~" ou c est un caractere, f est une couleur (voir matrice.h). \0 est permis. 1 peut etre remplace par 2 pour ecrire en bas.
				int i;
				for (i = 0; i < 13; ++i) {
					transfererChar(buf[i]);
				}
			} else {
				return -2;
			}
		} else if (buf[0] == '3') {
			if (size == 11) {
				//code ecrire essai
				//format: "#3eeeerrrr~" ou e est un chiffre entre 0 et 7 correspondant a une couleur et r est le feedback (0 = mauvais, 1 = mauvaise place, 2 = bon)
				int i;
				for (i = 0; i < 11; ++i) {
					transfererChar(buf[i]);
				}
			} else {
				return -3;
			}
		} else {
			return -4;
		}
	} else {
		return -5;
	}

	return 0;
}

void transfererChar(char c) {
	DIGITALIO_Write(sepO, HIGH);
	DIGITALIO_Write(sigO, HIGH);

	THREAD_MSleep(delai_ms);
	int i;

	for (i = 1; i < 129; i *= 2) {
		DIGITALIO_Write(sepO, LOW);
		if ((c & i)) {
			DIGITALIO_Write(sigO, HIGH);
		} else {
			DIGITALIO_Write(sigO, LOW);
		}
		THREAD_MSleep(delai_ms);

		if (i < 128) {
			DIGITALIO_Write(sepO, HIGH);
			DIGITALIO_Write(sigO, LOW);

		} else {
			DIGITALIO_Write(sepO, HIGH);
			DIGITALIO_Write(sigO, HIGH);
		}
		THREAD_MSleep(delai_ms);
	}
	DIGITALIO_Write(sepO, LOW);
	DIGITALIO_Write(sigO, LOW);
	THREAD_MSleep(delai_ms);
}

