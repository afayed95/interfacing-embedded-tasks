/*
 * File:   Main.c
 * Author: Toshiba
 *
 * Created on 04 ????, 2020, 09:45 ?
 */

#define F_CPU 16000000UL
#include <xc.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "BoardConfig.h"
#include "Config.h"
#include "DIO.h"
#include "ADC.h"
#include "mUart.h"
#include "mTimer.h"



char newline[]= "\t\r"; // adding new line to adjust our dislay 
char string[]="Hello ya bro";
char state1[]="Led is On \t\r"; // \t \r new line
char state2[]="Led is OFF\t\r"; // \t \r new line
char state3[]="  'C"; 

//ISR(USART_UDRE_vect)  //  DOn't depend on interrupt in case of sending or trnasmitting
//{
//    UDR= 'A'; 
//}

ISR(USART_RXC_vect)
{
    char receive=UDR;
    if (receive=='T') // TOGGLE FOR EXAMPLE
    {
        {
          PORTC ^=(1<<LED1);
          if (isPressedC(LED1))
          {
              transmit_string(state1);
          }
          else
          {
              transmit_string(state2); 
          }
          
          if (receive=='O')
          {
              PORTC |= (1<<LED1);
            transmit_string(state1);
          }
          if (receive=='F')
          {
              PORTC &= ~(1<<LED1);
            transmit_string(state2);
          }            
          }
          
//          transmit_char('a');
//           transmit_string(string);       
          //_delay_ms(500); // cause without it it will send too much data 
      }
    }

ISR(ADC_vect)
{
    int value_= getADCdata();
    transmit_int(value_*0.49); // conversion value *4.9 as each step is represented by 4.9 mv and divide by 10 as each 1 degree 'c is 
    // is 10 mv
    transmit_string(state3);
    newline();
}
ISR(TIMER0_OVF_vect)
{
    static int _1sec=0;
    _1sec++;
    if(_1sec==31)
    {
        startConv();
        while (!(ADCSRA & (1<<ADIF)));
        int value_= getADCdata();
        int temp=value_*0.49
        transmit_int(temp); // conversion value *4.9 as each step is represented by 4.9 mv and divide by 10 as each 1 degree 'c is 
        // is 10 mv
        transmit_string(state3);
         newline();
         if (temp>75)
         {
             setPINC(LED1);
         }
         else
         {
            resetPIN(LED1,PORT3);
         }
        _1sec=0;
    }
    
}


int main(void) {
    /* Replace with your application code */
     PINBas(Button0,IN);
     PINCas(LED1,OUT);
     sei(); // enabling global interrupt
    UART_init(9600); // enable the UART ..Transmitter only 
    //UDR= 'A'; // at least one time write it manually then once it is cleared it 'll enter automatically in the ISR 
    // sei(); //Global Interrupt  to close it to send it once or from UDRIE
    ADC_init();
    startConv(); // at least one time is needed 
    Timer0_init(NormalMode,OC0_DIS,CLK_io_PS1024) ;
   while (1)
    {
     // if (isPressedB(Button0)) 
      
    }
}
