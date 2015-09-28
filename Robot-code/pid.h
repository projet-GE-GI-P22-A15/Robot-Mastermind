/*
 * pid.h
 *
 *  Created on: 2015-09-25
 *      Author: blood
 */

#ifndef PID_H_
#define PID_H_

//Déclaration des fonctions, obligatoire en C++

/**
 * @brief Correction proportionel pour l'avacement d'un moteur
 * @details Action proportionnelle : l'erreur est multipliee par un gain G 
 * 
 * @param cochesGauche Roue encodeur de gauche elle possede 64 encoches
 * @param cochesDroite Roue encodeur de droite elle possede 64 encoches
 * 
 * @return Valeur de l'erreur fois le gain
 */
//Déclaration des fonctions, obligatoire en C++

void avancerDroit(int mode, int distance, int vitesse);
float correctionProportionnelle(int erreur, int vitesse);
float correctionIntegrative(int sommeErreurs);
float correctionDerivative(int erreur, int erreurPrecedente);
void appliquerCorrection(float correctionP, float correctionI,
		float correctionD);
void ajusterVitesseMoteurs(int vitesse);

#endif // PID_H_
