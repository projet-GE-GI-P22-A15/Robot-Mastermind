/*
 * mouvement.h
 *
 *  Created on: 2015-11-15
 *      Author: blood
 */

#ifndef MOUVEMENT_H_
#define MOUVEMENT_H_

/**
 * @brief Correction proportionel pour l'avacement d'un moteur
 * @details Action proportionnelle : l'erreur est multipliee par un gain G
 *
 * @param cochesGauche Roue encodeur de gauche elle possede 64 encoches
 * @param cochesDroite Roue encodeur de droite elle possede 64 encoches
 *
 * @return Valeur de l'erreur fois le gain
 */
void avancerDroit(int mode, int distance, int vitesse);

/**
 * @brief Correction proportionnelle entre 2 roues
 * @details La fonction fait la correction proportionnelle, donc un gain trouver en faisant des tests, de l'erreur entre les deux roues
 *
 * @param erreur Erreur entre les deux lectures des roues
 * @param vitesse Vitesse desiree entre 0 a 100
 *
 * @return La valeur corrigee avec le gain Proportionnelle
 */
float correctionProportionnelle(int erreur, int vitesse);

/**
 * @brief Correction integrative
 * @details Cela corrige la diff�rence les roues avec un facteur correctif selon la somme des erreurs depuis le d�but.
 *
 * @param sommeErreurs Les erreurs additionnes auparavant
 * @return La valeur corrigee avec le gain Integrale
 */
float correctionIntegrative(int sommeErreurs);

/**
 * @brief Correction derivee
 * @details A ne pas utiliser
 *
 * @param erreur erreur present
 * @param erreurPrecedente erreur calcule avant le tour d'avant
 *
 * @return La valeur de la correction derivee
 */
float correctionDerivative(int erreur, int erreurPrecedente);

/**
 * @brief Appliquer les corrections pour les moteurs
 * @details La correction est fait comme ceci Vittesse de la roue = Correction Proportionnelle + Correction Integrale - Correction Derivee
 *
 * @param correctionP Correction proportionnelle
 * @param correctionI Correction integrale
 * @param correctionD Correction derivee
 */
void appliquerCorrection(float correctionP, float correctionI,
		float correctionD);

/**
 * @brief Change la vitesse selon avec le PID
 * @details Change la vitesse d'une des 2 roues en aplliquant le resultat de la fonction appliquerCorrection
 *
 * @param vitesse La vitesse voulue
 */
void ajusterVitesseMoteurs(int vitesse);

/**
 * @brief Fonction de tourner d'un sens
 * @details Tourner selon la circonference de la roue et tourne avec les deux roues
 *
 * @param angle Angle de rotation de 0 a 180
 * @param direction Direction Gauche ou droite
 */
void tourner(int angle, int direction);

/**
 * @brief Tourner dans un sens
 * @details Tourner selon la circonference de la roue et les encodeurs. Tourne seulement avec une roue
 *
 * @param angle Angle de rotation de 0 a 180
 * @param direction Direction Gauche ou droite
 */
void tournerAlt(int angle, int direction);


void suivreLigne();
#endif /* MOUVEMENT_H_ */
