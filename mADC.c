
#include <xc.h>
#include <avr/interrupt.h>

extern int data;


void ADC_init(char channel, char ref, char prescaler, char isInterrupt, char isAutoT){
     // ADC Init
    ADMUX = (channel<<0)|(ref<<6);
    ADCSRA = (prescaler << 0) | (isInterrupt << 3)| (isAutoT << 5)| (1<<ADEN);
}
void ADC_startConv(){
    ADCSRA |= (1 << ADSC); // Start Conversion
}
void ADC_readData(int *pData){
    //Reading Data
    *pData = ADCL;
    *pData |= (ADCH << 8);
}

ISR(ADC_vect) {
    // ADC Interrupt

    ADC_readData(&data);
    
    data *= 4.9; // in mV  // 1.5V >> 1500mV

    data /= 10; // in C
    ADC_startConv();
}