#include <valeurs.h>

#define ARRET_DISTANCE 1
#define ARRET_INFRAROUGE 2
#define GAUCHE 1
#define DROITE -1

float vitesseDroitePRGauche = 1.03; 	//vitesseDroite / vitesseGauche
float CIRCONFERENCE_ROUE = 24.462; 	// NE PAS MODIFIER CETTE VALEUR
float CIRCONFERENCE_ROTATION = 44.462; //NE PAS MODIFIER. distance parcourue par les roues lorsque le robot tourne de 360 degres sur lui-meme.
int NOMBRE_DIVISIONS_ROUES = 64; 	//nombre de coches sur la roue
int DELAI_LECTURE = 100; 			//delai entre les lectures d'encodeur, en ms
int execution = 0;
