#include "logique.h"
#include <libarmus.h>
#include "valeurs.h"
#include "capteurs.h"
#include "pid.h"
#include "rotation.h"
#include "matrixLED.h"

//code pour logique ici
int mainCRJ(){
	//ne pas faire une boucle while, car je fais letat du fonctionnement dans le main!!!!!! et la boucle est dans le main
	//Si return == 1 DESTROY LE THREAD, si 0 sa continue le thread

	//faire le code general de notre robot final

	//Checker si gestionAvantDeCommencer() == 1 avant de commencer

	//checker si les boutons de depart sont clique pour lire ligne
	//checker si le bouton ligne fini est clique

	//faire rouler sur la premiere ligne de couleur

	//tableau de leds a affronter et l'assigner a le tableau formatter jeuxLedCouleurContreHumain(tableau)
	//il va etre faite comme ci a gauche cest lindice 0 du tableau  jusqua 4 vers la droite

	//Nbr de couleurOK
	//Nbr de couleur a bonne place
	//Est ce quil a gagner? selon le nombre de fois / afficher victoire et petite danse
	//Est ce quil a perdu? selon le nombre de fois / afficher defaite et faire quelque chose

	//Set tableau premiere ligne, deuxieme ligne, etc. ou dans un genre de list ou hashmap

	//Format la matrice de dels
	//Affiche la matrice de dels

	//Compte le nombre de fois qu'il a fait une ranger pour savoir le tableau a utilise ou dans le hashmap/list

	//fait la ligne de l'autre bord et dire a une variable de faire le trajet inverse pour que les tableaux soit bien fait
	
	//et boucler le tout jusqu'a temps qu'il y a une victoire / defaite


	THREAD_MSleep(50);	// Sleep for 50ms
	return 0;
}

int mainCapteur(){
 lireBumpers();
 lireCapteurLigne();
 lireCouleur();
 int lireBoutonPhysique();
THREAD_MSleep(10);	// Execute a tous les 10ms
return 0;
}

/*****************************************************************/


int randomGeneratedNumbers(){
	// Probablement utiliser des pointeurs pour le tableau ou le mettre en variable global. 
	// Il y a une libraire en C pour faire des randoms generated numbers je l'ai deja fait :P


	// retourne la valeur du nombre generer
	return 0;
}

void jeuxLedCouleurContreHumain(int &ledsJeux[4]){
	// Appelle 5 fois selon la largeur du jeu pour avoir les couleurs contre quoi on va jouer
	// Cree le tableau et apres que tout est formatter le tableau passe en pointeur.  http://www.hermetic.ch/cfunlib/ast_amp2.htm en bas de la page sa explique le tout

}

int verifNbrCouleurOK(int direction, int &tableauAVerif[4], int &tableauDeJeu[4]){
	//Retourne le nombre de couleur qui sont correct
	return 0;
}

int verifNbrCouleurABonnePlace(int direction,int &tableauAVerif[4], int &tableauDeJeu[4]){
	//Retourne le nombre de couleur qui sont correct et a la bonne place
	return 0;
}

void victoire(){
	//Lui faire dire j'ai Gagné! en boucle pendant genre 5secondes
	while (ENCODER_read==0{
	MOTOR_SetSpeed(MOTOR_LEFT,0);
	MOTOR_SetSpeed(MOTOR_RIGHT,50);
	}

	MOTOR_SetSpeed(MOTOR_RIGHT,0);
	MOTOR_SetSpeed(MOTOR_LEFT,50);

}

void defaite(){

}

int debugAffichage(int direction,int &tableauAVerif[4], int &tableauDeJeu[4], int nbrLecture, int nbrCouleurOK, int nbrBonnePosition){
	//affiche toutes les choses possible
	return 0;
}

int gestionAvantDeCommencer(){
	//Ici cest le setup de game et les parametres de gestion avant de commencer la lecture et toute
	return 0;
}

int easterEgg(){
	return 0;
}

int lineFollower() {
	if (ligneCentre == 0) {
		return 2;
	} else if (ligneGauche == 0) {
		return 1;
	} else if (ligneDroite == 0) {
		return 3;
	} else {
		return 0;
	}
}
