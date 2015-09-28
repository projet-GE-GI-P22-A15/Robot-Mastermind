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
#define GAUCHE 1
#define DROITE -1

extern float vitesseDroitePRGauche; 	//vitesseDroite / vitesseGauche
extern float CIRCONFERENCE_ROUE; 	// 3" * PI, en cm. a tweaker.
extern float CIRCONFERENCE_ROTATION; //distance parcourue par les roues lorsque le robot tourne de 360 degres sur lui-meme
extern int NOMBRE_DIVISIONS_ROUES; 	//nombre de coches sur la roue
extern int DELAI_LECTURE; 			//delai entre les lectures d'encodeur, en ms

#endif /* VALEURS_H_ */
