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
#define bleu 0
#define vert 1
#define rouge 2
#define jaune 3
#define mauve 4
#define orange 5
#define cyan 6
#define rose 7
#define fermer 8

#define DIRECTION_gd 0
#define DIREECTION_dg 1

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
int debugAffichage(int direction,int tableauAVerif[4], int tableauDeJeu[4], int nbrLecture, int nbrCouleurOK, int nbrBonnePosition);


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
int verifNbrCouleurABonnePlace(int direction,int tableauAVerif[4], int tableauDeJeu[4]);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param tableauAVerif [description]
 * @param tableauDeJeu [description]
 * 
 * @return [description]
 */
int verifNbrCouleurOK(int direction, int tableauAVerif[4], int tableauDeJeu[4]);

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
int lineFollower();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int mainCRJ();

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
int mainCapteur();
int capt_ligne,capt_bumper,capt_couleur,capt_bouton;

int tableau_a_verifier[4][10];
int tableau_de_joueur[4][10];
int tableau_de_robot[4];
#endif // LOGIQUE_H_
