#include "letters.h"


MATRICE * m;

void LETTERS::Init(MATRICE *mat){
	m = mat;
}

void LETTERS::chiffre0(int color, int position, int yPosition){

	// Condition de dépassement
	if(position > 5)
		position = 5;
	else if(position < 0)
		position = 0;
	if(color < 0)
		color = 0;
	else if(color > 8)
		color = 8;
	if(yPosition > 2)
		yPosition = 2;
	else if(yPosition < 0)
		yPosition = 1;

	// y = 0 
	m->Pset(0+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),0+(yPosition * 8),color*1);
	// y = 1 
	m->Pset(0+(position * 6),1+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),1+(yPosition * 8),color*1);
	// y = 2 
	m->Pset(0+(position * 6),2+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),2+(yPosition * 8),color*1);
	// y = 3 
	m->Pset(0+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),3+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),3+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),3+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),3+(yPosition * 8),color*1);
	// y = 4 
	m->Pset(0+(position * 6),4+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),4+(yPosition * 8),color*1);
	// y = 5 
	m->Pset(0+(position * 6),5+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),5+(yPosition * 8),color*1);
	// y = 6 
	m->Pset(0+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),6+(yPosition * 8),color*1);
	m->Paint();
}

void LETTERS::chiffre2(int color, int position, int yPosition){

	// Condition de dépassement
	if(position > 5)
		position = 5;
	else if(position < 0)
		position = 0;
	if(color < 0)
		color = 0;
	else if(color > 8)
		color = 8;
	if(yPosition > 2)
		yPosition = 2;
	else if(yPosition < 0)
		yPosition = 1;

	// y = 0 
	m->Pset(0+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),0+(yPosition * 8),color*1);
	// y = 1 
	m->Pset(0+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(1+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),1+(yPosition * 8),color*1);
	// y = 2 
	m->Pset(0+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(1+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),2+(yPosition * 8),color*1);
	// y = 3 
	m->Pset(0+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),3+(yPosition * 8),color*1);
	// y = 4 
	m->Pset(0+(position * 6),4+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),4+(yPosition * 8),color*0);
	// y = 5 
	m->Pset(0+(position * 6),5+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),5+(yPosition * 8),color*0);
	// y = 6 
	m->Pset(0+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),6+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),6+(yPosition * 8),color*1);
	m->Paint();
}

void LETTERS::chiffre4(int color, int position, int yPosition){

	// Condition de dépassement
	if(position > 5)
		position = 5;
	else if(position < 0)
		position = 0;
	if(color < 0)
		color = 0;
	else if(color > 8)
		color = 8;
	if(yPosition > 2)
		yPosition = 2;
	else if(yPosition < 0)
		yPosition = 1;

	// y = 0 
	m->Pset(0+(position * 6),0+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),0+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),0+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),0+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),0+(yPosition * 8),color*1);
	// y = 1 
	m->Pset(0+(position * 6),1+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),1+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),1+(yPosition * 8),color*1);
	// y = 2 
	m->Pset(0+(position * 6),2+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),2+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),2+(yPosition * 8),color*1);
	// y = 3 
	m->Pset(0+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(1+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(2+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(3+(position * 6),3+(yPosition * 8),color*1);
	m->Pset(4+(position * 6),3+(yPosition * 8),color*1);
	// y = 4 
	m->Pset(0+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(1+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),4+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),4+(yPosition * 8),color*1);
	// y = 5 
	m->Pset(0+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(1+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),5+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),5+(yPosition * 8),color*1);
	// y = 6 
	m->Pset(0+(position * 6),6+(yPosition * 8),color*0);
	m->Pset(1+(position * 6),6+(yPosition * 8),color*0);
	m->Pset(2+(position * 6),6+(yPosition * 8),color*0);
	m->Pset(3+(position * 6),6+(yPosition * 8),color*0);
	m->Pset(4+(position * 6),6+(yPosition * 8),color*1);
	m->Paint();
}

