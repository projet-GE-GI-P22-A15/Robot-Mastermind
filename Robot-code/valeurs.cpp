#include "valeurs.h"

float vitesseDroitePRGauche = 1.1; 	//46: 1.18  --  47: 1.1
float CIRCONFERENCE_ROUE = 24.462; 	// NE PAS MODIFIER CETTE VALEUR
float CIRCONFERENCE_ROTATION = 44.47; //44.462NE PAS MODIFIER. distance parcourue par les roues lorsque le robot tourne de 360 degres sur lui-meme.
int NOMBRE_DIVISIONS_ROUES = 64; 	//nombre de coches sur la roue
int DELAI_LECTURE = 100; 			//delai entre les lectures d'encodeur, en ms

int couleur = 0;
int lastCouleur = 0;
int ligneGauche = 0;
int ligneCentre = 0;
int ligneDroite = 0;

int bumperAvant = 0;
int bumperArriere = 0;
int bumperDroite = 0;
int bumperGauche = 0;
