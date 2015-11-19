#include <libarmus.h>
#include "mouvement.h"
#include "valeurs.h"

//mode: Définit la méthode d'arrêt
//distance: la distance a parcourir en cm (pas important en mode IR)
//vitesse: la vitesse en % a laquelle le robot doit aller
void avancerDroit(int mode, int distance, int vitesse) {
	float distanceParcourue = 0;
	int cochesGauche = 0, cochesDroite = 0;

	int erreur = 0;
	int sommeErreurs = 0;
	int erreurPrecedente = 0;

	float correctionP = 0;
	float correctionI = 0;
	float correctionD = 0;

	//Préparation a avancer

	//Reset des encodeurs

	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	//Montée en charge des moteurs
	ajusterVitesseMoteurs(vitesse / 1.6);
	THREAD_MSleep(50);

	//Fin de la préparation

	//2 façons d'arrêter: Soit on atteint la distance voulue, soit on détecte un mur
	while (((mode == ARRET_DISTANCE && distanceParcourue < distance)
			|| (mode == ARRET_INFRAROUGE && IR_Detect(IR_FRONT) == 0))) {
		cochesGauche = ENCODER_Read(ENCODER_LEFT);
		cochesDroite = ENCODER_Read(ENCODER_RIGHT);

		distanceParcourue = distanceParcourue
				+ (((cochesGauche + cochesDroite) / 2)
						* (CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES));

		erreurPrecedente = erreur;
		erreur = cochesGauche - cochesDroite;
		sommeErreurs += erreur;

		correctionP = correctionProportionnelle(erreur, vitesse);
		correctionI = correctionIntegrative(sommeErreurs);
		correctionD = correctionDerivative(erreur, erreurPrecedente);

		appliquerCorrection(correctionP, correctionI, correctionD);

		ajusterVitesseMoteurs(vitesse);

		THREAD_MSleep(DELAI_LECTURE);
	}

	if (mode == 2) {
		avancerDroit(1, 18, vitesse);
	}
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}

//Determine l'importance de la proportion de l'erreur dans le PID
float correctionProportionnelle(int erreur, int vitesse) {
	float FACTEUR_CORRECTION_P = 0.04;

	float correction = erreur * FACTEUR_CORRECTION_P;
	return correction;
}

//Corrige l'erreur en prenant en compte les erreurs passees (offset)
float correctionIntegrative(int sommeErreurs) {
	float FACTEUR_CORRECTION_I = 0.01;

	float correction = sommeErreurs * FACTEUR_CORRECTION_I;
	return correction;
}

//Corrige l'erreur en prevoyant les erreurs futures
float correctionDerivative(int erreur, int erreurPrecedente) {
	float FACTEUR_CORRECTION_D = 0.01;

	//correction = deltaErreur * temps. (mais tweake un peu)
	if (erreur - erreurPrecedente > 1 || erreur - erreurPrecedente < -1) {
		float correction = (erreur - erreurPrecedente) * FACTEUR_CORRECTION_D;
		return correction;
	} else {
		return 0;
	}
}

//Ajuste le facteur correctif des moteurs en fonction du PID
void appliquerCorrection(float correctionP, float correctionI,
		float correctionD) {
	vitesseDroitePRGauche += correctionP + correctionI - correctionD;
}

//
void ajusterVitesseMoteurs(int vitesse) {
	int vitesseGauche = vitesse;
	int vitesseDroite = (int) (vitesse * vitesseDroitePRGauche);

	if (vitesseDroite > 100) {
		vitesseDroite = 100;
		vitesseGauche = (int) (100 / vitesseDroitePRGauche);
	} else if (vitesseDroite < -100) {
		vitesseDroite = -100;
		vitesseGauche = (int) (100 / vitesseDroitePRGauche);
	}
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);
}

void tourner(int angle, int direction) {
	int vitesse = 60;
	int cochesGauche = 0, cochesDroite = 0;
	int vitesseGauche = 0, vitesseDroite = 0;

	float cochesATournerTemp = (angle * CIRCONFERENCE_ROTATION)
			/ (CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES) / 360;

	int cochesATourner = cochesATournerTemp;

	if (cochesATournerTemp - cochesATourner >= 0.500) {
		cochesATourner += 1;
	}

	if (direction == GAUCHE) {
		vitesseGauche = -vitesse;
		vitesseDroite = vitesse;
	} else if (direction == DROITE) {
		vitesseGauche = vitesse;
		vitesseDroite = -vitesse;
	}

	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche / 2);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite / 2);
	THREAD_MSleep(30);

	while ((cochesGauche < cochesATourner || cochesDroite < cochesATourner)) {
		cochesGauche += ENCODER_Read(ENCODER_LEFT);
		cochesDroite += ENCODER_Read(ENCODER_RIGHT);

		if (cochesGauche >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_LEFT, 0);
		} else {
			MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
		}
		if (cochesDroite >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
		} else {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);
		}
		THREAD_MSleep(10);
	}

	//Fail safe
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}

void tournerAlt(int angle, int direction) {
	int vitesse = 60;
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
		vitesseDroite = vitesse;
	} else if (direction == DROITE) {
		vitesseGauche = vitesse;
		vitesseDroite = 0;
	}

	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche / 2);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite / 2);
	THREAD_MSleep(30);

	while (cochesGauche < cochesATourner && cochesDroite < cochesATourner) {
		cochesGauche += ENCODER_Read(ENCODER_LEFT);
		cochesDroite += ENCODER_Read(ENCODER_RIGHT);

		if (cochesGauche >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_LEFT, 0);
		} else {
			MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
		}
		if (cochesDroite >= cochesATourner) {
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
		} else {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);
		}
		THREAD_MSleep(15);
	}

	//Fail safe
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}

void suivreLigne() {
	int vitesse=65;
		int cutoff=0;
		if (ligneCentre == 0) {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesse*vitesseDroitePRGauche);
			MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
		} else if (ligneGauche == 0) {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesse*vitesseDroitePRGauche);
			MOTOR_SetSpeed(MOTOR_LEFT,cutoff);
		} else if (ligneDroite == 0) {
			MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
			MOTOR_SetSpeed(MOTOR_RIGHT,cutoff);
		} else {
			MOTOR_SetSpeed(MOTOR_RIGHT, vitesse*vitesseDroitePRGauche);
			MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
		}
}
