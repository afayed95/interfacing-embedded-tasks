/*
 * File:   ADC.c
 * Author: Toshiba
 *
 * Created on 05 ????, 2020, 05:44 ?
 */


#include <xc.h>
#include "ADC.h"


void ADC_init() {
    ADMUX = 0x00; // Channel 0 // nd from Vref
   // SFIOR |= (1<<ADTS1); // Don't need it to be INT0
    ADCSRA |= (1 << ADEN) |(1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    
}

void selectChannel(unsigned int channelNo) { // 0~7
    if (channelNo < 8) { // 00000001| 00000000
        ADMUX &= ~(7 << 0); // 00000111  11111000
        ADMUX |= channelNo;
    } else {
        //# warning ""
    }
}

void startConv() {
    ADCSRA |= (1 << ADSC);
}

int getADCdata() {
    int data = 0;
    data = ADCL;
    data |= (ADCH << 8);

    return data;
}

int getADCdataL() {
    int data = 0;
    data = (ADCH << 2);
    return data;
}
