#include <xc.h>


void Timer0_init(char TimerMode, char CompOUTMode, char Clk_S) {

    //    switch()
    if (CompOUTMode) {
        DDRB |= (1 << 3); // PINB3 (OC0) as OUTPUT.
    }

    TCCR0 |= (TimerMode << 3) | (CompOUTMode << 4);
    TCCR0 |= (Clk_S << 0);
    TIMSK |= (1 << OCIE0) | (1 << TOIE0); // Enable Interrupt OVF
    
}
