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


char newline[] = "\t\r"; // adding new line to adjust our dislay 
char string[] = "Hello ya bro";
char state1[] = "Led 1 is On \t\r"; // \t \r new line
char state2[] = "Led 1 is OFF\t\r"; // \t \r new line


//ISR(USART_UDRE_vect)  //  DOn't depend on interrupt in case of sending or trnasmitting
//{
//    UDR= 'A'; 
//}

ISR(USART_RXC_vect) {
    char receive = UDR;
    if (receive == 'T') // TOGGLE FOR EXAMPLE
    {
        {
            PORTC ^= (1 << LED1);
            if (isPressedC(LED1)) {
                transmit_string(state1);
            } else {
                transmit_string(state2);
            }

            if (receive == 'O') {
                PORTC |= (1 << LED1);
                transmit_string(state1);
                newline();
            }
            if (receive == 'F') {
                PORTC &= ~(1 << LED1);
                transmit_string(state2);
                newline();

            }
        }

        //          transmit_char('a');
        //           transmit_string(string);       
        _delay_ms(500); // cause without it it will send too much data 
    }
}


    int main(void) {
        /* Replace with your application code */
        PINBas(Button0, IN);
        PINCas(LED1, OUT);
        PINDas(LED2, OUT);
        UART_init(9600); // enable the UART ..Transmitter only 
        //UDR= 'A'; // at least one time write it manually then once it is cleared it 'll enter automatically in the ISR 
        // sei(); //Global Interrupt  to close it to send it once or from UDRIE
       // SPI_init(Master , F_PS128);
        sei(); // enabling global interrupt


        while (1) {

        }
    }
