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

			//avancerDroit(1, 500, 100);
			StratNinja();
		}
	}

	return 0;
}

void testLigne() {
	while (bumperAvant == 0) {
		int lignePosition = 0;
		lireCapteurLigne();
		printf("%i", lineFollower());

		THREAD_MSleep(1000);
	}

}

int testCouleur() {
	while (bumperAvant == 0) {
		couleur = lireCouleur();
		printCouleur(couleur);

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
