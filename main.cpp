// For NuMaker-PFM-NUC472 GPIO pins connected to rgbled, green led, buzzer
#include "mbed.h"

DigitalOut    rgbled_B(PD_8); // low-active
DigitalOut    rgbled_R(PD_9); // low-active
DigitalOut    rgbled_G(PA_4); // low-active
DigitalOut    greenled(PG_0); // low-active
DigitalOut    buzzer(PD_11);  // low-active
DigitalIn     button_SW1(PC_12); // press button =0
DigitalIn     button_SW2(PC_13); // press button =0

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main() {
    
    rgbled_B=1; rgbled_R=1; rgbled_G=1;
    greenled=1;
    buzzer=1;
                        
    while (true) {
        // press SW1 will turn on greeled and RGBLED=blue
        if (button_SW1==0) {
                             greenled=0;
                             rgbled_B=0;
                           }                             
        else               {
                             greenled=1;
                             rgbled_B=1;
                           }
        // press SW2 will turn on buzzer                                  
        if (button_SW2==0) buzzer=0;
        else               buzzer=1;
    }
}

