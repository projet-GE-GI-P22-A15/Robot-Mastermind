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

#ifndef PID_H_   /* Include guard */
#define PID_H_


/**
 * @brief Correction proportionel pour l'avacement d'un moteur
 * @details Action proportionnelle : l'erreur est multipliee par un gain G 
 * 
 * @param cochesGauche Roue encodeur de gauche elle possede 64 encoches
 * @param cochesDroite Roue encodeur de droite elle possede 64 encoches
 * 
 * @return Valeur de l'erreur fois le gain
 */
float correctionProportionnelle(int cochesGauche, int cochesDroite);
float correctionIntegrative(int sommeErreurs);
float correctionDerivative(int erreur, int erreurPrecedente, int delaiAdaptatif);
void appliquerCorrection(int correctionP, int correctionI, int correctionD);
void ajusterVitesseMoteurs();


#endif // PID_H_