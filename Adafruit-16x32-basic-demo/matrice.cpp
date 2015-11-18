#include "matrice.h"
#include "mbed.h"
#include "letters.h"

BusOut ABC(PB_6,PB_15,PB_7); // Row address.
DigitalOut CLK(D10);    //  Data clock    - rising edge
DigitalOut LAT(D9);    //  Data latch    - active low (pulse up after data load)
DigitalOut OE(D11);     //  Output enable - active low (hold high during data load, bring low after LAT pulse)
DigitalOut R1(D2);     //  RED   Serial in for upper half
DigitalOut R2(D3);     //  RED   Serial in for lower half
DigitalOut G1(D0);      //  GREEN Serial in for upper half
DigitalOut G2(D1);      //  GREEN Serial in for lower half
DigitalOut B1(D4);      //  BLUE  Serial in for upper half
DigitalOut B2(D5);      //  BLUE  Serial in for lower half

unsigned char gm[32][6]; // Graphic memory
unsigned long CT; //        Counter for demo code

void MATRICE::Init()
{
    // Set up things to a known state
    CLK = LOW;
    LAT = LOW;
    OE = HIGH; //display off
    ABC = 0;
    CT=0;
}

void MATRICE::ShiftRight()
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

void MATRICE::WrRow(unsigned char Row)
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


void MATRICE::Pset(unsigned char x,unsigned char y, unsigned char c)
{
    // Set pixel (x,y) to color c
    // Manipulates graphics memory, so you won't see any change till you Paint() it.
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

void MATRICE::Paint()
{
    // Write graphics memory to display
    for(int Row=0; Row<8; Row++) {
        OE = HIGH; // Disable output
        WrRow(Row);
        OE = LOW; // Enable output
        wait_us(500);
	}
}
