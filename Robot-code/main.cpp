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

int main() {
	int bumperPresse = 0;
	while (bumperPresse == 0) {
		bumperPresse = DIGITALIO_Read(BMP_REAR);
		if ( bumperPresse != 0) {
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
			avancerDroit(1, 12, -75);
			tournerAlt(90, GAUCHE);

			roulerParcoursRetour();
		}
		THREAD_MSleep(50);
	}

	return 0;
}

int roulerParcoursAller() {
	// À l'endroit
	avancerDroit(ARRET_DISTANCE, 216, 100); 	//200
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 27, 100); 	//47.5**
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 28, 100);	//45
	tournerAlt(90, DROITE);		//90
	avancerDroit(ARRET_DISTANCE, 29, 100); 	//47.5 ou == **
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 26, 100); 	//31.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 30, 100); 	// 67.2
	tournerAlt(90, GAUCHE);		//90
	avancerDroit(ARRET_DISTANCE, 58, 100); 	// 73.2
	tournerAlt(45, DROITE);		//45
	avancerDroit(ARRET_DISTANCE, 30, 100); 	// 47.5
	tournerAlt(5, DROITE);		//12.5
	avancerDroit(ARRET_DISTANCE, 85, 100); 	// 73.5

	return 0;
}

int roulerParcoursRetour() {
	//À l'envers

	avancerDroit(ARRET_DISTANCE, 85, 100); 	//73.5
	tournerAlt(12, GAUCHE);		//12.5
	avancerDroit(ARRET_DISTANCE, 30, 100); 	//47.5
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 55, 100); 	// 73.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 30, 100); 	//67.2
	tournerAlt(45, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 26, 100); 	//31.2
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 31, 100); 	// 47.5**
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 28, 100); 	// 45
	tournerAlt(90, GAUCHE);
	avancerDroit(ARRET_DISTANCE, 29, 100); 	// 47.5 ou **
	tournerAlt(90, DROITE);
	avancerDroit(ARRET_DISTANCE, 225, 100);	//200

	return 0;
}
