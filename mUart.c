/*
 * File:   mUart.c
 * Author: Toshiba
 *
 * Created on 05 ????, 2020, 03:39 ?
 */

#define F_CPU 16000000 UL

#include <xc.h>
//#define F_CPU 8000000 UL
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mUart.h"


//void main(void) {
//    return;
//}
void UART_init(int Baudrate)
{
   UCSRB |= (1<<TXEN) | (1<<UDRIE); // ENABLE TRANSMITTER.. ENABLE UDRE INTERRUPT
  // UBRRL =51; // calculated from    Baud rate and frequency of oscillation 
   int value =((F_CPU/(16.0*Baudrate))-1);
   UBRRL =(char)(value);// char because i want to access the first 8 bits only 
   UBRRH = (value>>8);
}

void transmit_char(char data)
{
    //Pooling Interrupt
      while(!(UCSRA & (1<<UDRE)));  // wait for flag
      // checking the flag of UDRE instead of using it as an interrupt, we will use it to write directly 
    // but we have to check whether it is empty or not cause e cannot send data directly
    // WHILE NOT TRUE IT IS FALSE THEN IT WILL BREAK OUT THE WHILE LOOP
    //For instance it is not empty, which means that UDRE is not empty then !false , 
    //it will be true , subsequently it will be in the loop         
          UDR=data;
}

void transmit_string(char* data)
{
 for (int i=0; data[i]!='\0'; i++)
    {
     transmit_char(data[i]);
    }
}

void transmit_int(int value)
{
    //Pooling Interrupt
    int buff[10];
      itoa(value,buff,10);
      transmit_string(buff);
}