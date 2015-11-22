#include "mbed.h"
#include "rtos.h"
#include "matrice.h"
#include "letters.h"
#include "communication.h"
#include "charma.h"
#include "affichage.h"

Ticker shift;
Ticker pt;


// Creation des objets
MATRICE mat;
LETTERS let;
COMMUNICATION comm;
CHARMA charm;
AFFICHAGE aff;

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


    let.ecrireB(CREME, 0, LETTER_POS_HAUT);
    let.ecrireR(BLANC, 1, LETTER_POS_HAUT);
    let.ecrireA(GRIS, 2, LETTER_POS_HAUT);
    let.ecrireV(TURQUOISE, 3, LETTER_POS_HAUT);
    let.ecrireO(BLEU, 4, LETTER_POS_HAUT);
    let.ecrireC(CORAIL, 0, LETTER_POS_BAS);
    let.ecrireO(CIEL, 1, LETTER_POS_BAS);
    let.ecrireC(ORANGE, 2, LETTER_POS_BAS);
    let.ecrireO(FLUO, 3, LETTER_POS_BAS);

    modifAlternance();
    mat.Paint();
}

int main() {
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    let.Init(&mat);

    charm.Init();

    pt.attach(&refreshAffichage, 0.005);

    while(1) { 
        if (charm.lireCharma() == 0){
            charm.talkToPC();
        }
    }  
}

