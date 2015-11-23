/*
 * charma.cpp
 *
 *  Created on: 2015-11-19
 *      Author: blood
 */
#include <libarmus.h>
#include "charma.h"



void transmettreEssai(int numero, char essai[9]) {
	if (numero < 1 || numero > 10) {
		LCD_Printf("Valeur d'essai invalide\n");
	} else {
		char message[13];
		message[0] = '#';
		message[1] = '3';
		message[2] = numero + 48;
		message[3] = essai[0];
		message[4] = essai[1];
		message[5] = essai[2];
		message[6] = essai[3];
		message[7] = essai[4];
		message[8] = essai[5];
		message[9] = essai[6];
		message[10] = essai[7];
		message[11] = '~';
		message[12] = '\0';
		charmaEcrire(message);
	}
}

void transmettreMot(int yPosition, char mot[11]) {
	if (yPosition < 1 || yPosition > 2) {
		LCD_Printf("Position Y invalide\n");
	} else {
		char message[14];
		message[0] = '#';
		message[1] = yPosition + 48;
		message[2] = mot[0];
		message[3] = mot[1];
		message[4] = mot[2];
		message[5] = mot[3];
		message[6] = mot[4];
		message[7] = mot[5];
		message[8] = mot[6];
		message[9] = mot[7];
		message[10] = mot[8];
		message[11] = mot[9];
		message[12] = '~';
		message[13] = '\0';
		charmaEcrire(message);
	}
}

void charmaEcrire(char buf[]) {
	int i;
	for (i = 0; buf[i] != '~' && i < 63; ++i) {

	}
	int size = i + 1;

	if (buf[0] == '#' && buf[size - 1] == '~') {
		//code ecrire lettres
		//format lettres: "_1cccccfffff~" ou c est un caractere, f est une couleur (voir matrice.h). \0 est permis. 1 peut etre remplace par 2 pour ecrire en bas.
		//format essai: _3#RGBRvfvf~ ou # est le numero de l<essai
		LCD_Printf("Start Comm\n");
		//Debut Comm
		DIGITALIO_Write(sepO, HIGH);
		DIGITALIO_Write(sigO, HIGH);
		THREAD_MSleep(delai_ms);

		//ecrire caracteres un par un
		int i;
		for (i = 0; i < size; ++i) {
			transfererChar(buf[i]);
		}
		//Fin Comm
		DIGITALIO_Write(sepO, LOW);
		DIGITALIO_Write(sigO, LOW);
		THREAD_MSleep(500);

		LCD_Printf("End Comm\n");
	} else {
		LCD_Printf("%sU\n", buf);
	}
}

void transfererChar(char c) {
	int i;
	for (i = 1; i < 129; i *= 2) {
		//ecrire un bit
		DIGITALIO_Write(sepO, LOW);
		if ((c & i)) {
			DIGITALIO_Write(sigO, HIGH);
		} else {
			DIGITALIO_Write(sigO, LOW);
		}
		THREAD_MSleep(delai_ms);

		//ecrire une separation de bits
		DIGITALIO_Write(sepO, HIGH);
		if (i < 128) {
			DIGITALIO_Write(sigO, LOW);
		} else {
			DIGITALIO_Write(sigO, HIGH);
		}
		THREAD_MSleep(delai_ms);
	}
}

