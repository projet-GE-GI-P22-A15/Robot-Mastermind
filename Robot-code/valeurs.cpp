#include <valeurs.h>

#define ARRET_DISTANCE 1
#define ARRET_INFRAROUGE 2
#define GAUCHE 1
#define DROITE -1

float vitesseDroitePRGauche = 1.195; 	//46: 1.21  --  47: 0.97
float CIRCONFERENCE_ROUE = 24.462; 	// NE PAS MODIFIER CETTE VALEUR
float CIRCONFERENCE_ROTATION = 44.47; //44.462NE PAS MODIFIER. distance parcourue par les roues lorsque le robot tourne de 360 degres sur lui-meme.
int NOMBRE_DIVISIONS_ROUES = 64; 	//nombre de coches sur la roue
int DELAI_LECTURE = 100; 			//delai entre les lectures d'encodeur, en ms
int execution = 0;
