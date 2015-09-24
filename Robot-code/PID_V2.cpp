#include <libarmus.h>

float vitesseDroitePRGauche = 1.073; 	//vitesseDroite / vitesseGauche
float CIRCONFERENCE_ROUE = 25.1; 	// 3" * PI, en cm. a tweaker.
int NOMBRE_DIVISIONS_ROUES = 64; 	//nombre de coches sur la roue
int DELAI_LECTURE = 100; 			//delai entre les lectures d'encodeur, en ms

void avancerDroit(int mode, int distance, int vitesse);
float correctionProportionnelle(int erreur, int vitesse);
float correctionIntegrative(int sommeErreurs);
float correctionDerivative(int erreur, int erreurPrecedente);
void appliquerCorrection(float correctionP, float correctionI, float correctionD);
void ajusterVitesseMoteurs(int vitesse);

int main(){
	int distance = (int)(2.54 * 200);
	avancerDroit(1, distance, 100);

	return 0;
}

//mode: 1. avancer jusqu'a une distance 2. avancer jusqu'a un obstable
//distance: la distance a parcourir en cm (pas important en mode IR)
//vitesse: la vitesse en % a laquelle le robot doit aller
void avancerDroit(int mode, int distance, int vitesse){
	float distanceParcourue = 0;
	int cochesGauche = 0, cochesDroite = 0;

	int erreur = 0;
	int sommeErreurs = 0;
	int erreurPrecedente = 0;

	float correctionP = 0;
	float correctionI = 0;
	float correctionD = 0;

	//Preparation a avancer
	ajusterVitesseMoteurs(vitesse);
	THREAD_MSleep(50);
	cochesGauche = ENCODER_Read(ENCODER_LEFT);
	cochesDroite = ENCODER_Read(ENCODER_RIGHT);

	while ((mode == 1 && distanceParcourue < distance) || (mode == 2 && IR_Detect(IR_FRONT) == 0)){
		cochesGauche = ENCODER_Read(ENCODER_LEFT);
		cochesDroite = ENCODER_Read(ENCODER_RIGHT);

		distanceParcourue = distanceParcourue + (((cochesGauche + cochesDroite) / 2) * (CIRCONFERENCE_ROUE / NOMBRE_DIVISIONS_ROUES));

		erreurPrecedente = erreur;
		erreur = cochesGauche - cochesDroite;
		sommeErreurs += erreur;

		correctionP = correctionProportionnelle(erreur, vitesse);
		correctionI = correctionIntegrative(sommeErreurs);
		//correctionD = correctionDerivative(erreur, erreurPrecedente);

		appliquerCorrection(correctionP, correctionI, correctionD);
		ajusterVitesseMoteurs(vitesse);

		LCD_Printf("Var: %f\n", vitesseDroitePRGauche);

		THREAD_MSleep(DELAI_LECTURE);
	}

	if (mode == 2){
		avancerDroit(1, 180, vitesse);
	}
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}

//Determine l'importance de la proportion de l'erreur dans le PID
float correctionProportionnelle(int erreur, int vitesse){
	float FACTEUR_CORRECTION_P = 0.015;

	float correction = erreur * FACTEUR_CORRECTION_P;
	return correction;
}

//Corrige l'erreur en prenant en compte les erreurs passees (offset)
float correctionIntegrative(int sommeErreurs){
	float FACTEUR_CORRECTION_I = 0.009;

	float correction = sommeErreurs * FACTEUR_CORRECTION_I;
	return correction;
}

//Corrige l'erreur en prevoyant les erreurs futures
float correctionDerivative(int erreur, int erreurPrecedente){
	float FACTEUR_CORRECTION_D = 0.001;

	//correction = deltaErreur * temps. (mais tweake un peu)
	float correction = (erreur - erreurPrecedente) * FACTEUR_CORRECTION_D;
	return correction;
}

//Ajuste le facteur correctif des moteurs en fonction du PID
void appliquerCorrection(float correctionP, float correctionI, float correctionD){
	vitesseDroitePRGauche += correctionP + correctionI + correctionD;
}

//
void ajusterVitesseMoteurs(int vitesse){
	int vitesseGauche = vitesse;
	int vitesseDroite = (int)(vitesse * vitesseDroitePRGauche);

	if (vitesseDroite > 100){
		vitesseDroite = 100;
		vitesseGauche = (int)(100 / vitesseDroitePRGauche);
	}else if (vitesseDroite < -100){
		vitesseDroite = -100;
		vitesseGauche = (int)(100 / vitesseDroitePRGauche);
	}
	MOTOR_SetSpeed(MOTOR_LEFT, vitesseGauche);
	MOTOR_SetSpeed(MOTOR_RIGHT, vitesseDroite);
}


void tournerAngle(int vitesse, int angle){
	int cochesGaucheDepart = 0;
	int cochesDroiteDepart = 0;
	int cochesGauche = 0;
	int cochesDroite = 0;
	int tempAngle = 0;
	int degree64Encoches = 35;

	cochesGaucheDepart = ENCODER_Read(ENCODER_LEFT);
	cochesDroiteDepart = ENCODER_Read(ENCODER_RIGHT);
	while(tempAngle != angle){
		cochesGauche = (ENCODER_Read(ENCODER_LEFT) - cochesGaucheDepart);
		cochesDroite = (ENCODER_Read(ENCODER_RIGHT) - cochesDroiteDepart);

		//Circonference de la roue pi*76mm == 238,7 mm ou 28.87cm
		//A faire tourner 64 coches les 2 roues et trouver le degree --> degree64Encoches
		//NombreMagic / le nombre d<encoche
		MOTOR_SetSpeed(MOTOR_LEFT, vitesse);
		MOTOR_SetSpeed(MOTOR_RIGHT, vitesse);

	}
}
