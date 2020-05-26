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
#define SS      4
#define MOSI    5
#define MISO    6
#define SCK     7

char newline[] = "\t\r"; // adding new line to adjust our dislay 
char string[] = "Hello ya bro";
char state1[] = "Led 1 is On \t\r"; // \t \r new line
char state2[] = "Led 1 is OFF\t\r"; // \t \r new line

unsigned char counter=0;
unsigned char data;
    
void SPI_Master_init() 
{
    // Data Direction Configuration
    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0) | (1 << SPIE);
}
void SPI_Slave_init()
{
    // Data Direction Configuration
    DDRB |= (1 << MISO);
    SPCR |= (1 << SPE) | (1 << SPR1) | (1 << SPR0) | (1 << SPIE);
}
void SPI_write(char data)           //TX SPI 
{
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

//char SPI_read()  // RX:SPI: replaced in main
//{
//    data = SPDR;
//    return data;
//}

//ISR(SPI_STC_vect)  //TX SPI replaced by pooling in the main
//{
//    SPI_write(counter++);
//}

//ISR(SPI_STC_vect)   //RX SPI : deleted and replaced by pooling in the main  
//{
//    PORTC = SPI_read();
//}
        int main(void) {
        /* Replace with your application code */
//        PINCas(LED1, OUT);
//        PINDas(LED2, OUT);
          DDRC |= 0XFF;  
       // UART_init(9600); // enable the UART ..Transmitter only         
        SPI_Master_init();
        SPI_Slave_init();
        SPI_write(counter); //at least one time to trigger the ISR of the SPI
        sei(); // enabling global interrupt
        while (1) 
        {
            SPI_write(counter++);             // for master in SPI
            _delay_ms(5000);
             while (!(SPSR & (1 << SPIF)));     // for slave in SPI
             PORTD =SPDR;
            
                    
        }
    }
