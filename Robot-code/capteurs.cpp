#include <capteurs.h>
#include <libarmus.h>
#include <valeurs.h>

//code capteur ici!
#define PORTMICRO 1
#define PAUSECAFE 200

#define BLANC 0
#define ROUGE 1
#define VERT 2
#define BLEU 3
#define JAUNE 4
#define GRIS 5
#define ROSE 6

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

int SignalDepartNinja() { //Pour le Ninja seulement!!! Il utilise la fonction de signal de depart pour le Sumo pour justement partir apres le Sumo.
	int deuxiemeSignal;
	deuxiemeSignal = SignalDepartSumo();

	THREAD_MSleep(2000);
	while (deuxiemeSignal != 2) {
		THREAD_MSleep(PAUSECAFE);
		deuxiemeSignal = deuxiemeSignal + Lire5kHz();
	}
	return 1;
}

int lireCapteurLigne() {
	int gauche = ANALOG_Read(7);
	int centre = ANALOG_Read(6);
	int droite = ANALOG_Read(5);

	if (gauche < 500) {
		ligneGauche = 1;
	} else if (gauche > 500) {
		ligneGauche = 0;
	}
	if (centre < 500) {
		ligneCentre = 1;
	} else if (centre > 500) {
		ligneCentre = 0;
	}
	if (droite < 500) {
		ligneDroite = 1;
	} else if (droite > 500) {
		ligneDroite = 0;
	}
	return 0;
}

int lireBumpers(){
	bumperAvant = DIGITALIO_Read(BMP_FRONT);
	bumperArriere = DIGITALIO_Read(BMP_REAR);
	bumperGauche = DIGITALIO_Read(BMP_LEFT);
	bumperDroite = DIGITALIO_Read(BMP_RIGHT);

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
