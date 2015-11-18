#include "communication.h"


Serial * s;
Serial pc(USBTX, USBRX);

int tableauLettre[64];
int tableauJeu[4][10];
int nbrDeTours = 0;

void COMMUNICATION::Init(Serial *ser){
	s = ser;
	s->baud(115200);
	pc.baud(115200);

	// Initialisation des tableaux
	for (int i = 0; i < 64; ++i)
	{
		tableauLettre[i] = 0;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tableauJeu[i][j] = 0;
		}
	}

	// PC serial == test d'envoie de caractere avec l'ordinateur!
	pc.printf("La communication est demarre\n\r");
}

void COMMUNICATION::logiqueSerie(){
	int i = 0;
	int tempReceived = 0;

	//Simulation avec un ordi
	if(pc.readable()){
		if(s->getc() == '#'){
			pc.printf(" Receive # \r\n");

			// Analyse le deuxieme byte et associe les valeurs au tableau
			switch(s->getc()){
				case '$':
					pc.printf(" Receiving letters \n\r");
					do{
						if(tempReceived != '!'){
							tableauLettre[i-1] = s->getc();		// Max 64 caracteres à afficher	
						}	
						i++;
						tempReceived = s->getc();
					}while(tempReceived != '!');
					i = 0;				// Reset le nombre de caractere recu
					pc.printf(" End of transmission \r\n");
				break;
				case '%':
					pc.printf(" Receiving state \n\r");
					do{
						if(tempReceived != '!' && nbrDeTours < 10 && i < 4){
								tableauJeu[i-1][nbrDeTours] = tempReceived;
						}
						i++;		// Incremente pour les prochains etats
						tempReceived = s->getc();
					}while(tempReceived != '!');
					i = 0;				// Reset le nombre de caractere recu
					nbrDeTours++;		// Nbr de tour de l'adversaire
					pc.printf(" End of transmission \r\n");
				break;
				default:
					s->putc('+');
					pc.printf(" Error \r\n");
				break;
			}
		}
		else{
			s->putc('+');			// ERROR send byte for the error
			pc.printf(" Error! \n\r");
		}
	}
}