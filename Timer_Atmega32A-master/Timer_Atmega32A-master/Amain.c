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

char message[] ="hello bro!";
char st1[]="volt = ";
char st2[]= "mv";
char cl[]="    ";
void ADC_init() 
{
    ADMUX = 0x00; // Channel 0
    //SFIOR |=  (1<<ADTS1);
    ADCSRA |= (1 << ADEN) |(1 << ADIE) | (1 << ADPS2) |(1 << ADPS1) | (1 << ADPS0) ;
     // if i needed to put the pre scaler with f/128
}
void startConv() 
{
    ADCSRA |= (1 << ADSC);
}

void Selecting_channel(unsigned int channel )
{
    ADMUX &= ~(7<<0);  //00000111 11111000
    ADMUX |= channel;  
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
    static int state =0 ;
    char buffer[20];  
    int step =getADCdata();
    setPORTC(step); //seting output on first 8 leds on PortC
    setPORTD(step>>8);    // output on the last 2 leds on portD
    //_delay_ms(500); // if need to put delay here to avoid flickering or set the pre scaler
    int data=(step*5)/1.024;
    itoa(data,buffer,10);
    
    
    if (state)
    {
        LCD_String_xy(1,7,cl);
        LCD_String_xy(1,7,buffer);
        startConv();
        state=0;
    }
    else 
    {
        LCD_String_xy(0,7,cl);
        LCD_String_xy(0,7,buffer);
        startConv();
        state=1;
    }
    _delay_ms(500);
}


int main(void) {
    /* Replace with your application code */
    PORTCas(OUT);
    PORTDas(OUT);
        
    LCD_Init();
    ADC_init(); // input to trigger is  on ADC0
    
    sei();   //Global interrupt is ON
    startConv(); 
    
    LCD_String_xy(0, 0, st1);
    LCD_String_xy(0, 13, st2);
    LCD_String_xy(1, 0, st1);
    LCD_String_xy(1, 13, st2);
   
    while (1) 
    {
    }
}
