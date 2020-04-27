/*
 * File:   Amain.c
 * Author: Toshiba
 *
 * Created on 27 ?????, 2020, 03:27 ?
 */

#define F_CPU 16000000UL
// Built-in headers
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined Headers
#include "Config.h"
#include "DIO.h"
#include "lcd.h"

void ADC_init() 
{
    ADMUX = 0x00; // Channel 0
    SFIOR |=  (1<<ADTS1);
    ADCSRA |= (1 << ADEN) |(1 << ADIE) | (1 << ADPS0) |(1 << ADPS2) | (1 << ADPS1) ;
     // if i needed to put the pre scaler with f/128
}
void startConv() 
{
    ADCSRA |= (1 << ADSC);
}

int getADCdata() 
{
   //Right adjustment
    int data = 0;
    data = ADCL;
    data |= (ADCH << 8);
    return data;
}

int getADCdataL() 
{
    //left adjustment
    int data = 0;
    data = (ADCH << 2);
    return data;
}

ISR(ADC_vect)
{
    char buffer[20];  
    int data =getADCdata();
    setPORTC(data);
    setPORTD(data>>8);   
    //_delay_ms(500); // i need to put delay here or set the pre scaler
    itoa(data,buffer,10);
    LCD_String(buffer);
    startConv();
}


int main(void) {
    /* Replace with your application code */
    PORTCas(OUT);
    PORTDas(OUT);
    
    LCD_Init();
    ADC_init(); // input to trigger is  on ADC0
    
    sei();   //Global interrupt is ON
    startConv(); 
   
    while (1) {
    }
}
