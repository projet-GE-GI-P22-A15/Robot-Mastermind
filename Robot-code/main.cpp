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
#include <pid.h>
#include <rotation.h>
#include <valeurs.h>

int roulerParcoursAller();
int roulerParcoursRetour();

int main() {
	avancerDroit(1, 100, 100);

	return 0;
}

int roulerParcoursAller() {
	// À l'endroit
	avancerDroit(1, 222, 100); 	//222.5
	tourner(90, GAUCHE);		//90
	avancerDroit(1, 48, 100); 	//47.5**
	tourner(90, DROITE);		//90
	avancerDroit(1, 45, 100);	//45
	tourner(90, DROITE);		//90
	avancerDroit(1, 48, 100); 	//47.5 ou == **
	tourner(90, GAUCHE);		//90
	avancerDroit(1, 31, 100); 	//31.2
	tourner(45, DROITE);		//45
	avancerDroit(1, 67, 100); 	// 67.2
	tourner(90, GAUCHE);		//90
	avancerDroit(1, 73, 100); 	// 73.2
	tourner(45, DROITE);		//45
	avancerDroit(1, 47, 100); 	// 47.5
	tourner(12, DROITE);		//12.5
	avancerDroit(1, 75, 100); 	// 73.5

	return 0;
}

int roulerParcoursRetour() {
	//À l'envers
	tourner(180, GAUCHE);

	avancerDroit(1, 75, 100); 	//73.5
	tourner(12, GAUCHE);		//12.5
	avancerDroit(1, 47, 100); 	//47.5
	tourner(45, GAUCHE);
	avancerDroit(1, 73, 100); 	// 73.2
	tourner(90, DROITE);
	avancerDroit(1, 67, 100); 	//67.2
	tourner(45, GAUCHE);
	avancerDroit(1, 31, 100); 	//31.2
	tourner(90, DROITE);
	avancerDroit(1, 48, 100); 	// 47.5**
	tourner(90, GAUCHE);
	avancerDroit(1, 45, 100); 	// 45
	tourner(90, GAUCHE);
	avancerDroit(1, 48, 100); 	// 47.5 ou **
	tourner(90, DROITE);
	avancerDroit(1, 200, 100);	//200

	return 0;
}
