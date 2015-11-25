#include "logique.h"
#include <libarmus.h>
#include "valeurs.h"
#include "capteurs.h"
#include "mouvement.h"
#include "matrixLED.h"
#include "charma.h"

int capt_ligne, capt_bumper, capt_couleur, capt_boutonEssai,
		capt_boutonNbPastilles;
int nbPastilles = 2;
int tableau_a_verifier[4][10];
int tableau_de_joueur[4][10];
int tableau_de_robot[4];
formatEnvoi formatEnvoiArray[10];
char formatEssai[9];
/********************************************************************************/
int mainCRJ() {
	/*
	 gestionAvantDeCommencer();

	 int essai, pastille = 0;
	 int direction = 1;
	 int gagner = 0;
	 while (essai != 10 || gagner != 1) {
	 while (capt_boutonEssai == 1) {
	 suivreLigne();
	 if (direction == 1) {
	 while (pastille != nbPastilles) {
	 int couleurCaptee = lireCouleur();
	 if (couleurCaptee != blanc) {
	 stockerCouleur(couleurCaptee, essai, pastille);
	 pastille++;
	 do {
	 int couleur = lireCouleur();
	 THREAD_MSleep(200);
	 } while (couleur != blanc);
	 }
	 }
	 direction *= (-1);
	 MOTOR_SetSpeed(MOTOR_LEFT, 0);
	 MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	 tourner(180, DROITE);
	 } else {
	 pastille = (nbPastilles - 1);
	 while (pastille != (-1)) {
	 int couleurCaptee = lireCouleur();
	 if (couleurCaptee != blanc) {
	 stockerCouleur(couleurCaptee, essai, pastille);
	 pastille--;
	 do {
	 int couleur = lireCouleur();
	 THREAD_MSleep(200);
	 } while (couleur != blanc);
	 }
	 }
	 direction *= (-1);
	 MOTOR_SetSpeed(MOTOR_LEFT, 0);
	 MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	 }
	 THREAD_MSleep(200);
	 verifNbrCouleurOK(essai);
	 verifNbrCouleurABonnePlace(essai);
	 storeDansStructure(essai);
	 envoieStringStructure(essai);
	 debugAffichage(direction, essai);
	 //Ajouter : Fonction d'affichage sur la matrice de LED
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < nbPastilles; i++) {
	 if (tableau_a_verifier[i][essai] == vert)
	 j++;
	 }
	 if (j == nbPastilles)
	 gagner = 1;
	 essai++;
	 }
	 THREAD_MSleep(200);
	 }

	 if (gagner == 1)
	 victoire();
	 else
	 defaite();

	 THREAD_MSleep(50);	// Sleep for 50ms
	 */
	return 0;

}
/******************************************************************/

