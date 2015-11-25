#include "capteurs.h"
#include <libarmus.h>
#include "valeurs.h"
#include "mouvement.h"
#include "logique.h"
#include "charma.h"

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
		return eROUGE;
	} else if (red > 60 && red < 120 && green > 145 && green < 200 && blue > 80
			&& blue < 175) {
		return eVERT;
	} else if (red > 75 && red < 145 && green > 130 && green < 190 && blue > 200
			&& blue < 375) {
		return eBLEU;
	} else if (red > 450 && red < 600 && green > 500 && green < 625
			&& blue > 200 && blue < 275) {
		return eJAUNE;
	} else if (red > 400 && red < 500 && green > 200 && green < 300
			&& blue > 150 && blue < 275) {
		return eROSE;
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
