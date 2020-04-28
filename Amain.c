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


char str1[] = "Volt = ";
char str2[] = " mV";
char cl[] = "    ";

void INT0_init() 
{
    MCUCR |= (1 << ISC01) | (1 << ISC00); // Rising Edge
    GICR |= (1 << INT0); 
}

void ADC_init() 
{
    ADMUX = 0x41; // Channel 0
    SFIOR |=  (1<<ADTS1); //special function input output register 
    // SFIOR must be before ADCSRA !!!!!! 
    ADCSRA |= (1 << ADEN) |(1 << ADIE) |(1<<ADATE) | (1 << ADPS2) |(1 << ADPS1) | (1 << ADPS0) ;
     // if i needed to put the pre scaler with f/128
    //AADATE is auto trigger enable to connect between ADC and interrupt0
    //SFIOR |=  (1<<ADTS1); //special function input output register
}
void startConv() 
{
    ADCSRA |= (1 << ADSC);
}

//void Selecting_channel(unsigned int channel )
//{
//    
//    ADMUX &= ~(7<<0);  //00000111 11111000
//    ADMUX |= channel;  
//}
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
     int static state =1 ;
    char buffer[20];  
    int step =getADCdata();
//    setPORTC(step); //seting output on first 8 leds on PortC
//    setPORTD(step>>8);    // output on the last 2 leds on portD
    //_delay_ms(500); // if need to put delay here to avoid flickering or set the pre scaler
    int data=(step*5)/1.024;
    itoa(data,buffer,10);
    
//        LCD_String_xy(0,7,cl); // clearing lcd to overwrite
//        LCD_String_xy(0,7,buffer);// data after conversion from ADC
    if (data>1000)
    {
        LCD_String_xy(0,7,cl); // clearing lcd to overwrite
        LCD_String_xy(0,7,buffer);// data after conversion from ADC
        setPINA(Relay);
        setPINC(LED1);
        if (state)
        {
         setPINA(Buzzer);
        _delay_ms(1000);
        resetPIN(Buzzer,1);
        setPIND(LED2);
        state=0;
        }
        //startConv();

     //   startConv(); // infinite loop to start conversion right now !!
              // changing state to read from the other sensor
    }
    else 
    {
        LCD_String_xy(0,7,cl); // clearing lcd to overwrite
        LCD_String_xy(0,7,buffer);// data after conversion from ADC
        resetPIN(Relay,1);
        resetPIN(LED1,3);
        resetPIN(LED2,4);  
        //startConv();
        
    }
    _delay_ms(500); // delay to adjust the ADC O/P
   // startConv();

}

ISR(INT0_vect)
{
    static int triggered=1;
    if(triggered)
    {
        startConv();
        triggered=0; // set it to zero to confirm that I entered it once
    }
}

int main(void) {
    PORTCas(OUT);
    //PORTDas(OUT);
    PINDas(LED2,OUT);
    PINDas(Button2,IN);
    PINAas(Relay, OUT);
    PINAas(LM35,IN);
    //PINAas(Buzzer, OUT);
        
    LCD_Init(); //initializing the LCD
    ADC_init(); // input to trigger is  on ADC0 and ADC 1
   INT0_init();//  setting interrupt int0  ON as well as adjusting interrupt on BUTTON2 
    sei();   //Global interrupt is ON
    
    LCD_String_xy(0, 0, str1);
    LCD_String_xy(0, 12, str2);
       // startConv();  //it was set when Interrupt is triggered

    
    while (1) 
    {
    }
}
