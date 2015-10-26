#include <capteurs.h>
#include <libarmus.h>
#include <valeurs.h>
#include <pid.h>
#include <rotation.h>

//code capteur ici!

int Lire5kHz() //Lecture de l'entrée analogique du micro , donc le 5kHz pour le signal de départ . Fonction utilisee pour les deux robots.
{
	int lectureEntree = 0;

	lectureEntree = ANALOG_Read(PORTMICRO);
	if (lectureEntree >= 500) {
		lectureEntree = 1;
		//LCD_Printf("SIGNAL 5kHz!\n");
		return lectureEntree;
	} else {
		lectureEntree = 0;
		//LCD_Printf("PAS DE SIGNAL!\n");
		return lectureEntree;
	}
}

int SignalDepartSumo() { //Pour le Sumo ET le Ninja
	int premierSignal = 0;

	while (premierSignal != 1) {
		THREAD_MSleep(PAUSECAFE);
		premierSignal = Lire5kHz();
	}
	LCD_Printf("GO!!! I GOT YO BACK NINJA!!!\n");
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
	return 1;
}

int lireCapteurLigne() {
	ligneGauche = DIGITALIO_Read(11);
	ligneCentre = DIGITALIO_Read(10);
	ligneDroite = DIGITALIO_Read(9);

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

	LCD_Printf("RED: %i, GREEN: %i, BLUE: %i\n", red, green, blue);
	if (red > 200 && red < 350 && green > 100 && green < 175 && blue > 50
			&& blue < 150) {
		return ROUGE;
	} else if (red > 50 && red < 120 && green > 120 && green < 200 && blue > 80
			&& blue < 150) {
		return VERT;
	} else if (red > 75 && red < 150 && green > 120 && green < 225 && blue > 175
			&& blue < 400) {
		return BLEU;
	} else if (red > 375 && red < 600 && green > 350 && green < 610
			&& blue > 150 && blue < 300) {
		return JAUNE;
	} else if (red > 300 && red < 500 && green > 175 && green < 300
			&& blue > 150 && blue < 250) {
		return ROSE;
	} else if (red > 200 && red < 450 && green > 200 && green < 450
			&& blue > 250 && blue < 450) {
		return GRIS;
	} else if (red > 0 && red < 150 && green > 0 && green < 150 && blue > 0
			&& blue < 150) {
		return NOIR;
	} else {
		return BLANC;
	}
	return 0;
}
