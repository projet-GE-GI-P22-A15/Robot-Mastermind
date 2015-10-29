#include <capteurs.h>
#include <libarmus.h>
#include <valeurs.h>
#include <pid.h>
#include <rotation.h>

//code capteur ici!

int Lire5kHz() //Lecture de l'entrée analogique du micro , donc le 5kHz pour le signal de départ . Fonction utilisee pour les deux robots.
{
	if (ANALOG_Read(1) - ANALOG_Read(5) > 60) {
		return 1;
	} else {
		return 0;
	}
}

int SignalDepartSumo() { //Pour le Sumo ET le Ninja
	int premierSignal = 0;

	while (premierSignal != 1) {
		THREAD_MSleep(PAUSECAFE);
		premierSignal = Lire5kHz();
	}
	//LCD_Printf("Premier Signal!\n");
	return premierSignal;
}

int SignalDepartNinja() { //Pour le Ninja seulement!!! Il utilise la fonction de signal de depart pour le Sumo pour justement partir apres le Sumo.
	int deuxiemeSignal;
	deuxiemeSignal = SignalDepartSumo();

	THREAD_MSleep(3000);
	while (deuxiemeSignal != 2) {
		THREAD_MSleep(PAUSECAFE);
		deuxiemeSignal = deuxiemeSignal + Lire5kHz();
	}
	//LCD_Printf("Deuxi�me signal!");
	return 1;
}

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
