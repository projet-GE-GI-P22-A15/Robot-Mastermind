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
int alternateur = 0;

void refreshShift(){
    mat.ShiftRight(); 
}

void refreshAffichage(){
    alternateur = (alternateur + 1) % 10;
    if (let.getAlternance() == 0) {
        let.setAlternance(HIGH);
    } else {
        let.setAlternance(LOW);
    }
<<<<<<< HEAD
    let.ecrire4(POUDRE, 1, LETTER_POS_HAUT);
    let.ecrire2(BLANC, 2, LETTER_POS_HAUT);
    let.ecrire0(ROUGE, 3, LETTER_POS_HAUT);
    let.ecrireY(TURQUOISE, 0, LETTER_POS_BAS);
    let.ecrireO(FORET, 1, LETTER_POS_BAS);
    let.ecrireL(JAUNE, 2, LETTER_POS_BAS);
    let.ecrireO(ORANGE, 3, LETTER_POS_BAS);
=======
    let.ecrire4(CREME, 0, LETTER_POS_HAUT);
    let.ecrire4(FLUO, 1, LETTER_POS_HAUT);
    let.ecrire2(POURPRE, 2, LETTER_POS_HAUT);
    let.ecrire0(CORAIL, 3, LETTER_POS_HAUT);
    let.ecrire4(POUDRE, 4, LETTER_POS_HAUT);
    let.ecrireY(GOMME, 0, LETTER_POS_BAS);
    let.ecrireO(CREME, 1, LETTER_POS_BAS);
    let.ecrireL(GRIS, 2, LETTER_POS_BAS);
    let.ecrireO(BLANC, 3, LETTER_POS_BAS);
>>>>>>> origin/master
    mat.Paint();
}

int main()
{
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    let.Init(&mat);
    comm.Init(&ser);

    //shift.attach(&refreshShift, 0.5);
    pt.attach(&refreshAffichage, 0.001);


    while(1) { 
        comm.logiqueSerie();
        wait_ms(10);
    }  
}