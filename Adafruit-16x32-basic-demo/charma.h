#ifndef CHARMA_H_
#define CHARMA_H_

#include "mbed.h"

#define LOW 0
#define HIGH 1

#define delai_ms 16



class CHARMA {
public:
	void Init();
	int lireCharma();
	int trouverType();
	char* getBuf();
private:
	
};

#endif
