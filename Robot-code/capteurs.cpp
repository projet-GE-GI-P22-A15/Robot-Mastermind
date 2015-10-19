#include "capteurs.h"

//code capteur ici!
#define PORTMICRO 1
#define PAUSECAFE 200

int lectureMicro() //Lecture de l'entrée analogique du micro , donc le 5kHz pour le signal de départ . Fonction utilisee pour les deux robots.
{
	int lectureEntree=0;
		
	lectureEntree=ANALOG _Read(PORTMICRO);
	if(lectureEntree!=0)
	{
		lectureEntree=1;
		LCD_Printf("SIGNAL 5kHz!\n");
		return lectureEntree;
	}
	else
	{
		lectureEntree=0;
		LCD_Printf("PAS DE SIGNAL!\n");
		return lectureEntree;
	}
}

int SignalDepartSumo() //Pour le Sumo ET le Ninja
{
	int premierSignal=0;
	
	while(premierSignal!=1)
	{
		THREAD_MSleep(PAUSECAFE);
		premierSignal=lectureMicro();
	}
	LCD_Printf("GO!!! I GOT YO BACK NINJA!!!\n");
	return premierSignal;
}

int SignalDepartNinja() //Pour le Ninja seulement!!! Il utilise la fonction de signal de depart pour le Sumo pour justement partir apres le Sumo.
{
	int deuxiemeSignal;
	deuxiemeSignal=SignalDepartSumo();
	
	LCD_Printf("THANKS M8!!!\nPremier Signal Detecte!!!\nDEPART IMMINENT M8!!!\n");
	
	while(deuxiemeSignal!=2)
	{
		THREAD_MSleep(PAUSECAFE);
		deuxiemeSignal=deuxiemeSignal+lectureMicro();
	}
	LCD_Printf("SO BE IT!!!");
	return 1;
}

void grandeCourse(int mode,int position) //mode=1 :Sumo mode=2:Ninja , position=1:droite position=2:gauche FONCTION DANS LE MAIN
{
	if(mode==1)
	{
		Sumo(position);
	}
	else if(mode==2)
	{
		Ninja(position);
	}	
}

void Ninja(int position)
{
	SignalDepartNinja();
	if(position==1)
	{
	//NinjaDroit();fonction à concevoir avec fonctions autres capteurs et mouvements du Ninja qui part de la droite!
	}
	if else(position==2)
	{
	//NinjaGauche();fonction à concevoir avec fonctions autres capteurs et mouvements du Ninja qui part de la gauche!
	}
}

void Sumo(int position)
{
	SignalDepartSumo();
	if(position==1)
	{
	//SumoDroit();fonction à concevoir avec fonctions autres capteurs et mouvements du Ninja qui part de la droite!
	}
	if else(position==2)
	{
	//SumoGauche();fonction à concevoir avec fonctions autres capteurs et mouvements du Ninja qui part de la gauche!
	}
}


/**
 * Détection d'obstacles avec le sonar:
 */
// float SONAR_Detect(int sonar_number)

/**
 * Detection infra rouge donc mur ou obstacle
 */
 // IR_Detect()