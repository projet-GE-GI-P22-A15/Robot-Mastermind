#ifndef MATRICE_H
#define MATRICE_H


#define LOW 0
#define HIGH 1

#define NOIR 		0
#define BLEU 		1
#define VERT 		2
#define CYAN 		3
#define ROUGE 		4
#define MAGENTA 	5
#define JAUNE 		6
#define BLANC 		7


class MATRICE {

public:
	void Init();
	void ShiftRight();
	void Pset(unsigned char x,unsigned char y, unsigned char c);
	void Paint();
	
private:
	void MkPattern();
	void WrRow(unsigned char Row);

};

#endif