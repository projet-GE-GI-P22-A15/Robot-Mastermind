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

#include <libarmus>
#include "controlMoteur.h"

//Determine l'importance de la proportion de l'erreur dans le PID
float correctionProportionnelle(int cochesGauche, int cochesDroite){
	float FACTEUR_CORRECTION_P = 0.06666;

	float correction = erreur * FACTEUR_CORRECTION_P;
	return correction;
}

//Corrige l'erreur en prenant en compte les erreurs passees (offset)
float correctionIntegrative(int sommeErreurs){
	float FACTEUR_CORRECTION_I = 0.03;
	
	float correction = sommeErreurs * FACTEUR_CORRECTION_I;
	return correction;
}

//Corrige l'erreur en prevoyant les erreurs futures
float correctionDerivative(int erreur, int erreurPrecedente, int delaiAdaptatif){
	float FACTEUR_CORRECTION_D = 0.01;
	
	//correction = deltaErreur * temps. (mais tweake un peu)
	float correction = (erreur - erreurPrecedente * DELAI_LECTURE) * delaiAdaptatif * FACTEUR_CORRECTION_D;
	return correction;
}

//Ajuste le facteur correctif des moteurs en fonction du PID
void appliquerCorrection(int correctionP, int correctionI, int correctionD){
	vitesseDroitePRGauche += correctionP + correctionI + correctionD;
}

//
void ajusterVitesseMoteurs(){
	if (vitesse * vitesseDroitePRGauche > 100){
		MOTOR_SetSpeed(MOTOR_LEFT, 100 / vitesseDroitePRGauche);
		MOTOR_SetSpeed(MOTOR_RIGHT, 100);
	} else {
		MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
		MOTOR_SetSpeed(MOTOR_RIGHT, vitesse * vitesseDroitePRGauche);
	}
}





