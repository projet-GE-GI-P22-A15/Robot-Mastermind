#include "capteurs.h"
#include <libarmus.h>
#include "valeurs.h"
#include "pid.h"
#include "rotation.h"

int lireCapteurLigne() {
	ligneGauche = DIGITALIO_Read(11);
	ligneCentre = DIGITALIO_Read(10);
	ligneDroite = DIGITALIO_Read(9);

	//LCD_Printf("Gauche: %i, Centre: %i, Droite: %i\n", ligneGauche, ligneCentre, ligneDroite);

	return 0;
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

	int red = ((vRed * 100) / 16);
	int green = ((vGreen * 130) / 22);
	int blue = ((vBlue * 200) / 25);

	//LCD_Printf("RED: %i, GREEN: %i, BLUE: %i\n", red, green, blue);

	if (red > 250 && red < 350 && green > 125 && green < 180 && blue > 80
			&& blue < 150) {
		return ROUGE;
	} else if (red > 20 && red < 100 && green > 20 && green < 115 && blue > 20
			&& blue < 110) {
		return NOIR;
	} else if (red > 60 && red < 120 && green > 145 && green < 200 && blue > 80
			&& blue < 175) {
		return VERT;
	} else if (red > 75 && red < 145 && green > 130 && green < 190 && blue > 200
			&& blue < 375) {
		return BLEU;
	} else if (red > 450 && red < 600 && green > 500 && green < 625
			&& blue > 200 && blue < 275) {
		return JAUNE;
	} else if (red > 400 && red < 500 && green > 200 && green < 300
			&& blue > 150 && blue < 275) {
		return ROSE;
	} else if (red > 225 && red < 425 && green > 300 && green < 475
			&& blue > 275 && blue < 475) {
		return GRIS;
	} /*else if (red > 400 && red < 1000 && green > 400 && green < 1000
	 && blue > 400 && blue < 1000) {
	 return BLANC;
	 }*/else {
		return 0;
	}
	return 0;
}

int lireBoutonPhysique() {
	//Lire un front montant et apres 15ms lire ensuite un front descendant pour detecter une activation du bouton

	//Return la valeur 1 pour bouton 1 et 2 pour bouton 2 NE PAS FAIRE DE BOUCLE WHILE
	return 0;
}
