#include <matrixLED.h>
#include <libarmus.h>
#include "valeurs.h"
#include <stdlib.h>
#include <stdio.h>

//CODE DE MATRICE ICI

void afficheMatrixDEL() {
	// A voir si recois un tableau mais bon, affiche les couleurs sur la matrix de del
}

int formatTableauMatrix() {
	// A voir comment utiliser cette fonction

	return 1;
}

int** creerLettre1() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 1;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre2() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre3() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre4() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre5() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre6() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre7() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre8() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre9() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettre0() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreQ() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 1;
	tab[5][2] = 1;
	tab[5][3] = 1;
	tab[5][4] = 0;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreW() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 1;
	tab[5][2] = 1;
	tab[5][3] = 1;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreE() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreR() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 1;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreT() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 1;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 1;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 1;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 1;
	tab[6][3] = 0;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreY() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 1;
	tab[2][2] = 0;
	tab[2][3] = 1;
	tab[2][4] = 0;
	tab[3][0] = 0;
	tab[3][1] = 1;
	tab[3][2] = 0;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 1;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 1;
	tab[6][3] = 0;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreU() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreI() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 1;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 1;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 1;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreO() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreP() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreA() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 0;
	tab[0][2] = 1;
	tab[0][3] = 0;
	tab[0][4] = 0;
	tab[1][0] = 0;
	tab[1][1] = 1;
	tab[1][2] = 0;
	tab[1][3] = 1;
	tab[1][4] = 0;
	tab[2][0] = 0;
	tab[2][1] = 1;
	tab[2][2] = 0;
	tab[2][3] = 1;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 1;
	tab[4][2] = 1;
	tab[4][3] = 1;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreS() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 1;
	tab[1][3] = 1;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 0;
	tab[5][1] = 1;
	tab[5][2] = 1;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreD() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreF() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreG() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreH() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreJ() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreK() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 1;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 1;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 1;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 1;
	tab[5][3] = 1;
	tab[5][4] = 0;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreL() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 0;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreZ() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 1;
	tab[2][4] = 1;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 0;
	tab[4][1] = 1;
	tab[4][2] = 1;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 1;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreX() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 0;
	tab[2][1] = 1;
	tab[2][2] = 0;
	tab[2][3] = 1;
	tab[2][4] = 0;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 0;
	tab[4][1] = 1;
	tab[4][2] = 0;
	tab[4][3] = 1;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreC() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 0;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 0;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 0;
	tab[3][3] = 0;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 0;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 0;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreV() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 0;
	tab[3][3] = 1;
	tab[3][4] = 1;
	tab[4][0] = 0;
	tab[4][1] = 1;
	tab[4][2] = 0;
	tab[4][3] = 1;
	tab[4][4] = 0;
	tab[5][0] = 0;
	tab[5][1] = 1;
	tab[5][2] = 1;
	tab[5][3] = 1;
	tab[5][4] = 0;
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 1;
	tab[6][3] = 0;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreB() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 0;
	tab[1][0] = 1;
	tab[1][1] = 0;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 0;
	tab[2][2] = 0;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 1;
	tab[3][4] = 0;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 1;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 0;
	return tab;
}
int** creerLettreN() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 1;
	tab[1][2] = 0;
	tab[1][3] = 0;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 1;
	tab[2][2] = 1;
	tab[2][3] = 0;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 1;
	tab[4][3] = 1;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 1;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
int** creerLettreM() {
	int** tab = new int*[5];
	int i;
	for (i = 0; i < 7; ++i) {
		tab[i] = new int[7];
	}
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 1;
	tab[1][0] = 1;
	tab[1][1] = 1;
	tab[1][2] = 0;
	tab[1][3] = 1;
	tab[1][4] = 1;
	tab[2][0] = 1;
	tab[2][1] = 1;
	tab[2][2] = 1;
	tab[2][3] = 1;
	tab[2][4] = 1;
	tab[3][0] = 1;
	tab[3][1] = 0;
	tab[3][2] = 1;
	tab[3][3] = 0;
	tab[3][4] = 1;
	tab[4][0] = 1;
	tab[4][1] = 0;
	tab[4][2] = 0;
	tab[4][3] = 0;
	tab[4][4] = 1;
	tab[5][0] = 1;
	tab[5][1] = 0;
	tab[5][2] = 0;
	tab[5][3] = 0;
	tab[5][4] = 1;
	tab[6][0] = 1;
	tab[6][1] = 0;
	tab[6][2] = 0;
	tab[6][3] = 0;
	tab[6][4] = 1;
	return tab;
}
