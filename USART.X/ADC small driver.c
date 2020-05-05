/*
 * File:   ADC small driver.c
 * Author: Toshiba
 *
 * Created on 27 ?????, 2020, 01:27 ?
 */



#include <avr/io.h>
#include <util/delay.h>
void ADC_init()
{
 ADMUX=0x00; // REF (AREF) ..//pre scaler (f/128)...select to read from pin A0.. left adjustment
 ADCSRA |=(1<<ADEN) | (1<<ADIF) | (1<<ADSP2) | (1<<ADSP1) | (1<<ADSP0); // ENABLE AND SET FLAG OF interrupt 1 // prescaler is f/128 
}


void ADC-start conversion ()
{
    ADCSRA|=(1<<ADSC) // START CONVERSION NOW !!
}


ISR(ADC)
{
}

int main(void) {
    /* Replace with your application code */
    while (1) {
    }
}
