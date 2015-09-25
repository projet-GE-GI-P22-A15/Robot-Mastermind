/*
 * pid.h
 *
 *  Created on: 2015-09-25
 *      Author: blood
 */

#ifndef PID_H_
#define PID_H_

//Déclaration des fonctions, obligatoire en C++
void avancerDroit(int mode, int distance, int vitesse);
float correctionProportionnelle(int erreur, int vitesse);
float correctionIntegrative(int sommeErreurs);
float correctionDerivative(int erreur, int erreurPrecedente);
void appliquerCorrection(float correctionP, float correctionI, float correctionD);
void ajusterVitesseMoteurs(int vitesse);



#endif /* PID_H_ */
