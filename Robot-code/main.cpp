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
	InitCouleurs();
	//Fin Init
	int depart = 0;
	while (depart == 0) {
		depart = DIGITALIO_Read(BMP_REAR);
		if (depart != 0) {
			LCD_Printf("Bumper ON == Main ON\n");
			//Create thread here for Robot and Capteur ET CEST LA SEULE CHOSE QUIL FAIT!

			char texte1[6];
			texte1[0] = 'G';
			texte1[1] = 'E';
			texte1[2] = 'N';
			texte1[3] = 'I';
			texte1[4] = 'E';

			char texte2[6];
			texte2[0] = 'N';
			texte2[1] = 'a';
			texte2[2] = 't';
			texte2[3] = 'u';
			texte2[4] = 's';

			//charmaEcrire("#1BRAVOabcdd~");

			transmettreMot(1, texte1);
			transmettreMot(2, texte2);

			char texte3[8];
			texte3[0] = eJAUNE;
			texte3[1] = eROUGE;
			texte3[2] = eVERT;
			texte3[3] = eBLEU;
			texte3[4] = eVERT;
			texte3[5] = eVERT;
			texte3[6] = eJAUNE;
			texte3[7] = eROUGE;

			transmettreEssai(1, texte3);

			afficherJeu();
			THREAD_MSleep(2000);
			afficherMot();

		}
	}

	return 0;
}

