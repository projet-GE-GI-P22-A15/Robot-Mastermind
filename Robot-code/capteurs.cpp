#include <capteurs.h>
#include <libarmus.h>
#include <valeurs.h>
#include <pid.h>
#include <rotation.h>

//code capteur ici!
#define PORTMICRO 1
#define PAUSECAFE 200

#define BLANC 0
#define ROUGE 1
#define VERT 2
#define BLEU 3
#define JAUNE 4
#define GRIS 5
#define ROSE 6

#define AUCUN_OBSTACLE  0
#define PERPENDICULAIRE 1
#define LIGNE_AU_CENTRE 2
#define LIGNE_A_GAUCHE  3
#define LIGNE_A_DROITE  4

int Lire5kHz() //Lecture de l'entrÃ©e analogique du micro , donc le 5kHz pour le signal de dÃ©part . Fonction utilisee pour les deux robots.
{
	int lectureEntree = 0;

	lectureEntree = ANALOG_Read(PORTMICRO);
	if (lectureEntree >= 500) {
		lectureEntree = 1;
		LCD_Printf("SIGNAL 5kHz!\n");
		return lectureEntree;
	} else {
		lectureEntree = 0;
		LCD_Printf("PAS DE SIGNAL!\n");
		return lectureEntree;
	}
}

int SignalDepartSumo() //Pour le Sumo ET le Ninja
{
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

	THREAD_MSleep(2000);
	while (deuxiemeSignal != 2) {
		THREAD_MSleep(PAUSECAFE);
		deuxiemeSignal = deuxiemeSignal + Lire5kHz();
	}
	return 1;
}

int lireCapteurLigne() {
	ligneGauche = DIGITALIO_Read(8);
	ligneCentre = DIGITALIO_Read(9);
	ligneDroite = DIGITALIO_Read(10);
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

	int redValue = ((vRed * 100) / 16);
	int greenValue = ((vGreen * 130) / 22);
	int blueValue = ((vBlue * 200) / 25);

	LCD_Printf("RED: %i, GREEN: %i, BLUE: %i\n", redValue, greenValue,
			blueValue);

	/*if (redValue > greenValue && redValue > blueValue) {
	 if (greenValue > 2.6)
	 LCD_Printf("Object is Orange.");
	 else
	 LCD_Printf("Object is Red.");
	 } else if (greenValue > blueValue && greenValue > redValue) {
	 if (redValue > 2)
	 LCD_Printf("Object is Yellow.");
	 else
	 LCD_Printf("Object is Green.");
	 } else {
	 if (redValue > 2)
	 LCD_Printf("Object is Purple.");
	 else
	 LCD_Printf("Object is Blue.");
	 }*/
	return 0;
}

#define AUCUN_OBSTACLE  0
#define PERPENDICULAIRE 1
#define LIGNE_AU_CENTRE 2
#define LIGNE_A_GAUCHE  3
#define LIGNE_A_DROITE  4

//Position : 1 pour tourner a gauche  2 pour tourner a droite
int mainNinja(int positon) {
	int position = 1;

	// attendre le 3 sec 5khz

	while (lineFollower() != PERPENDICULAIRE)
		avancerDroit(1, 1, 90);

	if (position == 1 && lineFollower() == PERPENDICULAIRE) {
		while (lineFollower() < LIGNE_AU_CENTRE) {
			MOTOR_SetSpeed(MOTOR_LEFT, -60);
			MOTOR_SetSpeed(MOTOR_RIGHT, 60);
		}
	}
	if (position == 2 && lineFollower() == PERPENDICULAIRE) {
		while (lineFollower() < LIGNE_AU_CENTRE) {
			MOTOR_SetSpeed(MOTOR_LEFT, 60);
			MOTOR_SetSpeed(MOTOR_RIGHT, -60);
		}

	}

	if (lineFollower() == LIGNE_AU_CENTRE) {
		tournerAlt(15, DROITE);
		while (lineFollower() != LIGNE_A_GAUCHE) {
			avancerDroit(1, 1, 90);
		}
	}

	//jusqu'à ce que le robot détecte sa couleur:

	if (lineFollower() == LIGNE_A_DROITE) {
		tournerAlt(30, DROITE);
		while (lineFollower() != LIGNE_A_GAUCHE) {
			avancerDroit(1, 1, 90);
		}

	} else if (lineFollower() == LIGNE_A_GAUCHE) {
		tournerAlt(30, GAUCHE);
		while (lineFollower() != LIGNE_A_DROITE) {
			avancerDroit(1, 1, 90);
		}
	}
return 0;
}

int lineFollower() {
	// 0 = noir  1 = blanc

	if (ligneGauche == 1 && ligneCentre == 1 && ligneDroite == 1) // avant d arriver sur la ligne                        (AUCUN_OBSTACLE)
		return 0;
	else if (ligneGauche == 0 && ligneCentre == 0 && ligneDroite == 0) // lorsqu il croise la ligne pour la premiere fois (PERPENDICULAIRE)
		return 1;
	else if (ligneGauche == 1 && ligneCentre == 0 && ligneDroite == 1) // ligne au centre                                (LIGNE_AU_CENTRE)
		return 2;
	else if (ligneGauche == 0 && ligneCentre == 1 && ligneDroite == 1) // ligne a gauche                                 (LIGNE_A_GAUCHE)
		return 3;
	else if (ligneGauche == 1 && ligneCentre == 1 && ligneDroite == 0) // ligne a droite                                  (LIGNE_A_DROITE)
		return 4;
	else
		return -1;
}
