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
	int essai,pastille;
	suivreLigne();
	for(essai=0;essai<10;essai++)
	{
		for(pastille=0;pastille<4;pastille++)
		{
			if (lireCouleur()==jaune)
				verifNbrCouleurOK(essai);

		}
	}

	THREAD_MSleep(50);	// Sleep for 50ms
	return 0;
}
/****************************************************************/
void stockerCouleur(int direction,int couleur)
{

}
/****************************************************************/
int mainCapteur() {
	 capt_ligne = lireCapteurLigne();
	 capt_bumper = lireBumpers();
	 capt_couleur = lireCouleur();
	 capt_bouton=lireBoutonPhysique();
	 THREAD_MSleep(10);
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
int verifNbrCouleurOK(int ligne) {
	//Retourne le nombre de couleur qui sont correct
	int i = 0;
		for (i = 0; i < 4; i++)
		{
			if (tableau_de_joueur[i][ligne] == tableau_de_robot[0] ||
					tableau_de_joueur[i][ligne] == tableau_de_robot[1] ||
					tableau_de_joueur[i][ligne] == tableau_de_robot[2] ||
					tableau_de_joueur[i][ligne] == tableau_de_robot[3])
				tableau_a_verifier[i][ligne] = jaune;
			else
				tableau_a_verifier[i][ligne] = fermer;
		}
		return 0;
}
/****************************************************************/
int verifNbrCouleurABonnePlace(int ligne) {
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (tableau_a_verifier[i][ligne] == jaune)
			{
				if (tableau_de_joueur[i][ligne] == tableau_de_robot[i])
					tableau_a_verifier[i][ligne] = vert;
			}
	}
	return 0;
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

