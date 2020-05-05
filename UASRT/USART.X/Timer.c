/*
 * File:   Timer.c
 * Author: Toshiba
 *
 * Created on 04 ????, 2020, 09:48 ?
 */


#include <xc.h>

//void main(void) {
//    return;
//}
#include "DIO.h"
#include "Timer.h"


//void main(void) {
//    return;
//}
void _timer0_init(char TimerMode, char OCOMode, char OCR0_Value)
{
    TCCR0 =0x00;
    TIMSK =0x00;
    switch(TimerMode)
    {
        case Normal:
            TIMSK |= (1<<TOIE0);
            break;
         case CTC:
             TCCR0 |= (1<<WGM01) ;
             TIMSK |= (1<<OCIE0);
            break;
        case FastPwm:
            TCCR0 |= (1<<WGM00) | (1<<WGM01) ;
            break;
        case Pwm:
            TCCR0 |=(1<<WGM00);
            break;
    }
    TCCR0 |= (OCOMode<<4);
    OCR0=OCR0_Value;
    TCCR0 |=(1<<CS02)| (1<<CS00);
    PINBas(3,OUT);
}

void _timer0_reset()
{
    TCCR0 &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));
}

void _timer2_init(char TimerMode, char OCOMode, char OCR0_Value)
{
    TCCR2 =0x00;
    TIMSK =0x00;
    switch(TimerMode)
    {
        case Normal:
            TIMSK |= (1<<TOIE2);
            break;
         case CTC:
             TCCR2 |= (1<<WGM21) ;
             TIMSK |= (1<<OCIE2);
            break;
        case FastPwm:
            TCCR2 |= (1<<WGM20) | (1<<WGM21) ;
            break;
        case Pwm:
            TCCR2 |=(1<<WGM20);
            break;
    }
    TCCR2 |= (OCOMode<<4);
    OCR2=OCR0_Value;
    TCCR2 |=(1<<CS22)| (1<<CS20);
    PINBas(3,OUT);
}

void _timer2_reset()
{
    TCCR2 &= ~((1<<CS22) | (1<<CS21) | (1<<CS20));
}
