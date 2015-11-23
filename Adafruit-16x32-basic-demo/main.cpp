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
COMMUNICATION comm;
CHARMA charm;
AFFICHAGE aff;

void refreshShift(){
    mat.ShiftRight(); 
}


void refreshAffichage(){
    aff.afficherMot(1);
    mat.Paint();
}

int main() {
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    aff.Init(&mat);

    charm.Init();

    pt.attach(&refreshAffichage, 0.005);

    while(1) { 
        if (charm.lireCharma() == 0){
            charm.talkToPC();
            aff.majTableauMot(charm.getBuf());
            
        }
    }  
}

