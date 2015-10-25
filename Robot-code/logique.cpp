#include "logique.h"
#include <libarmus.h>
#include <valeurs.h>
#include <capteurs.h>
#include <pid.h>

//code pour logique ici
int StratNinja(){
	SignalDepartNinja();
	avancer = 1;
	avancerDroit(ARRET_EXTERNE, 50, 60);
	THREAD_MSleep(2000);
	avancer = 0;


	return 0;
}

int partirThreadCapteurs(){

	while (conditionArret == 0){
		conditionArret = Lire5kHz();
		couleur = lireCouleur();
		lireCapteurLigne();
		lireBumpers();

		THREAD_MSleep(50);
	}

	return 0;
}

