#include <libarmus.h>
#include <rotation.h>
#include <valeurs.h>

void tourner(int angle, int direction) {
	int cochesGauche = 0, cochesDroite = 0;
	int vitesseGauche = 0, vitesseDroite = 0;

	float cochesATournerTemp = (angle * CIRCONFERENCE_ROTATION)
			/ (CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES) / 360;

	int cochesATourner = cochesATournerTemp;

	if (cochesATournerTemp - cochesATourner >= 0.500) {
		cochesATourner += 1;
	}

	if (direction == GAUCHE) {
		vitesseGauche = -75;
		vitesseDroite = 75;
	} else if (direction == DROITE) {
		vitesseGauche = 75;
		vitesseDroite = -75;
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
		} else if (cochesGauche >= cochesATourner - 10) {
			MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche / 2);
		}
		if (cochesDroite >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
		} else if (cochesDroite >= cochesATourner - 10) {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite / 2);
		}
		THREAD_MSleep(25);
	}

	//Fail safe
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	THREAD_MSleep(100);
}

void tournerAlt(int angle, int direction) {
	int cochesGauche = 0, cochesDroite = 0;
	int vitesseGauche = 0, vitesseDroite = 0;

	float cochesATournerTemp = (angle * 2 * CIRCONFERENCE_ROTATION)
			/ (CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES) / 360;

	int cochesATourner = cochesATournerTemp;

	if (cochesATournerTemp - cochesATourner >= 0.500) {
		cochesATourner += 1;
	}

	if (direction == GAUCHE) {
		vitesseGauche = 0;
		vitesseDroite = 75;
	} else if (direction == DROITE) {
		vitesseGauche = 75;
		vitesseDroite = 0;
	}

	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);

	while (cochesGauche < cochesATourner && cochesDroite < cochesATourner) {
		cochesGauche += ENCODER_Read(ENCODER_LEFT);
		cochesDroite += ENCODER_Read(ENCODER_RIGHT);

		if (cochesGauche >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_LEFT, 0);
		}
		if (cochesDroite >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
		}
		THREAD_MSleep(25);
	}

	//Fail safe
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	THREAD_MSleep(100);
}

