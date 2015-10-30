/** @file capteurs.h
 *  @brief Les prototypes de function pour les capteurs.
 *
 *  @author Marc-Antoine Lalonde (Bloodae)
 *  
 *  @bug No known bugs.
 */

#ifndef ROTATION_H_
#define ROTATION_H_

/**
 * @brief Fonction de tourner d'un sens
 * @details Tourner selon la circonference de la roue et tourne avec les deux roues
 * 
 * @param angle Angle de rotation de 0 a 180
 * @param direction Direction Gauche ou droite
 */
void tourner(int angle, int direction);

/**
 * @brief Tourner dans un sens
 * @details Tourner selon la circonference de la roue et les encodeurs. Tourne seulement avec une roue
 * 
 * @param angle Angle de rotation de 0 a 180
 * @param direction Direction Gauche ou droite
 */
void tournerAlt(int angle, int direction);

#endif /* ROTATION_H_ */
