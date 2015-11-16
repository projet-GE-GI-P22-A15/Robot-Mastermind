#include "mbed.h"
#include "rtos.h"
#include "matrice.h"
#include "letters.h"
#include "communication.h"


Ticker shift;
Ticker pt;
Serial ser(PC_6, PC_7);

// Creation des objets
MATRICE mat;
LETTERS let;
COMMUNICATION comm;

void refreshShift(){
    mat.ShiftRight(); 
}
void refreshAffichage(){
    mat.Paint();
}

int main()
{
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    let.Init(&mat);
    comm.Init(&ser);

    shift.attach(&refreshShift, 0.5);
    pt.attach(&refreshAffichage, 0.01);

    let.ecrire4(BLEU, 1, LETTER_POS_HAUT);
    let.ecrire2(VERT, 2, LETTER_POS_HAUT);
    let.ecrire0(ROUGE, 3, LETTER_POS_HAUT);
    let.ecrireY(BLEU, 0, LETTER_POS_BAS);
    let.ecrireO(VERT, 1, LETTER_POS_BAS);
    let.ecrireL(ROUGE, 2, LETTER_POS_BAS);
    let.ecrireO(MAGENTA, 3, LETTER_POS_BAS);
    while(1) { 
        comm.logiqueSerie();
    }  
}