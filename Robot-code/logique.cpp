#include "logique.h"
#include <libarmus.h>
#include "valeurs.h"
#include "capteurs.h"
#include "mouvement.h"
#include "matrixLED.h"

int capt_ligne, capt_bumper, capt_couleur, capt_bouton;

int tableau_a_verifier[4][10];
int tableau_de_joueur[4][10];
int tableau_de_robot[4];
/********************************************************************************/
int mainCRJ() {
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
/****************************************************************/
int mainCapteur() {
	/*capt_ligne = lireCapteurLigne();
	 capt_bumper = lireBumpers();
	 capt_couleur = lireCouleur();
	 capt_bouton=lireBoutonPhysique();
	 THREAD_MSleep(10);*/
	return 0;
}
/*****************************************************************/
int randomGeneratedNumbers() {
	int choixCouleur = rand() % 8;
		return choixCouleur;
	return 0;
}
/****************************************************************/
void jeuxLedCouleurContreHumain() {
	srand ( time(NULL));
		tableau_de_robot[0] = randomGeneratedNumbers();
		tableau_de_robot[1] = randomGeneratedNumbers();
		tableau_de_robot[2] = randomGeneratedNumbers();
		tableau_de_robot[3] = randomGeneratedNumbers();
}
/***************************************************************/
int verifNbrCouleurOK(int direction, int ligne) {
	//Retourne le nombre de couleur qui sont correct
	/*int count;
	 if (direction==0){
	 for (count=0;count<=3;count++){
	 if (tableau_de_joueur[count][ligne]==tableau_de_robot[count])
	 tableau_a_verifier[count]=jaune;
	 else
	 tableau_a_verifier[count]=fermer;
	 count++;
	 }
	 }
	 else{
	 for (count=3;count<=0;count--){
	 if (tableau_de_joueur[count][ligne]==tableau_de_robot[count])
	 tableau_a_verifier[count]=jaune;
	 else
	 tableau_a_verifier[count]=fermer;
	 }
	 }*/
	return 0;
}
/****************************************************************/
int verifNbrCouleurABonnePlace(int direction, int ligne) {
	int compteurBonnePlace = 0;
		if (direction == 0)
		{
			int i = 0;
			for (i = 0; i < 4; i++)
			{
				if (tableau_a_verifier[i][ligne] == fermer)
				//Verifie si la valeur a ete changee a fermer par verifNbrCouleurOK(),
				//donc si elle est soit bonne et a la bonne place ou simplement pas bonne
				{
					if (tableau_de_joueur[i][ligne] == tableau_de_robot[i])
					{
						tableau_a_verifier[i][ligne] = vert;
					}
					else
					{
						tableau_a_verifier[i][ligne] = rouge;
					}
				}
			}
		}
		else
		{
			int i = 0;
			for (i = 3; i >= 0; i--)
			{
				if (tableau_a_verifier[i][ligne] == fermer)
				{
					if (tableau_de_joueur[i][ligne] == tableau_de_robot[i])
					{
						tableau_a_verifier[i][ligne] = vert;
					}
					else
					{
						tableau_a_verifier[i][ligne] = rouge;
					}
				}
			}
		}
}
/****************************************************************/
void victoire() {
	AUDIO_SetVolume(100);
	AUDIO_PlayFile("jaigagner.mp3");
	tourner(45,GAUCHE);
	tourner(90,DROITE);
	tourner(90,GAUCHE);
	tourner(90,DROITE);
	tourner(360,GAUCHE);
	tourner(360,DROITE);
	tourner(45,GAUCHE);

}
/****************************************************************/
void defaite() {
	// Il manque a faire le fichier jaiperdu
	AUDIO_SetVolume(90);
	/*AUDIO_PlayFile("jaiperdu.mp3");*/
	tourner(180,GAUCHE);
	THREAD_MSleep(3000);
	tourner(180,DROITE);
}
/****************************************************************/
int debugAffichage(int direction, int tableauAVerif[4], int tableauDeJeu[4],
		int nbrLecture, int nbrCouleurOK, int nbrBonnePosition) {
	//affiche toutes les choses possible
	return 0;
}
/******************************************************************/
int gestionAvantDeCommencer() {
	//Ici cest le setup de game et les parametres de gestion avant de commencer la lecture et toute
	return 0;
}
/******************************************************************/
int easterEgg() {
	return 0;
}
/*******************************************************************/

