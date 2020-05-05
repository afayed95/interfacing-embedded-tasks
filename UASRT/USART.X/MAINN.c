/*
 * File:   main.c
 * Author: Hossam Eldeen Altokhy
 *
 * Created on April 4, 2020, 6:24 PM
 */
#define F_CPU 16000000UL



#include <avr/io.h>
#include <util/delay.h>
//#include "Config.h"
#include "DIO.h"
//#include "lcd.h"
#include <avr/interrupt.h>


#define Button2        2
#define LED0           2
#define LED1           7
#define LED2           7
#define Buzzer         3
#define Button1        4
#define Button0        0



#define portA           1
#define portB           2
#define portC           3
#define portD           4

#define  low_level   1
#define toggle       2
#define falling_edge 3
#define raising_edge 4
#define set_zero     1
#define set_one      2
int i = 0;

char x[] = "REM";
char y[] = "TUHH";
char flag = 0;

void INT0_INIT(int mode) {
    switch (mode) {
            case 1:
            MCUCR = 0X00;
            break;
        case 2:
            MCUCR |= (1 << ISC00);
            break;
        case 3:
            MCUCR |= (1 << ISC01);
            break;

        case 4:
            MCUCR |= (1 << ISC01) | (1 << ISC00);
            break;
    }
    GICR |= (1 << INT0);
}

void INT1_INIT(int mode) {
    switch (mode) {
            case 1:
            MCUCR = 0X00;
            break;
        case 2:
            MCUCR |= (1 << ISC10);
            break;
        case 3:
            MCUCR |= (1 << ISC11);
            break;
        case 4:
            MCUCR |= (1 << ISC11) | (1 << ISC10);
            break;
    }
    GICR |= (1  << INT1);
}

void INT2_INIT(int mode) {
    switch (mode) 
    {

        case 1:
            MCUCSR &= ~(1 << ISC2);
        case 2:
            MCUCSR |= (1 << ISC2);
    }
     GICR |= (1 << INT2);

}
//ISR(_VECTOR(1))
ISR(INT0_vect) {
    togglePINC(LED0);
}

ISR(INT1_vect) {
    // when button 1 on port B is pressed interrupt 2 will be activated
     togglePINB(LED2);
     //setPIN(Buzzer, OUT);
}

ISR(INT2_vect)
{
    togglePINC(LED1);
    //setPIN(Buzzer, OUT);
            
}


int main(void) {
    INT0_INIT(raising_edge); // init call it 
    INT1_INIT(raising_edge);
    INT2_INIT(2);
    sei();
    PINBas(Button0, IN);
    PINBas(Button1, IN);
    PINCas(LED1, OUT);
    PINCas(LED0, OUT);
    PINBas(LED2, OUT);
    
    PINAas(Buzzer, OUT);
    DDRD |=(1<<3);  // interrupt 1 is ON
    DDRB |=(1<<2);  // interrupt 2 is ON 
    
    while (1) 
    {  
      if (isPressedB(Button0))
        { 
            PORTD |=(1<<3);  // set interrupt 1 to high
        }
       if(isPressedB(Button1))
      {
          PORTB |=(1<<2);  // set interrupt 2 to high
           
      }
      else
      {
            PORTD &= ~(1<<3);  // CLOSE IT 
            PORTB &= ~(1<<2);  // CLOSE IT
      }
      _delay_ms(250);      
   }
}

