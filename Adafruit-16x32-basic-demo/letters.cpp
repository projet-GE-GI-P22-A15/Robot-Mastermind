#include "letters.h"

MATRICE * m;


void LETTERS::Init(MATRICE *mat) {
	m = mat;
	alternance = LOW;
	newColor = 0;
}

int LETTERS::getAlternance(){
	return alternance;
}
void LETTERS::setAlternance(int value){
	alternance = value;
}

void LETTERS::verifParams(int * color, int * position, int * yPosition) {
	if (*position > 5)
		*position = 5;
	else if (*position < 0)
		*position = 0;
	if (*color < 0)
		*color = 0;
	else if (*color > 8)
		*color = 8;
	if (*yPosition > 2)
		*yPosition = 2;
	else if (*yPosition < 0)
		*yPosition = 1;
}

int LETTERS::verifColor(int color) {
	newColor = 0;
	if (alternance == LOW) {
		//alternance = HIGH;
	} else {
		newColor = newColor | (color & 4);
		newColor = newColor | (color & 2);
		newColor = newColor | (color & 1);
        newColor = newColor << 3;
	}
	newColor = newColor | (color & 32);
	newColor = newColor | (color & 16);
	newColor = newColor | (color & 8);
	newColor = newColor >> 3;
	return newColor;
}

void LETTERS::ecrire1(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire2(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire3(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire4(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire5(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire6(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire7(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire8(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire9(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrire0(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireQ(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireW(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireE(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireR(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireT(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireY(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireU(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireI(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireO(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireP(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireA(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireS(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireD(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireF(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireG(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireH(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireJ(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireK(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireL(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireZ(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireX(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireC(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireV(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireB(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 0);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 0);

}
void LETTERS::ecrireN(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
void LETTERS::ecrireM(int color, int xPosition, int yPosition) {

	// Condition de depassement
	color = verifColor(color);
	verifParams(&color, &xPosition, &yPosition);
	m->Pset(0 + (xPosition * 6), 0 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 0 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 0 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 1 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 1 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 1 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(2 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 2 + (yPosition * 8), color * 1);
	m->Pset(4 + (xPosition * 6), 2 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 3 + (yPosition * 8), color * 1);
	m->Pset(3 + (xPosition * 6), 3 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 3 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 4 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 4 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 4 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 5 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 5 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 5 + (yPosition * 8), color * 1);

	m->Pset(0 + (xPosition * 6), 6 + (yPosition * 8), color * 1);
	m->Pset(1 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(2 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(3 + (xPosition * 6), 6 + (yPosition * 8), color * 0);
	m->Pset(4 + (xPosition * 6), 6 + (yPosition * 8), color * 1);

}
