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
#include "valeurs.h"
#include "logique.h"

void threadCapteur();
void threadCRJ();

/**
 * @brief Demarre la lecture des capteurs
 * @details Lit Le suiveur de lignes, le capteur de couleur et ....
 */
void threadCapteur() {
	int mainCapteur = 0;
	LCD_Printf("Debut du thread Capteur\n\r");
	while (mainCapteur != 1) {
		mainCapteur = mainCRJ();
	}
	// THREAD DESTROY HERE
	LCD_Printf("Thread Capteur = DEAD\n\r");
}

/**
 * @brief Execute la fonction mainCRJ
 * @details Appelle la fonction mainCRJ de logique.h et l'executer en parallele
 */
void threadCRJ() {
	int mainCRJEtat = 0;
	LCD_Printf("Debut du thread CRJ\n\r");
	while (mainCRJEtat != 1) {
		mainCRJEtat = mainCRJ();
	}
	// THREAD DESTROY HERE
	LCD_Printf("Thread CRJ = DEAD\n\r");
}

int main() {
	int depart = 0;
	while (depart == 0) {
		depart = DIGITALIO_Read(BMP_REAR);
		if (depart != 0) {
			LCD_Printf("Bumper ON == Main ON\n\r");
			//Create thread here for Robot and Capteur ET CEST LA SEULE CHOSE QUIL FAIT!

		}
	}

	return 0;
}

