/*
 * valeurs.h
 *
 *  Created on: 2015-09-25
 *      Author: blood
 */

#ifndef VALEURS_H_
#define VALEURS_H_

#define ARRET_DISTANCE 1
#define ARRET_INFRAROUGE 2
#define ARRET_EXTERNE 3
#define GAUCHE 1
#define DROITE -1

/**
 * vitesseDroite / vitesseGauche
 */
extern float vitesseDroitePRGauche;

/**
 * 3" * PI, en cm
 */
extern float CIRCONFERENCE_ROUE;

/**
 * Distance parcourue par les roues lorsque le robot tourne de 360 degres sur lui-meme
 */
extern float CIRCONFERENCE_ROTATION;

/**
 * Nombre de coches sur la roue
 */
extern int NOMBRE_DIVISIONS_ROUES;

/**
 * Delai entre les lectures d'encodeur, en ms
 */
extern int DELAI_LECTURE;

/**
 * Sert au controle du robot avec les bumpers
 */
extern int conditionArret;

extern int couleurCible;
extern int avancer;
extern int couleur;
extern int ligneGauche;
extern int ligneCentre;
extern int ligneDroite;
extern int bumperAvant;
extern int bumperArriere;
extern int bumperDroite;
extern int bumperGauche;
#endif /* VALEURS_H_ */
