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
    aff.rafraichirMatrice();
    mat.Paint();
}

int main() {
    pt.attach(&refreshAffichage, 0.0075);

    while(1) { 
        charm.lireCharma();
        aff.majMatrice(charm.getBuf());
            
        
    }  
}

