#include "capteurs.h"
#include <libarmus.h>
#include "valeurs.h"
#include "mouvement.h"
#include "logique.h"
#include "charma.h"

int red, green, blue;
int tableauCouleurs[9];

void lireCapteurLigne() {
	ligneGauche = DIGITALIO_Read(11);
	ligneCentre = DIGITALIO_Read(10);
	ligneDroite = DIGITALIO_Read(9);

	//LCD_Printf("Gauche: %i, Centre: %i, Droite: %i\n", ligneGauche, ligneCentre, ligneDroite);

}

int lireBumpers() {
	bumperAvant = DIGITALIO_Read(BMP_FRONT);
	bumperArriere = DIGITALIO_Read(BMP_REAR);
	bumperGauche = DIGITALIO_Read(BMP_LEFT);
	bumperDroite = DIGITALIO_Read(BMP_RIGHT);

	return 0;
}

int lireCouleur() {
	int vRed = ANALOG_Read(2);
	int vGreen = ANALOG_Read(3);
	int vBlue = ANALOG_Read(4);

	red = ((vRed * 100) / 16);
	green = ((vGreen * 130) / 22);
	blue = ((vBlue * 200) / 25);

	//LCD_Printf("R: %i, G: %i, B: %i\n", red, green, blue);

	if (comparerCouleur(87, 130, 232)) {
		tableauCouleurs[eBLEU] = tableauCouleurs[eBLEU] + 1;
	} else if (comparerCouleur(125, 315, 176)) {
		++tableauCouleurs[eVERT] = tableauCouleurs[eVERT] + 1;
	} /*else if (comparerCouleur(0, 0, 0)) {
	 return eCYAN;
	 }*/else if (comparerCouleur(350, 190, 110)) {
		++tableauCouleurs[eROUGE] = tableauCouleurs[eROUGE] + 1;
	} else if (comparerCouleur(780, 330, 264)) {
		++tableauCouleurs[eROSE] = tableauCouleurs[eROSE] + 1;
	} else if (comparerCouleur(490, 720, 288)) {
		++tableauCouleurs[eJAUNE] = tableauCouleurs[eJAUNE] + 1;
	} else if (comparerCouleur(800, 390, 160)) {
		++tableauCouleurs[eCYAN] = tableauCouleurs[eCYAN] + 1; //pastille orange
	} else if (comparerCouleur(250, 159, 100)) {
		++tableauCouleurs[eORANGE] = tableauCouleurs[eORANGE] + 1; // tape orange
	} else if (comparerCouleur(56, 65, 56)) {
		++tableauCouleurs[eNOIR] = tableauCouleurs[eNOIR] + 1;
	} else if (comparerCouleur(385, 460, 400)) {
		resetCouleurs(); //blanc
	}
	return trouverCouleur();
}

void resetCouleurs() {
	int i;
	for (i = 0; i < 9; ++i) {
		tableauCouleurs[i] = 0;
	}
}

int trouverCouleur() {
	int max = 7;

	int i;
	for (i = 0; i < 9; ++i) {
		if (tableauCouleurs[i] > 5
				&& tableauCouleurs[i] > tableauCouleurs[max]) {
			max = i;
		}
	}
	return max;
}

int comparerCouleur(int rouge, int vert, int bleu) {
	int tolerance = 60;
	if (red > rouge - tolerance && red < rouge + tolerance
			&& green > vert - tolerance && green < vert + tolerance
			&& blue > bleu - tolerance && blue < bleu + tolerance) {
		return 1;
	} else {
		return 0;
	}
}

int lireBoutonPhysiqueEssai() {
	//Lire un front montant et apres 15ms lire ensuite un front descendant pour detecter une activation du bouton
	//Return la valeur 1 pour bouton 1 et 2 pour bouton 2 NE PAS FAIRE DE BOUCLE WHILE

	return 0; //Doit retourner 1 (Vrai) ou 0 (Faux)
}

int lireBoutonPhysiqueNbPastilles() {
	//Lire un front montant et apres 15ms lire ensuite un front descendant pour detecter une activation du bouton
	//Return la valeur 1 pour bouton 1 et 2 pour bouton 2 NE PAS FAIRE DE BOUCLE WHILE

	return 0; //Doit retourner 1 (Vrai) ou 0 (Faux)
}

int lireBoutonPhysiqueResetGame() {
	//Lire un front montant et apres 15ms lire ensuite un front descendant pour detecter une activation du bouton
	//Return la valeur 1 pour bouton 1 et 2 pour bouton 2 NE PAS FAIRE DE BOUCLE WHILE

	return 0; //Doit retourner 1 (Vrai) ou 0 (Faux)
}