void stockerCouleur(int couleurCapter, int essai, int numPastille) {
	tableau_de_joueur[numPastille][essai] = couleurCapter;
}
/******************************************************************/
void mainCapteur() {
	while (1) {
		capt_ligne = lireCapteurLigne();
		capt_bumper = lireBumpers();
		capt_couleur = lireCouleur();
		capt_boutonEssai = lireBoutonPhysiqueEssai();
		THREAD_MSleep(20);
	}
}
/******************************************************************/
int randomGeneratedNumbers() {
	int choixCouleur = (rand() % 6) + 1;
	return choixCouleur;
}
/******************************************************************/
void jeuxLedCouleurContreHumain() {
	srand(time(NULL));
	tableau_de_robot[0] = randomGeneratedNumbers();
	tableau_de_robot[1] = randomGeneratedNumbers();
	tableau_de_robot[2] = randomGeneratedNumbers();
	tableau_de_robot[3] = randomGeneratedNumbers();
}
/******************************************************************/
int verifNbrCouleurOK(int ligne) {
	int i = 0;
	for (i = 0; i < nbPastilles; i++) {
		if (tableau_de_joueur[i][ligne] == tableau_de_robot[0]
				|| tableau_de_joueur[i][ligne] == tableau_de_robot[1]
				|| tableau_de_joueur[i][ligne] == tableau_de_robot[2]
				|| tableau_de_joueur[i][ligne] == tableau_de_robot[3])
			tableau_a_verifier[i][ligne] = eJAUNE;
		else
			tableau_a_verifier[i][ligne] = eNOIR;
	}
	return 0;
}
/******************************************************************/
int verifNbrCouleurABonnePlace(int ligne) {
	int i = 0;
	for (i = 0; i < nbPastilles; i++) {
		if (tableau_a_verifier[i][ligne] == eJAUNE) {
			if (tableau_de_joueur[i][ligne] == tableau_de_robot[i])
				tableau_a_verifier[i][ligne] = eVERT;
		}
	}
	return 0;
}
/******************************************************************/
void victoire() {
	AUDIO_SetVolume(100);
	AUDIO_PlayFile("jaigagner.mp3");
	tourner(45, GAUCHE);
	tourner(90, DROITE);
	tourner(90, GAUCHE);
	tourner(90, DROITE);
	tourner(360, GAUCHE);
	tourner(360, DROITE);
	tourner(45, GAUCHE);

}
/******************************************************************/
void defaite() {
	// Il manque a faire le fichier jaiperdu
	AUDIO_SetVolume(90);
	/*AUDIO_PlayFile("jaiperdu.mp3");*/
	tourner(180, GAUCHE);
	THREAD_MSleep(3000);
	tourner(180, DROITE);
}
/******************************************************************/
int debugAffichage(int direction, int essai) {
	int i = 0;
	LCD_Printf("Debogage\n");
	LCD_Printf("Direction : %d\n", direction);
	LCD_Printf("No essai : %d\n", essai);
	for (i = 0; i < nbPastilles; i++) {
		LCD_Printf("Ligne joueur :\n%d %d %d %d\n",
				tableau_de_joueur[i][essai]);
	}
	for (i = 0; i < nbPastilles; i++) {
		LCD_Printf("Ligne robot:\n%d %d %d %d\n", tableau_de_robot[i]);
	}
	for (i = 0; i < nbPastilles; i++) {
		LCD_Printf("Ligne a verif:\n%d %d %d %d\n",
				tableau_a_verifier[i][essai]);
	}
	return 0;
}
/******************************************************************/
void gestionAvantDeCommencer() {
	jeuxLedCouleurContreHumain();
	nbPastilles = choixNbPastilles();
	resetTableau();
}
/******************************************************************/
int easterEgg() {
	return 0;
}
/******************************************************************/
int choixNbPastilles() {
	int choixFait = 0;
	int compteur = 2;
	capt_boutonNbPastilles = 0;

	/*Afficher(en gros) ,avec la matrice: Chiffre associé au nombre de pastilles maximales prises en compte par le robot-jouet pour la partie donnée*/
	while (choixFait != 1) {
		capt_boutonNbPastilles = lireBoutonPhysiqueNbPastilles();
		compteur += capt_boutonNbPastilles;
		if (compteur > 4) {
			compteur = 2;
		}
		/*Afficher(en gros) ,avec la matrice: Chiffre associé au nombre de pastilles maximales prises en compte par le robot-jouet pour la partie donnée*/
		choixFait = lireBoutonPhysiqueEssai();
		THREAD_MSleep(200);
	}
	return compteur;
}
/******************************************************************/
void resetTableau() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 10; j++) {
			tableau_de_joueur[i][j] = eNOIR;
			tableau_a_verifier[i][j] = eNOIR;
		}
		tableau_de_robot[i] = eNOIR;
	}
}
/******************************************************************/
void storeDansStructure(int essai) {
	formatEnvoiArray[essai].couleur1 = tableau_de_joueur[0][essai];
	formatEnvoiArray[essai].couleur2 = tableau_de_joueur[1][essai];
	formatEnvoiArray[essai].couleur3 = tableau_de_joueur[2][essai];
	formatEnvoiArray[essai].couleur4 = tableau_de_joueur[3][essai];
	formatEnvoiArray[essai].feedBack1 = tableau_a_verifier[0][essai];
	formatEnvoiArray[essai].feedBack2 = tableau_a_verifier[1][essai];
	formatEnvoiArray[essai].feedBack3 = tableau_a_verifier[2][essai];
	formatEnvoiArray[essai].feedBack4 = tableau_a_verifier[3][essai];
}
/******************************************************************/
void envoieStringStructure(int essai) {
	formatEssai[0] = formatEnvoiArray[essai].couleur1;
	formatEssai[1] = formatEnvoiArray[essai].couleur2;
	formatEssai[2] = formatEnvoiArray[essai].couleur3;
	formatEssai[3] = formatEnvoiArray[essai].couleur4;
	formatEssai[4] = formatEnvoiArray[essai].feedBack1;
	formatEssai[5] = formatEnvoiArray[essai].feedBack2;
	formatEssai[6] = formatEnvoiArray[essai].feedBack3;
	formatEssai[7] = formatEnvoiArray[essai].feedBack4;
	formatEssai[8] = '\0';

	transmettreEssai(essai, formatEssai);
}
