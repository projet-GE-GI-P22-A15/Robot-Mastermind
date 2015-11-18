#ifndef MATRICE_H
#define MATRICE_H


#define LOW 0
#define HIGH 1

#define NOIR 		0
#define INDIGO		1
#define BLEU 		8
#define FORET		2
#define TURQUOISE	3
#define CIEL		10
#define VERT 		16
#define CORAIL		17
#define CYAN 		24
#define BOURGOGNE	4
#define POURPRE		5
#define MAUVE		12
#define VOMIT		6
#define GRIS		7
#define ACIER		14
#define FLUO		20
#define HOPITAL		21
#define POUDRE		28
#define ROUGE 		32
#define ROSE		33
#define MAGENTA 	40
#define ORANGE		34
#define CHAIR		35
#define GOMME		42
#define JAUNE 		48
#define CREME		49
#define BLANC 		56


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
