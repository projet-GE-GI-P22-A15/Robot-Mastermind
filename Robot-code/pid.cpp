#include <libarmus.h>
#include <pid.h>
#include <valeurs.h>

#include <pid.h>
#include <libarmus.h>



void partirPIDThread(){
	avancerDroit(ARRET_EXTERNE, 0, vitesseGlobale);

}
//mode: Définit la méthode d'arrêt
//distance: la distance a parcourir en cm (pas important en mode IR)
//vitesse: la vitesse en % a laquelle le robot doit aller
void avancerDroit(int mode, int distance, int vitesse) {
	conditionArret = 0;
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
			|| (mode == ARRET_INFRAROUGE && IR_Detect(IR_FRONT) == 0))
			|| (mode == ARRET_EXTERNE && avancer == 1)) {
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

		/*if (distance - distanceParcourue <= 5) {
		 ajusterVitesseMoteurs(vitesse / 1.7);
		 } else {
		 ajusterVitesseMoteurs(vitesse);
		 }*/
		THREAD_MSleep(DELAI_LECTURE);
	}

	if (mode == 2) {
		avancerDroit(1, 18, vitesse);
	}
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	THREAD_MSleep(100);
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
