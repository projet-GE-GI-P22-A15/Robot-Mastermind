#include <capteurs.h>
#include <libarmus.h>
#include <valeurs.h>
#include <pid.h>
#include <rotation.h>

//code capteur ici!

int Lire5kHz() //Lecture de l'entrée analogique du micro , donc le 5kHz pour le signal de départ . Fonction utilisee pour les deux robots.
{
	if (ANALOG_Read(1) - ANALOG_Read(5) > 60) {
		LCD_Printf("%i\n", ANALOG_Read(1) - ANALOG_Read(5));
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

	if (red > 175 && red < 350 && green > 100 && green < 200 && blue > 50
			&& blue < 150) {
		return ROUGE;
	} else if (red > 0 && red < 145 && green > 0 && green < 145 && blue > 0
			&& blue < 145) {
		return NOIR;
	} else if (red > 50 && red < 120 && green > 145 && green < 200 && blue > 80
			&& blue < 175) {
		return VERT;
	} else if (red > 75 && red < 150 && green > 100 && green < 225 && blue > 200
			&& blue < 400) {
		return BLEU;
	} else if (red > 325 && red < 600 && green > 300 && green < 610
			&& blue > 150 && blue < 300) {
		return JAUNE;
	} else if (red > 300 && red < 500 && green > 150 && green < 300
			&& blue > 150 && blue < 250) {
		return ROSE;
	} else if (red > 200 && red < 450 && green > 200 && green < 450
			&& blue > 200 && blue < 450) {
		return GRIS;
	} /*else if (red > 400 && red < 1000 && green > 400 && green < 1000
	 && blue > 400 && blue < 1000) {
	 return BLANC;
	 }*/else {
		return 0;
	}
	return 0;
}
