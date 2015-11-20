#include "charma.h"

unsigned char buf[64];
int i = 0;

int CHARMA::lireCharma(){
	int i = 0;
	for(i = 0; i < 64; ++i){
		buf[i] = '\0';
	}


	for(i = 0; buf[i] != '~'; ++i){
		if (!sepI && !sigI){
			wait_ms(delai_ms / 2);
		} else if (septI && sigI){
			while (sepI && sigI){
				wait_ms(delai_ms / 2);
			}
			int j;
			for(j = 0; j < 7; ++j){
				buf[i] = buf[i] | (sigI << j);
				wait_ms(delai_ms / 2);
				while(!sepI){
					wait_ms(delai_ms / 2);
				}
				while (sepI){
					wait_ms(delai_ms / 2);
				}
			}
			buf[i] = buf[i] | (sigI << 7);
			wait_ms(delai_ms / 2);
			while(!sepI){
				wait_ms(delai_ms / 2);
			}
			while (sepI && sigI){
				wait_ms(delai_ms / 2);
			}

		} else {
			return -1;
		}
	}
	return 0;
}

int CHARMA::trouverType(){
	if (buf[1] == '3'){
		return 2;
	} else {
		return 1;
	}
}