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
#include <capteurs.h>

#define vitesse 85

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

int testMicro();
int testCouleur();
void testLigne();

int main() {
	int depart = 0;
	while (depart == 0) {
		depart = DIGITALIO_Read(BMP_REAR);
		if (depart != 0) {

			StratNinja();
			//testCouleur();
		}
	}

	return 0;
}

void testLigne() {
	while (bumperAvant == 0) {
		int lignePosition = 0;
		//lireCapteurLigne();
		lignePosition = lineFollower();

		if (lignePosition == 4) {	//droite
			MOTOR_SetSpeed(MOTOR_RIGHT, 55);
			MOTOR_SetSpeed(MOTOR_LEFT, 70);
		}
		if (lignePosition == 2) {	//center
			MOTOR_SetSpeed(MOTOR_RIGHT, 70);
			MOTOR_SetSpeed(MOTOR_LEFT, 70);
		}
		if (lignePosition == 3) {	//gauche
			MOTOR_SetSpeed(MOTOR_RIGHT, 70);
			MOTOR_SetSpeed(MOTOR_LEFT, 55);
		}
		THREAD_MSleep(50);
	}

}

int testCouleur() {
	while (bumperAvant == 0) {
		int couleur = lireCouleur();
		switch (couleur) {
		case 0:
			LCD_Printf("BLANC\n");
			break;
		case 1:
			LCD_Printf("ROUGE\n");
			break;
		case 2:
			LCD_Printf("GREEN\n");
			break;
		case 3:
			LCD_Printf("BLUE\n");
			break;
		case 4:
			LCD_Printf("YELLOW\n");
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
		}

		THREAD_MSleep(1000);
	}
	return 0;
}

int testMicro() {

	int i = 0;
	while (i < 20) {
		int lectureMicro = ANALOG_Read(1);
		LCD_Printf("Valeur Micro: %i\n", lectureMicro);
		THREAD_MSleep(200);
		++i;
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
	// � l'endroit
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
	//� l'envers

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
