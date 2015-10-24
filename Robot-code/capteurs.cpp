#include <capteurs.h>
#include <libarmus.h>

//code capteur ici!
#define PORTMICRO 1
#define PAUSECAFE 200

int Lire5kHz() //Lecture de l'entrée analogique du micro , donc le 5kHz pour le signal de départ . Fonction utilisee pour les deux robots.
{
	int lectureEntree = 0;

	lectureEntree = ANALOG_Read(PORTMICRO);
	if (lectureEntree >= 500) {
		lectureEntree = 1;
		LCD_Printf("SIGNAL 5kHz!\n");
		return lectureEntree;
	} else {
		lectureEntree = 0;
		LCD_Printf("PAS DE SIGNAL!\n");
		return lectureEntree;
	}
}

int SignalDepartSumo() //Pour le Sumo ET le Ninja
{
	int premierSignal = 0;

	while (premierSignal != 1) {
		THREAD_MSleep(PAUSECAFE);
		premierSignal = Lire5kHz();
	}
	LCD_Printf("GO!!! I GOT YO BACK NINJA!!!\n");
	return premierSignal;
}

int SignalDepartNinja() //Pour le Ninja seulement!!! Il utilise la fonction de signal de depart pour le Sumo pour justement partir apres le Sumo.
{
	int deuxiemeSignal;
	deuxiemeSignal = SignalDepartSumo();

	LCD_Printf(
			"THANKS M8!!!\nPremier Signal Detecte!!!\nDEPART IMMINENT M8!!!\n");

	THREAD_MSleep(2000);
	while (deuxiemeSignal != 2) {
		THREAD_MSleep(PAUSECAFE);
		deuxiemeSignal = deuxiemeSignal + Lire5kHz();
	}
	LCD_Printf("SO BE IT!!!");
	return 1;
}

void grandeCourse(int mode, int position) //mode=1 :Sumo mode=2:Ninja , position=1:droite position=2:gauche FONCTION DANS LE MAIN
		{
	if (mode == 1) {
		//Sumo(position);
	} else if (mode == 2) {
		//Ninja(position);
	}
}

int lireCapteurLigne() {
	int gauche = ANALOG_Read(7);
	int centre = ANALOG_Read(6);
	int droite = ANALOG_Read(5);

	LCD_Printf("Gauche: %i, Centre: %i, Droite %i\n", gauche, centre, droite);
	return 0;
}

int lireCouleur() {
	int vRed = ANALOG_Read(2);
	int vGreen = ANALOG_Read(3);
	int vBlue = ANALOG_Read(4);

	int redValue = ((vRed * 100) / 16);
	int greenValue = ((vGreen * 130) / 22);
	int blueValue = ((vBlue * 200) / 25);

	LCD_Printf("RED: %i, GREEN: %i, BLUE: %i\n", redValue, greenValue,
			blueValue);

	/*if (redValue > greenValue && redValue > blueValue) {
	 if (greenValue > 2.6)
	 LCD_Printf("Object is Orange.");
	 else
	 LCD_Printf("Object is Red.");
	 } else if (greenValue > blueValue && greenValue > redValue) {
	 if (redValue > 2)
	 LCD_Printf("Object is Yellow.");
	 else
	 LCD_Printf("Object is Green.");
	 } else {
	 if (redValue > 2)
	 LCD_Printf("Object is Purple.");
	 else
	 LCD_Printf("Object is Blue.");
	 }*/
	return 0;
}
