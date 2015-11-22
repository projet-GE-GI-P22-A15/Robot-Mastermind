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
#include "charma.h"

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
	//Init les sorties du CHARMA. IMPORTANT.
	DIGITALIO_Write(sepO, 0);
	DIGITALIO_Write(sigO, 0);
	//Fin Init
	int depart = 0;
	while (depart == 0) {
		depart = DIGITALIO_Read(BMP_REAR);
		if (depart != 0) {
			LCD_Printf("Bumper ON == Main ON\n");
			//Create thread here for Robot and Capteur ET CEST LA SEULE CHOSE QUIL FAIT!

			char texte1[] = "RGBYaabc";
			char texte2[] = "BRAVOabcde";
			char texte3[14];
			texte3[0] = '#';
			texte3[1] = '1';
			texte3[2] = 'B';
			texte3[3] = 'R';
			texte3[4] = 'A';
			texte3[5] = 'V';
			texte3[6] = 'O';
			texte3[7] = 'a';
			texte3[8] = 'b';
			texte3[9] = 'c';
			texte3[10] = 'd';
			texte3[11] = 'e';
			texte3[12] = '~';
			texte3[13] = '\0';

			int i;
			for (i = 0; i < 10; ++i) {
				transmettreEssai(1, texte1);
				transmettreMot(1, texte2);
			}
		}
	}

	return 0;
}

