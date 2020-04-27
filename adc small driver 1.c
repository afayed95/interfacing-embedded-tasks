/*
 * File:   adc small driver 1.c
 * Author: Toshiba
 *
 * Created on 27 ?????, 2020, 01:28 ?
 */
#include <avr/io.h>
#include <util/delay.h>

void ADC_init()
{
    ADMUX=0x00; // volt by REF ...selecting single channel A0
    ADCSRA |=(1<< ADEN) |(1<< ADIF) |(1<<ADPS2) | (1<<ADPS1)|(1<<ADPS0); // enabling ADC .. 
    //setting flag by 1 .. setting prescaler by f/128     
}

void ADC_startconversion()
{
    ADCSRA |=( 1<<ADSC);
    // START CONVERSION NOW !! 
}

int ADC_readresult()
{
    int data=ADCL;
    data |=(ADCH<<8);
    return data;
    // left adjustment 
   // data =ADC;  // or can write it like this 
}
ISR(ADC_vect)
{
    //code to write !!
    PORTC |=OxFF;
}


int main(void) {
    sei();
    /* Replace with your application code */
    DDRC |= 0XFF;
    // TO WRITE !! 
    while (1) {
    }
}
