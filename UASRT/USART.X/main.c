/*
 * File:   main.c
 * Author: Safaa
 *
 * Created on May 1, 2020, 9:31 AM
 */

#define F_CPU 8000000UL
#include <xc.h>
#include <avr/interrupt.h>
#include "mADC.h"


int data;

int main(void) {

    ADC_init( 0 , _AREF, _128PS, _useInterrupt, _noAutoTrigger);
    sei();

    ADC_startConv();
    DDRC = 0xFF;
    DDRD = 0xFF;
    while (1) {

        PORTC = (char) data;
        PORTD = (char) (data >> 8);

    }
    return 0;
}

