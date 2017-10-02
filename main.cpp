// For NuMaker-PFM-NUC472 GPIO pins connected to rgbled, green led, buzzer
#include "mbed.h"
#if defined(TARGET_NUMAKER_PFM_NUC472)
DigitalOut    rgbled_B(PD_8); // low-active
DigitalOut    rgbled_R(PD_9); // low-active
DigitalOut    rgbled_G(PA_4); // low-active
DigitalOut    greenled(PG_0); // low-active
DigitalOut    buzzer(PD_11);  // low-active
DigitalIn     button_SW1(PC_12); // press button =0
DigitalIn     button_SW2(PC_13); // press button =0
#elif defined(TARGET_NUMAKER_PFM_M453)
DigitalOut    rgbled_B(PD_7); // low-active
DigitalOut    rgbled_R(PD_2); // low-active
DigitalOut    rgbled_G(PD_3); // low-active
DigitalOut    greenled(PB_12); // low-active
DigitalOut    buzzer(PE_2);  // low-active
DigitalIn     button_SW1(PA_15); // press button =0
DigitalIn     button_SW2(PA_14); // press button =0
#elif defined(TARGET_NUMAKER_PFM_M487)
DigitalOut    rgbled_B(PH_1); // in M487 rgbled_B is yellow, not blue. low-active
DigitalOut    rgbled_R(PH_0); // low-active
DigitalOut    rgbled_G(PH_2); // low-active
DigitalOut    greenled(PH_2); // in M487 use the pin to connect the led, low-active
DigitalOut    buzzer(PF_11);  // in M487 use the pin to connect the buzzer, low-active
DigitalIn     button_SW1(PC_10); // in M487 button_SW1 is SW2, press button =0
DigitalIn     button_SW2(PC_9); // in M487 button_SW2 is SW3, press button =0
#endif

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for d elays)
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

