/**
 * 	Code cree par l'equipe d'Ingenium Natus
 * 	
 * 	Pascal Vaillancourt
 * 	Marc-Antoine Lalonde
 * 	Cedrik Maillet
 * 	Pierre-Geoffroy 
 * 	Alexis Morel
 * 	Patrick Beaulieu
 * 	Amazigh Abibsi
 * 	Justin Beaulieu
 * 	Anthony Parris
 */

#ifndef CONTROLMOTEUR_H_   /* Include guard */
#define CONTROLMOTEUR_H_

#define NOMBRE_DIVISIONS_ROUES = 16; 	//nombre de coches sur la roue
#define DELAI_LECTURE = 500; 			//delai entre les lectures d'encodeur, en ms
#define DECALAGE_LECTURE = 1.1; 		// est utilise pour augmenter le delai entre chaque lecture d'encodeur avec le temps pour plus de precision.


float vitesseDroitePRGauche = 1; 	//vitesseDroite / vitesseGauche
float CIRCONFERENCE_ROUE = 7.9796; 	// 3" * PI, en cm. a tweaker.

/**
 * @brief Fonction qui fait avancer le robot
 * @details Fait avancer le robot tout en ayant un suivi avec le code de PID
 * 
 * @param mode voir pid pour plus d'information
 * @param distance la distance 
 * @param vitesse la vitesse
 */
void avancerDroit(int mode, int distance, int vitesse);

#endif // CONTROLMOTEUR_H_