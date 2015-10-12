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
#include <logique.h>

#define vitesse 80

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int roulerParcoursAller();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int roulerParcoursRetour();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int roulerParcoursComplet();

int main() {
	//THREAD BumperStopper;

	while (execution == 0) {
		execution = DIGITALIO_Read(BMP_REAR);
		if (execution != 0) {

			//tournerAlt(1080, DROITE);

			//BumperStopper = THREAD_CreateSimple(BumperCommander);
			/*MOTOR_SetSpeed(MOTOR_LEFT, 100);
			 MOTOR_SetSpeed(MOTOR_RIGHT, 100);
			 THREAD_MSleep(8000);
			 MOTOR_SetSpeed(MOTOR_LEFT, 0);
			 MOTOR_SetSpeed(MOTOR_RIGHT, 0);*/

			/*avancerDroit(1, 1000, 100);
			 tournerAlt(180, GAUCHE);
			 avancerDroit(1, 1000, 100);*/

			roulerParcoursComplet();

			//THREAD_Destroy(&BumperStopper);
		}
		THREAD_MSleep(50);
	}

	return 0;
}

int roulerParcoursComplet() {
	roulerParcoursAller();

	tournerAlt(90, GAUCHE);
	avancerDroit(1, 15, -75);
	tournerAlt(90, GAUCHE);

	roulerParcoursRetour();

	return 0;
}

int roulerParcoursAller() {
	// À l'endroit
	avancerDroit(ARRET_DISTANCE, 216, vitesse); 	//200
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 27, vitesse); 	//47.5**
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 28, vitesse);	//45
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 32, vitesse); 	//47.5 ou == **
	tournerAlt(87, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 23, vitesse); 	//31.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 27, vitesse); 	// 67.2
	tournerAlt(85, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 53, vitesse); 	// 73.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 30, vitesse); 	// 47.5
	tournerAlt(10, DROITE);		//12.5
	avancerDroit(ARRET_DISTANCE, 85, vitesse); 	// 73.5

	return 0;
}

int roulerParcoursRetour() {
	//À l'envers

	avancerDroit(ARRET_DISTANCE, 85, vitesse); 	//73.5
	tournerAlt(12, GAUCHE);		//12.5
	avancerDroit(ARRET_DISTANCE, 37, vitesse); 	//47.5
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 58, vitesse); 	// 73.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 30, vitesse); 	//67.2
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 21, vitesse); 	//31.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 31, vitesse); 	// 47.5**
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 28, vitesse); 	// 45
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 29, vitesse); 	// 47.5 ou **
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 225, vitesse);	//200

	return 0;
}
