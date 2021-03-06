/** @file capteurs.h
 *  @brief Les prototypes de function pour les capteurs.
 *
 *  @author Marc-Antoine Lalonde (Bloodae) 
 *  @author Pascal Vaillancourt (scoremoregoals)
 *  @author Anthony Parris (MrParris)
 *  @author Alexis Morel (AlexMo_16)
 *  @bug No known bugs.
 */

#ifndef LOGIQUE_H_
#define LOGIQUE_H_

//FONCTIONS POUR LA LOGIQUE DU ROBOT

#define DIRECTION_gd 0
#define DIREECTION_dg 1

typedef struct formatEnvoi {
	int couleur1;
	int couleur2;
	int couleur3;
	int couleur4;
	int feedBack1;
	int feedBack2;
	int feedBack3;
	int feedBack4;
};

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param direction [description]
 * @param tableauAVerif [description]
 * @param nbrLecture [description]
 * @param nbrCouleurOK [description]
 * @param nbrBonnePosition [description]
 */
int debugAffichage(int direction, int essai);

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int easterEgg();

/**
 * @brief [brief description]
 * @details [long description]
 */
void victoire();

/**
 * @brief [brief description]
 * @details [long description]
 */
void defaite();

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param direction [description]
 * @param tableauAVerif [description]
 * @param tableauDeJeu [description]
 * @return [description]
 */
int verifNbrCouleurABonnePlace(int ligne);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param tableauAVerif [description]
 * @param tableauDeJeu [description]
 * 
 * @return [description]
 */
int verifNbrCouleurOK(int ligne);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param ledsJeux [description]
 */
void jeuxLedCouleurContreHumain(int ledsJeux[4]);

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int randomGeneratedNumbers();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int mainCRJ();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]*/
void mainCapteur();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
void stockerCouleur(int couleurCapter, int esssai, int numPastille);

/**
 * @details [long description]
 * @return [description]
 */
int choixNbPastilles();

void resetTableau();

void gestionAvantDeCommencer();

void storeDansStructure(int essai);

void envoieStringStructure(int essai);

#endif // LOGIQUE_H_
