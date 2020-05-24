/*
 * File:   main.c
 * Author: Safaa
 *
 * Created on May 1, 2020, 11:27 AM
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "mTimer.h"

#define LED     0
#define Btn0    1
#define Btn1    2

//30 times per second

ISR(TIMER0_OVF_vect) {
    static int _1sec = 0;
    _1sec++;
    if (_1sec == 31) {
        // Once every on second
        PORTC ^= (1 << LED); // LED Toggle
        _1sec = 0;
    }
}
int isPressed(int pinNum);

int dCycle = 50;

int main(void) {
    /* Replace with your application code */

    DDRC |= (1 << LED);
    DDRC &= ~((1 << Btn0) | (1 << Btn1));
    PORTC &= ~(1 << LED);

    //  Timer0_init(char TimerMode, char CompOUTMode, char Clk_S)
    Timer0_setDutyCyle(dCycle);
    Timer0_init(PWM, OC0_PWM_ClearDN, CLK_io_PS1024);

    sei(); // Global Interrupt Enable
    while (1) {
        if (isPressed(Btn0)) {
            if (dCycle > 0) {
                dCycle -= 10;
                Timer0_setDutyCyle(dCycle);
            }

        }

        if (isPressed(Btn1)) {
            if (dCycle < 100)
                dCycle += 10;
            Timer0_setDutyCyle(dCycle);
        }

        _delay_ms(500);
    }
}

int isPressed(int pinNum) {

    if (PINC & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}