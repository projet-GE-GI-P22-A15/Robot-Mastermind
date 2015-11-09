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
#define LOW 0
#define HIGH 1


BusOut ABC(D9,D10,D11); // Row address.
DigitalOut CLK(D0);    //  Data clock    - rising edge
DigitalOut LAT(D1);    //  Data latch    - active low (pulse up after data load)
DigitalOut OE(D2);     //  Output enable - active low (hold high during data load, bring low after LAT pulse)
DigitalOut R1(D3);     //  RED   Serial in for upper half
DigitalOut R2(D4);     //  RED   Serial in for lower half
DigitalOut G1(D5);      //  GREEN Serial in for upper half
DigitalOut G2(D6);      //  GREEN Serial in for lower half
DigitalOut B1(D7);      //  BLUE  Serial in for upper half
DigitalOut B2(D8);      //  BLUE  Serial in for lower half

unsigned char gm[32][6]; // Buffer with 32x6 bytes. Graphics memory if you like.
unsigned long CT; //        Counter for demo code

void MkPattern() // Fill graphics buffer with colorful test pattern.
{
    unsigned int col,r,g,b;
    r=0x0f0f0f0f;
    g=0x33333333;
    b=0x55555555;
    for(col=0; col<32; col++) {
        gm[col][0]=(r>>(col % 8)) & 0xff; // Shift red value and mask out LSB.
        gm[col][1]=(g>>(col % 8)) & 0xff; // Shift green value and mask out LSB.
        gm[col][2]=(b>>(col % 8)) & 0xff; // Shift blue value and mask out LSB.
        gm[col][3]=gm[col][0]; // Copy top red byte to bottom red byte.
        gm[col][4]=gm[col][1]; // Copy top green byte to bottom green byte.
        gm[col][5]=gm[col][2]; // Copy top blue byte to bottom blue byte.
    }
}

void Init()
{
    // Set up things to a known state
    CLK = LOW;
    LAT = LOW;
    OE = HIGH; //display off
    ABC = 0;
    CT=0;
    MkPattern();
}

void ShiftRight()
{
    unsigned char i,r,g,b;
    r=gm[31][0]; // Save value of last column (top half)
    g=gm[31][1];
    b=gm[31][2];

    for(i=31; i>0; i--) { // Copy value of column n to column n-1
        gm[i][0]=gm[i-1][0];
        gm[i][1]=gm[i-1][1];
        gm[i][2]=gm[i-1][2];
    }
    gm[0][0]=r; // Paste saved values from last column to first column
    gm[0][1]=g;
    gm[0][2]=b;
    // Do it again for the lower half
    r=gm[31][3];
    g=gm[31][4];
    b=gm[31][5];

    for(i=31; i>0; i--) {
        gm[i][3]=gm[i-1][3];
        gm[i][4]=gm[i-1][4];
        gm[i][5]=gm[i-1][5];
    }
    gm[0][3]=r;
    gm[0][4]=g;
    gm[0][5]=b;
}

void WrRow(unsigned char Row)
{
    // Write specified row (and row+8) to display. Valid input: 0 to 7.
    ABC=7-Row; // Set row address
    for(int col=0; col<32; col++) { // To daisychain more displays, I guess you would have to increase this counter to n*32 columns. Might mirror though.
        R1 = gm[col][0] & (1<<Row); // Red bit, upper half
        G1 = gm[col][1] & (1<<Row); // Green bit, upper half
        B1 = gm[col][2] & (1<<Row); // Blue bit, upper half
        R2 = gm[col][3] & (1<<Row); // Red bit, lower half
        G2 = gm[col][4] & (1<<Row); // Green bit, lower half
        B2 = gm[col][5] & (1<<Row); // Blue bit, lower half
        CLK = HIGH;                 // tick (clock bit in)
        CLK = LOW;                  // tock
    }
    LAT = HIGH; // Latch entire row
    LAT = LOW;
}

void Pset(unsigned char x,unsigned char y, unsigned char c)
{
    // Set pixel (x,y) to color c
    // Manipulates graphics memory, so you won't see any change til you Paint() it.
    unsigned char ud,l,r0,g0,b0;
    ud=(y & 8)>>3; // 0 = upper half, 1 = lower half
    l=y & 7; // Extract row in upper/lower half
    r0=(c & 4) >>2; // Extract red bit from color
    g0=(c & 2) >>1; // Extract green bit from color
    b0=(c & 1); //     Extract blue bit from color
    //            *******Removes current bit ******* *Adds bit**
    gm[x][0+3*ud]=(gm[x][0+3*ud] & (255-(1<<(7-l))))+(r0<<(7-l)); // Red byte
    gm[x][1+3*ud]=(gm[x][1+3*ud] & (255-(1<<(7-l))))+(g0<<(7-l)); // Green byte
    gm[x][2+3*ud]=(gm[x][2+3*ud] & (255-(1<<(7-l))))+(b0<<(7-l)); // Blue byte
}

void Paint()
{
    // Write graphics memory to display
    for(int Row=0; Row<8; Row++) {
        OE = HIGH; // Disable output
        WrRow(Row);
        OE = LOW; // Enable output
        wait_us(500); // Wasting some time. Use for whatever else. Probably better with a ticker for the display refresh.
    }
}

int main()
{
    Init(); // Set things up
    while(1) { // Messy demo loop following...
        CT++;
        if((CT<=2560)||(CT>=2880 && CT<=4160)) {
            Paint(); // Refresh display
            if((CT % 20)==0) ShiftRight(); // After every 20 refresh, do a ShiftRight
        }
        if(CT==2560) {
            for(int c=0; c<8; c++) {
                for(int x=c; x<(31-c); x++) {// Top side
                    Pset(x,c,c);
                    Paint(); // Display refresh time sets loop duration.
                }
                for(int y=c; y<(15-c); y++) {// Right side
                    Pset(31-c,y,c);
                    Paint();
                }
                for(int x=(31-c); x>=c; x--) {// Bottom side
                    Pset(x,(15-c),c);
                    Paint();
                }
                for(int y=(15-c); y>=c; y--) { // Left side
                    Pset(c,y,c);
                    Paint();
                }
            }
        }
        if(CT>4160) {
            MkPattern(); // Restore original priceless artwork
            CT=0; // Start all over.
        }
    }
}
