#include "mbed.h"
#include "rtos.h"
#include "matrice.h"
#include "letters.h"
#include "communication.h"
#include "charma.h"
#include "affichage.h"

Ticker pt;


// Creation des objets
MATRICE mat;
COMMUNICATION comm;
CHARMA charm;
AFFICHAGE aff(&mat);

void refreshShift(){
    mat.ShiftRight(); 
}


void refreshAffichage(){
    aff.afficherMot();
    mat.Paint();
}

int main() {
	// Matrice: horizontal = 32 = x; vertical = 16 = y
    //mat.Init(); // Set things up
    //aff.Init(&mat);
    charm.Init();

    pt.attach(&refreshAffichage, 0.0075);

    while(1) { 
        charm.lireCharma();
        aff.majTableauMot(charm.getBuf());
            
        
    }  
}

