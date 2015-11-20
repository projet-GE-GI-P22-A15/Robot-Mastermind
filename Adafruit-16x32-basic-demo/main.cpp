#include "mbed.h"
#include "rtos.h"
#include "matrice.h"
#include "letters.h"
#include "communication.h"
#include "charma.h"


Ticker shift;
Ticker pt;


// Creation des objets
MATRICE mat;
LETTERS let;
COMMUNICATION comm;
CHARMA charm;
int alternateur = 0;

void refreshShift(){
    mat.ShiftRight(); 
}

void modifAlternance(){
    alternateur = (alternateur + 1) % 3;
    if (alternateur == 0) {
        let.setAlternance(HIGH);
    } else {
        let.setAlternance(LOW);
    }
}

void refreshAffichage(){


    /*let.ecrireA(CREME, 0, LETTER_POS_HAUT);
    let.ecrireL(BLANC, 1, LETTER_POS_HAUT);
    let.ecrireE(GRIS, 2, LETTER_POS_HAUT);
    let.ecrireX(TURQUOISE, 3, LETTER_POS_HAUT);
    let.ecrireX(BLEU, 4, LETTER_POS_HAUT);
    let.ecrireJ(CORAIL, 0, LETTER_POS_BAS);
    let.ecrireP(CIEL, 1, LETTER_POS_BAS);
    let.ecrireL(ORANGE, 2, LETTER_POS_BAS);
    let.ecrireO(FLUO, 3, LETTER_POS_BAS);*/

    modifAlternance();
    mat.Paint();
}

int main() {
    unsigned char lastByte = '0';
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    let.Init(&mat);
    //comm.Init();
    charm.Init();

    //shift.attach(&refreshShift, 0.5);
    //pt.attach(&refreshAffichage, 0.005);

    while(1) { 
        if (charm.lireCharma() == 0){
            //testing
            int type = charm.trouverType();
        } else {
            //erreur
        }
    }  
    
}

