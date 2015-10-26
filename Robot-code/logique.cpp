#include "logique.h"
#include <libarmus.h>
#include <valeurs.h>
#include <capteurs.h>
#include <pid.h>
#include <rotation.h>

//code pour logique ici
int StratNinja() {
	SignalDepartNinja();
	avancer = 1;
	avancerDroit(ARRET_EXTERNE, 50, 60);
	THREAD_MSleep(2000);
	avancer = 0;

	return 0;
}

void partirThreadCapteurs() {
		conditionArret = Lire5kHz();
		couleur = lireCouleur();
		lireCapteurLigne();
		lireBumpers();
		THREAD_MSleep(25);


}
void arreterMouvement(){
	avancer = 0;
}

void avancerThread(int vitesse){
	avancer = 1;
	vitesseGlobale = vitesse;
	THREAD t = THREAD_CreateSimple(partirPIDThread);
	THREAD_Destroy(&t);
}

void tournerThread(int angle, int direction){
	angleGlobal = angle;
	directionGlobale = direction;
	THREAD t = THREAD_CreateSimple(tournerThreaded);
	THREAD_Destroy(&t);
}

void tournerAltThread(int angle, int direction){
	angleGlobal = angle;
	directionGlobale = direction;
	THREAD t = THREAD_CreateSimple(tournerAltThreaded);
	THREAD_Destroy(&t);
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

