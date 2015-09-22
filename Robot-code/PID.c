#include <libarmus>

float vitesseDroitePRGauche = 1; 	//vitesseDroite / vitesseGauche
float CIRCONFERENCE_ROUE = 7.9796; 	// 3" * PI, en cm. a tweaker.
int NOMBRE_DIVISIONS_ROUES = 16; 	//nombre de coches sur la roue
int DELAI_LECTURE = 500; 			//delai entre les lectures d'encodeur, en ms
int DECALAGE_LECTURE = 1.1; 		// est utilise pour augmenter le delai entre chaque lecture d'encodeur avec le temps pour plus de precision.

int main(){
	avancerDroit(1, 100, 100);

	return 0
}

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





