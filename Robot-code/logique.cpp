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
	couleurCible = lireCouleur();
	SignalDepartNinja();
	avancerThread(70);
	while (couleur != ROUGE) {
		lireCapteurs();
		THREAD_MSleep(100);
	}
	while (couleur != BLANC) {
		lireCapteurs();
		THREAD_MSleep(100);
	}
	arreterMouvement();
	avancerDroit(ARRET_DISTANCE, 30, 70);
	avancerThread(50);
	while (couleur == BLANC) {
		lireCapteurs();
		THREAD_MSleep(50);
	}
	arreterMouvement();
	THREAD_MSleep(4000);
	tourner(45, GAUCHE); // Cote a modifier selon l<emplacement de depart
	while (couleur != couleurCible && conditionArret == 0) {
		lireCapteurs();
		int lignePosition = lineFollower();
		if (couleur == couleurCible) {
			avancerDroit(1, 20, 70);
		} else if (couleur == ROUGE) {
			arreterMouvement();
			avancerDroit(1, 30, -80);
			tourner(180, DROITE);
			avancerThread(70);
		} else if (lignePosition == 2) {
			arreterMouvement();
			avancerThread(70);
		} else if (lignePosition == 3) {
			arreterMouvement();
			tournerAlt(25, GAUCHE);
		} else if (lignePosition == 40) {
			arreterMouvement();
			tournerAlt(25, DROITE);
		} else if (couleur != BLANC && couleur != couleurCible) {
			avancerDroit(1, 20, 70);
			tournerThread(90, DROITE);
			avancerThread(70);
		} else if (avancer == 0) {
			avancerThread(70);
		}

		THREAD_MSleep(100);
	}
	arreterMouvement();
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	LCD_Printf("FIN!");

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
		LCD_Printf("ERREUR");
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

