#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "mbed.h"


/**
 * @brief Communication de l'armus à mbed
 * @details Gestion de la communication de serie entre l'Armus et le microcontroleur MBED
 * 
 * Structure de communication
 * 
 * 1st byte: '#' | 0x23: Byte de demarrage de donne ou recevoir
 * 2nd byte: '$' | 0x24: Prochains bytes ==  Envoie de lettres ou chiffres
 * et ensuite les lettres, les chiffres et les carateres en ascii
 * 
 * 2nd byte: '%' | 0x25: Prochains bytes == Etat du jeu
 * 3rd, 4th, 5th, 6th byte: Bonne couleur bonne place = '2'; Bonne couleur mauvaise place = '1'; mauvaise couleur = '0';
 * 7th byte: Victoire = 2; Défaite = 1; Neutre = 0;
 * 
 * 
 * end byte: '!' | 0x21: Fin de l'envoie / reception
 * 
 * ERROR byte: '+' | 0x2B: Envoie le byte '+' pis recommence la communication
 * 
 */
 
class COMMUNICATION {
public:
	char* getTableauLettre();
	void logiqueSerie();
	void Init();
private:

};

#endif