/**
 * 	Code cree par l'equipe d'Ingenium Natus
 * 	
 * 	Pascal Vaillancourt
 * 	Marc-Antoine Lalonde
 * 	Cedrik Maillet
 * 	Pierre-Geoffroy 
 * 	Alexis Morel
 * 	Patrick Beaulieu
 * 	Amazigh Abibsi
 * 	Justin Beaulieu
 * 	Anthony Parris
 */

#include <libarmus.h>
#include <pid.h>
#include <rotation.h>
#include <valeurs.h>

int roulerParcoursAller();
int roulerParcoursRetour();

int main() {

	/*MOTOR_SetSpeed(MOTOR_LEFT, 100);
	MOTOR_SetSpeed(MOTOR_RIGHT, 100);
	THREAD_MSleep(8000);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);*/

	/*avancerDroit(1, 1000, 100);
	tournerAlt(180, GAUCHE);
	avancerDroit(1, 1000, 100);*/

	roulerParcoursAller();

	 tournerAlt(90, GAUCHE);
	 avancerDroit(1, 14, -75);
	 tournerAlt(90, GAUCHE);

	 roulerParcoursRetour();

	return 0;
}

void roulerParcoursAller() {
	// À l'endroit
	avancerDroit(ARRET_DISTANCE, 193, 100); 	//200
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 41, 100); 	//47.5**
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 36, 100);	//45
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 41, 100); 	//47.5 ou == **
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 27, 100); 	//31.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 58, 100); 	// 67.2
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 69, 100); 	// 73.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 45, 100); 	// 47.5
	tournerAlt(12, DROITE);		//12.5
	avancerDroit(ARRET_DISTANCE, 75, 100); 	// 73.5
}

void roulerParcoursRetour() {
	//À l'envers
	avancerDroit(ARRET_DISTANCE, 75, 100); 	//73.5
	tournerAlt(12, GAUCHE);		//12.5
	avancerDroit(ARRET_DISTANCE, 39, 100); 	//47.5
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 64, 100); 	// 73.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 63, 100); 	//67.2
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 22, 100); 	//31.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 38, 100); 	// 47.5**
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 36, 100); 	// 45
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 38, 100); 	// 47.5 ou **
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 193, 100);	//200
}
