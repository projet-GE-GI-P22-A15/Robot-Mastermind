/** @file capteurs.h
 *  @brief Les prototypes de function pour les capteurs.
 *
 *  @author Marc-Antoine Lalonde (Bloodae) 
 *  @author Pascal Vaillancourt (scoremoregoals)
 *  @author Anthony Parris (MrParris)
 *  
 *  @bug No known bugs.
 */

#ifndef LOGIQUE_H_
#define LOGIQUE_H_

//FONCTIONS POUR LA LOGIQUE DU ROBOT


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
debugAffichage(int direction,int &tableauAVerif[4], int &tableauDeJeu[4], int nbrLecture, int nbrCouleurOK, int nbrBonnePosition);


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
int verifNbrCouleurABonnePlace(int direction,int &tableauAVerif[4], int &tableauDeJeu[4]);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param tableauAVerif [description]
 * @param tableauDeJeu [description]
 * 
 * @return [description]
 */
int verifNbrCouleurOK(int direction, int &tableauAVerif[4], int &tableauDeJeu[4]);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param ledsJeux [description]
 */
void jeuxLedCouleurContreHumain(int &ledsJeux[4]);

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




#endif // LOGIQUE_H_
