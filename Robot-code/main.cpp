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
#include <couleuri2c.h>

#define vitesse 85

//int testCapteurCouleurI2C();

int testMicro();
int testCouleur();
void testLigne();

int main() {
	int depart = 0;
	while (depart == 0) {
		depart = DIGITALIO_Read(BMP_REAR);
		if (depart != 0) {

			testMicro();
			//testCapteurCouleurI2C();
			//StratNinja();
			//testCouleur();
			//testCapteurCouleurI2C();
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
	while (1) {
		Lire5kHz();
		THREAD_MSleep(1000);
	}
	return 0;
}

int testCapteurCouleurI2C() {

	int red, blue, green, clear;

	//initialisation du capteur

	cap_SetValue(CAP_RED, 15);
	cap_SetValue(CAP_GREEN, 15);
	cap_SetValue(CAP_BLUE, 15);
	cap_SetValue(CAP_CLEAR, 15);

	integrationTime_SetValue(INTEGRATION_RED, 255);
	integrationTime_SetValue(INTEGRATION_GREEN, 255);
	integrationTime_SetValue(INTEGRATION_BLUE, 255);
	integrationTime_SetValue(INTEGRATION_CLEAR, 255);

	while (1) {
		color_Read(red, blue, green, clear);
		LCD_ClearAndPrint("R=%d, G=%d, B=%d, C=%d", red, green, blue, clear);
		THREAD_MSleep(1000);
	}

	return 0;
}
