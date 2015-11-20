#include "charma.h"

char buf[64];
int i = 0;
Serial pc(USBTX,USBRX);
DigitalIn sepI(PA_0);
DigitalIn sigI(PA_3);

void CHARMA::Init(){
	pc.baud(115200);
}

int CHARMA::lireCharma() {
	pc.putc('q');
	int i = 0;
	for (i = 0; i < 64; ++i) {
		buf[i] = '\0';
	}

	

	for (i = 0; buf[i] != '~' && i < 64; ++i) {
		while (!sepI || !sigI) { // attente
			wait_ms(delai_ms / 4);
		} 
		//Verif debut de transfert
		if (sepI && sigI) { 
			// attend le premmier caractere
			while (sepI && sigI) {
				wait_ms(delai_ms / 4);
			}
			int j;
			//ecrit les bits
			wait_ms(1);
			for (j = 0; j < 8; ++j) {
				if (!sepI){
					buf[i] = buf[i] | (sigI << j);//ecrit le j-eme bit
					while (!sepI) { // attend la separation
						wait_ms(delai_ms / 4);
					}
				}else {
					pc.putc('a');
					pc.putc('b');
				}
				while (sepI) { //attend le prochain bit
					wait_ms(delai_ms / 4);
				}
				wait_ms(1);
			}
			
			pc.putc(buf[i]);
			/*wait_ms(delai_ms);
			int j;
			for(j = 0; j < 8; ++j){
				//recoit le premier bit
				if (!sepI){
					buf[i] = buf[i] | (sigI << j);//ecrit le j-eme bit
					wait_ms(delai_ms);
				} else {
					pc.putc('a');
				}
				//recoit le separateur
				if (sepI){
					wait_ms(delai_ms);
				} else {
					pc.putc('b');
				}
			}
			pc.putc(buf[i]);*/

		} else {
			pc.putc('c');
			pc.putc('d');
			wait_ms(delai_ms/4);
			return -1;
		}
	}
	return 0;
}

int CHARMA::trouverType() {
	pc.putc('e');
	if (buf[1] == '3') {
		return 2;
	} else {
		return 1;
	}
}

char* CHARMA::getBuf() {
	return buf;
}
