#ifndef CHARMA_H_
#define CHARMA_H_

#include "mbed.h"

#define LOW 0
#define HIGH 1
#define sepI DigitalIn(PB_8)
#define sigI DigitalIn(PB_9)
#define delai_ms 16



class CHARMA {
public:
	int lireCharma();
	int trouverType();
private:
	
};

#endif /* CHARMA_H_ */
