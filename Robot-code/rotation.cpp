#include <libarmus.h>
#include <rotation.h>
#include <valeurs.h>

void tourner(int angle, int direction) {
	int cochesGauche = 0, cochesDroite = 0;
	int vitesseGauche = 0, vitesseDroite = 0;

	int cochesATourner = (int) ((angle / 2) / 360 * NOMBRE_DIVISIONS_ROUES);

	if (direction == GAUCHE) {
		vitesseGauche = -50;
		vitesseDroite = 50;
	} else if (direction == DROITE) {
		vitesseGauche = 50;
		vitesseDroite = -50;
	}

	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);

	while (cochesGauche < cochesATourner || cochesDroite < cochesATourner) {
		cochesGauche += ENCODER_Read(ENCODER_LEFT);
		cochesDroite += ENCODER_Read(ENCODER_RIGHT);

		if (cochesGauche >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_LEFT, 0);
		}
		if (cochesGauche >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
		}
		THREAD_MSleep(50);
	}
}
