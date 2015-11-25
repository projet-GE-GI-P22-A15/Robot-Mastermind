#ifndef MATRICE_H
#define MATRICE_H


#define LOW 0
#define HIGH 1

#define NOIR 		0
#define INDIGO		1		//a
#define BLEU 		8		//b
#define FORET		2		//c
#define TURQUOISE	3		//d
#define CIEL		10		//e
#define VERT 		16		//f
#define CORAIL		17		//g
#define CYAN 		24		//h
#define BOURGOGNE	4		//i
#define POURPRE		5		//j
#define MAUVE		12		//k
#define VOMIT		6		//l
#define GRIS		7		//m
#define ACIER		14		//n
#define FLUO		20		//o
#define HOPITAL		21		//p
#define POUDRE		28		//q
#define ROUGE 		32		//r
#define ROSE		33		//s
#define MAGENTA 	40		//t
#define ORANGE		34		//u
#define CHAIR		35		//v
#define GOMME		42		//w
#define JAUNE 		48		//x
#define CREME		49		//y
#define BLANC 		56		//z


class MATRICE {

public:
	MATRICE();
	void ShiftRight();
	void Pset(unsigned char x,unsigned char y, unsigned char c);
	void Paint();
	
private:
	void MkPattern();
	void WrRow(unsigned char Row);

};

#endif
