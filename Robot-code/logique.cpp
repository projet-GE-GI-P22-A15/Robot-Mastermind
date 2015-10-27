#include "logique.h"
#include <libarmus.h>
#include <valeurs.h>
#include <capteurs.h>
#include <pid.h>
#include <rotation.h>

//code pour logique ici

THREAD thread1;

int StratSumo1() {
	SignalDepartSumo();
	avancer = 1;
	while (!(lireCouleur() == GRIS && bumperAvant == 1)) {
		avancerThread(60);
	}
	arreterMouvement();
	tournerThread(15, GAUCHE);
	tournerThread(30, DROITE);
	THREAD_MSleep(2000);
	avancer = 0;

	return 0;
}

int StratNinja() {
	int directionDepart = GAUCHE;

	int vitesseNinja = 60;
	couleurCible = lireCouleur();
	printCouleur(couleurCible);
	//SignalDepartNinja();
	avancerThread(80);
	while (couleur != ROUGE) {
		lireCapteurs();
		THREAD_MSleep(100);
	}
	while (couleur != BLANC) {
		lireCapteurs();
		THREAD_MSleep(100);
	}
	arreterMouvement();
	avancerDroit(ARRET_DISTANCE, 30, 60);
	THREAD_MSleep(1000);
	tourner(40, directionDepart);
	int lignePosition = 0;
	avancerThread(vitesseNinja);
	while (couleur != couleurCible && conditionArret == 0) {
		lastCouleur = couleur;
		lireCapteurs();
		lignePosition = lineFollower();

		if (couleur != lastCouleur || lignePosition != 0) {
			printCouleur(couleur);
			if (couleur == couleurCible) {
				arreterMouvement();
				THREAD_MSleep(300);
				lireCapteurs();
				avancerDroit(1, 15, vitesseNinja);
			} else if (couleur == ROUGE) {
				arreterMouvement();
				THREAD_MSleep(50);
				avancerDroit(1, 10, -80);
				THREAD_MSleep(50);
				tourner(180, directionDepart);
				THREAD_MSleep(50);
				avancerThread(vitesseNinja);
				THREAD_MSleep(50);
			} /*else if (lignePosition == 1) {
			 arreterMouvement();
			 THREAD_MSleep(50);
			 tourner(45, DROITE);
			 THREAD_MSleep(50);
			 } else if (lignePosition == 3) {
			 arreterMouvement();
			 THREAD_MSleep(50);
			 tourner(45, GAUCHE);
			 THREAD_MSleep(50);
			 }*/
			else if (couleur == BLANC) {
				arreterMouvement();
				THREAD_MSleep(50);
				avancerThread(vitesseNinja);
				THREAD_MSleep(50);
			} else if (couleur == GRIS) {
				tourner(135, directionDepart);
			} else if (couleur != NOIR) {

				arreterMouvement();
				THREAD_MSleep(50);
				avancerDroit(1, 10, 70);
				THREAD_MSleep(50);
				avancerDroit(1, 10, -70);
				THREAD_MSleep(50);
				tourner(90, directionDepart);
				THREAD_MSleep(50);
				avancerThread(vitesseNinja);
				THREAD_MSleep(50);
			}
		} else if (couleur == BLANC || avancer == 0 || threadQuiRoule == 0) {
			avancerThread(vitesseNinja);
		}
		THREAD_MSleep(100);
	}
	arreterMouvement();
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	LCD_Printf("FIN!\n");
	THREAD_MSleep(50);

	return 0;
}

void printCouleur(int couleur) {
	switch (couleur) {
	case 0:
		LCD_Printf("BLANC\n");
		break;
	case 1:
		LCD_Printf("ROUGE\n");
		break;
	case 2:
		LCD_Printf("VERT\n");
		break;
	case 3:
		LCD_Printf("BLEU\n");
		break;
	case 4:
		LCD_Printf("JAUNE\n");
		break;
	case 5:
		LCD_Printf("ROSE\n");
		break;
	case 6:
		LCD_Printf("GRIS\n");
		break;
	case 7:
		LCD_Printf("NOIR\n");
		break;
	case -1:
		LCD_Printf("ERREUR\n");
		break;
	}

}

void lireCapteurs() {
	conditionArret = Lire5kHz();
	couleur = lireCouleur();
	lireCapteurLigne();
	lireBumpers();
}
void arreterMouvement() {

	if (threadQuiRoule == 1) {
		THREAD_Destroy(&thread1);
		threadQuiRoule = 0;
	}
	avancer = 0;
	THREAD_MSleep(100);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}

void avancerThread(int vitesse) {
	avancer = 1;
	vitesseGlobale = vitesse;
	thread1 = THREAD_CreateSimple(partirPIDThread);
	threadQuiRoule = 1;
}

void tournerThread(int angle, int direction) {
	angleGlobal = angle;
	directionGlobale = direction;
	thread1 = THREAD_CreateSimple(tournerThreaded);
	threadQuiRoule = 1;
}

void tournerAltThread(int angle, int direction) {
	angleGlobal = angle;
	directionGlobale = direction;
	thread1 = THREAD_CreateSimple(tournerAltThreaded);
	threadQuiRoule = 1;
}

int lineFollower() {
// 0 = noir  1 = blanc

	/*if (ligneGauche == 1 && ligneCentre == 1 && ligneDroite == 1) // avant d arriver sur la ligne                        (AUCUN_OBSTACLE)
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
	 return -1;*/
	if (ligneCentre == 0) {
		return 2;
	} else if (ligneGauche == 0) {
		return 1;
	} else if (ligneDroite == 0) {
		return 3;
	} else {
		return 0;
	}
}

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

//jusqu'� ce que le robot d�tecte sa couleur:

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

