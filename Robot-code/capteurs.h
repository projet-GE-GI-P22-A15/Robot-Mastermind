#ifndef CAPTEURS_H_
#define CAPTEURS_H_

//FONCTION POUR LES CAPTEURS ICI	
int lectureMicro();
int SignalDepartSumo();
int SignalDepartNinja();
void grandeCourse(int mode, int position);
void Ninja(int position);
void Sumo(int position);

#endif // CAPTEURS_H_
