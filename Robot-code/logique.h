#ifndef LOGIQUE_H_
#define LOGIQUE_H_

//FONCTIONS POUR LA LOGIQUE DU ROBOT
int mainNinja(int positon);
void lireCapteurs();
int StratNinja();
int lineFollower();
void arreterMouvement();
void avancerThread();
void tournerThread(int angle, int direction);
void tournerAltThread(int angle, int direction);

#endif // LOGIQUE_H_
