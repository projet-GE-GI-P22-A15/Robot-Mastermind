#include "charma.h"

char buf[64];
int i = 0;
DigitalIn sepI(PA_3);
DigitalIn sigI(PA_0);

void CHARMA::Init(){
}

int CHARMA::lireCharma() {
	int i = 0, j = 0, fin = 0;
	for(i = 0; i < 64; ++i){
		buf[i] = '\0';
	}

	
	while (!sepI || !sigI){
		wait_ms(delai_ms / 2);
	}
	wait_us(delai_ms * 1000 / 4);
	while (sepI && sigI){
		wait_ms(delai_ms / 2);
	}
	wait_us(delai_ms * 1000 / 4);

	for(i = 0; i < 64 && fin == 0; ++i){
		for(j = 0; j < 8; ++j){
			
			buf[i] = buf[i] | (sigI << j);
				while(!sepI){
					wait_ms(delai_ms/2);
				} while (sepI){
					wait_ms(delai_ms/2);
				}
				wait_us(delai_ms * 1000 / 2);
		}
		if (buf[i] == '~'){
			fin = 1;
		}
	}
	return 0;
}

int CHARMA::trouverType() {
	if (buf[1] == '3') {
		return 2;
	} else {
		return 1;
	}
}

char* CHARMA::getBuf() {
	return buf;
}

/*void CHARMA::talkToPC(){
	for(int i = 0; i < 64 && buf[i] != '~'; ++i){
		pc.putc(buf[i]);
		wait_ms(1);
	}
	pc.putc('\n');
}*/
