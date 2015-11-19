#include "logique.h"
#include <libarmus.h>
#include "valeurs.h"
#include "capteurs.h"
#include "mouvement.h"
#include "matrixLED.h"

int capt_ligne, capt_bumper, capt_couleur, capt_boutonEssai,capt_boutonNbPastilles;
int nbPastilles=2;
int tableau_a_verifier[4][10];
int tableau_de_joueur[4][10];
int tableau_de_robot[4];
/********************************************************************************/
int mainCRJ() {
	
	//gestionAvantDeCommencer();
		
	int essai,pastille = 0;
	int direction = 1;
	int gagner = 0;
	while (essai != 10 || gagner != 1)
	{
		while (capt_boutonEssai == 1)
		{
			suivreLigne();
			if (direction == 1)
			{
				while (pastille != nbPastilles)
				{
					int couleurCaptee = lireCouleur();
					if (couleurCaptee != blanc)
					{
						stockerCouleur(couleurCaptee, essai, pastille);
						pastille ++;
						do
						{
							int couleur = lireCouleur();
							THREAD_MSleep(200);
						} while(couleur != blanc);
					}
				}
				direction *= (-1);
				MOTOR_SetSpeed(MOTOR_LEFT, 0);
				MOTOR_SetSpeed(MOTOR_RIGHT, 0);
				tourner(180, DROITE);
			}
			else
			{
				pastille = (nbPastilles-1);
				while (pastille != (-1))
				{
					int couleurCaptee = lireCouleur();
					if (couleurCaptee != blanc)
					{
						stockerCouleur(couleurCaptee, essai, pastille);
						pastille --;
						do
						{
							int couleur = lireCouleur();
							THREAD_MSleep(200);
						} while(couleur != blanc);
					}
				}
				direction *= (-1);
				MOTOR_SetSpeed(MOTOR_LEFT, 0);
				MOTOR_SetSpeed(MOTOR_RIGHT, 0);
			}

			THREAD_MSleep(200);
			verifNbrCouleurOK(essai);
			verifNbrCouleurABonnePlace(essai);
			//Ajouter : Fonction d'affichage sur la matrice de LED
			int i = 0;
			int j = 0;
			for (i = 0; i < nbPastilles; i++)
			{
				if (tableau_a_verifier[i][essai] == vert)
					j++;
			}
			if (j == nbPastilles)
				gagner = 1;
			essai ++;
		}
		THREAD_MSleep(200);
	}

	if (gagner == 1)
		victoire();
	else
		defaite();

	THREAD_MSleep(50);	// Sleep for 50ms
	return 0;
}
/****************************************************************/
void stockerCouleur(int couleurCapter,int essai,int numPastille)
{
tableau_de_joueur[numPastille][essai]=couleurCapter;
}
/****************************************************************/
int mainCapteur() {
	 capt_ligne = lireCapteurLigne();
	 capt_bumper = lireBumpers();
	 capt_couleur = lireCouleur();
	 capt_boutonEssai=lireBoutonPhysiqueEssai();
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
		for (i = 0; i < nbPastilles; i++)
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
	for (i = 0; i < nbPastilles; i++)
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

int choixNbPastilles(){
	int choixFait=0;
	int compteur=2;
	capt_boutonNbPastilles=0;
	
	/*Afficher(en gros) ,avec la matrice: Chiffre associé au nombre de pastilles maximales prises en compte par le robot-jouet pour la partie donnée*/
	while(choixFait!=1){
	capt_boutonNbPastilles=lireBoutonPhysiqueNbPastilles();
	compteur+=capt_boutonNbPastilles;
	if(compteur>4)
	{
		compteur=2;
	}
	/*Afficher(en gros) ,avec la matrice: Chiffre associé au nombre de pastilles maximales prises en compte par le robot-jouet pour la partie donnée*/
	choixFait=lireBoutonPhysiqueEssai();
	THREAD_MSleep(200);
	}
	return compteur;
}

/*******************************************************************/
