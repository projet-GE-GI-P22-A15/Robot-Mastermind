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

#define BLANC 0
#define ROUGE 1
#define VERT 2
#define BLEU 3
#define JAUNE 4
#define ROSE 5
#define GRIS 6
#define NOIR 7

#define AUCUN_OBSTACLE  0
#define PERPENDICULAIRE 1
#define LIGNE_AU_CENTRE 2
#define LIGNE_A_GAUCHE  3
#define LIGNE_A_DROITE  4

#define PORTMICRO 1
#define PAUSECAFE 200

#define ADJD_S371_QR999_SADR 	0x74
#define CAP_RED					0x6
#define CAP_GREEN				0x7
#define CAP_BLUE				0x8
#define CAP_CLEAR				0x9
#define INTEGRATION_RED			10
#define INTEGRATION_GREEN		12
#define INTEGRATION_BLUE		14
#define INTEGRATION_CLEAR		16
#define ADJD_REG_CTRL			0
#define ADJD_REG_CONFIG			1
#define DATA_RED_LO				64
#define DATA_GREEN_LO			66
#define DATA_BLUE_LO			68
#define DATA_CLEAR_LO			70

#define CTRL_GSSR				0
#define CTRL_GOFS				1

#define CONFIG_TOFS				0

extern int adjd_dev;

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
extern int vitesseGlobale;
extern int angleGlobal;
extern int directionGlobale;
extern int threadQuiRoule;
extern int lastCouleur;
extern int lastLignePosition;
#endif /* VALEURS_H_ */
