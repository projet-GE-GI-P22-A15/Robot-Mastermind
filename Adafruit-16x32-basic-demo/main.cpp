/*
The goal of this program is to show the basic connections and workings of Adafruits 32x16 RGB LED matrix board (http://www.adafruit.com/products/420),
also sold on other places, for instance http://www.ebay.com/itm/PH6-RGB-Full-Color-LED-16-32-Dot-Matrix-Display-Module-/310303408628?pt=LH_DefaultDomain_0&hash=item483f8641f4 (no
affiliation with either of them).
This program is not intended to be highly optimized or a guideline in C programming in any way (more of the opposite actually).
To have more than 7 colors on this thing, you need to implement software PWM of some sort. I have obviously not done that, but if YOU do, please let me know!
Adafruit have a wicked demo program for an arduino - www.youtube.com/watch?v=lY-flFEfsHo
There are probably lots of ways to make this perform better, perhaps by using Neal Hormans port of the Adafruit_GFX library (http://mbed.org/users/nkhorman/code/Adafruit_GFX/).
No error checking or out-of-bounds checking is done. Use at your own peril.
For more detailed information on the driver chip, see http://www.bjtopspace.com/ziliao/CYT62726.pdf
Although the chips on my board says jx15020, I've been informed that they are equvivalent to the CYT62726, and so far it's a match.
Feel free to use all or parts of this work.
If you choose to do so, I would appreciate a small mentioning in the scrolling opening credits ;)

Best regards,
Hugo Harming
upgraded@hotmail.com
*/

#include "mbed.h"
#include "rtos.h"
#include "matrice.h"
#include "letters.h"

Ticker shift;

// Creation des objets
MATRICE mat;
LETTERS let;

void refreshShift(){
    mat.ShiftRight(); 
}

int main()
{
    

    int yPos = 0;

	// Matrice: horizontal = 32 = x; vertical = 16 = y
    mat.Init(); // Set things up
    let.Init(&mat);
    shift.attach(&refreshShift, 0.25);

    let.chiffre4(BLANC, 0, LETTER_POS_HAUT);
    let.chiffre2(BLEU, 1, LETTER_POS_HAUT);
    let.chiffre0(CYAN, 2, LETTER_POS_HAUT);
    while(1) { 
        mat.Paint();
    }  
}


/*  // Thread example
void signal_thread(void const *argument) {
    while (true) {
        Thread::wait(500);
        osSignalSet(mainThreadID, 0x1);
    }
}

main:
mainThreadID = osThreadGetId();
Thread thread(signal_thread);
osSignalWait(0x1, osWaitForever);
*/