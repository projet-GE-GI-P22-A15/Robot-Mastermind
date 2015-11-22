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

void charmaEcrire(char buf[]);
void transfererChar(char c);
void transmettreEssai(int numero, char essai[]);
void transmettreMot(int yPosition, char mot[]);

#endif /* CHARMA_H_ */
