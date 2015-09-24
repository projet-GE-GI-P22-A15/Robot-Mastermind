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

#include "controlMoteur.h"
#include "pid.h"


//mode: 1. avancer jusqu'a une distance 2. avancer jusqu'a un obstable
//distance: la distance a parcourir en cm (pas important en mode IR)
//vitesse: la vitesse en % a laquelle le robot doit aller
void avancerDroit(int mode, int distance, int vitesse){
	
	float distanceParcourue = 0;
	int cochesGauche = 0, cochesDroite = 0;
	int delaiAdaptatif = DELAI_LECTURE;
	
	int erreur = 0;
	int sommeErreurs = 0;
	int erreurPrecedente = 0;
	
	float correctionP = 0;
	float correctionI = 0;
	float correctionD = 0;
	
	//Preparation a avancer
	MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesse);
	cochesGauche = ENCODER_Read(ENCODER_LEFT);
	cochesDroite = ENCODER_Read(ENCODER_RIGHT);
	
	while ((mode == 1 && distanceParcourue < distance) || (mode == 2 && IR_Detect() == 0)){
		delaiAdaptatif *= DECALAGE_LECTURE;
		
		cochesGauche = ENCODER_Read(ENCODER_LEFT);
		cochesDroite = ENCODER_Read(ENCODER_RIGHT);
		
		distanceParcourue += (cochesGauche + cochesDroite) / 2 * CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES;
		
		erreurPrecedente = erreur * DECALAGE_LECTURE;
		erreur = cochesGauche - cochesDroite;
		sommeErreurs += erreur;
		
		correctionP = correctionProportionnelle(erreur);
		correctionI = correctionIntegrative(sommeErreurs);
		correctionD = correctionDerivative(erreur, erreurPrecedente, delaiAdaptatif);
		
		appliquerCorrection(correctionP, correctionI, correctionD);
		ajusterVitesseMoteurs(vitesse);
		
		Thread_MSleep(delaiAdaptatif);
	}
}