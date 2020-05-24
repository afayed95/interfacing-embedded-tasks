/*
 * File:   Main.c
 * Author: Toshiba
 *
 * Created on 24 ????, 2020, 06:47 ?
 */


#include <avr/io.h>
#include <xc.h>
#include "mSPI.h"



void SPI_init(int SPI_Mode , int Prescaler)
{
    DDRB |=(1<<MOSI) | (1<<SS) |(1<<SCK);
    SPCR =(SPI_Mode<<MSTR ) |(Prescaler<<0);
    SPCR=(1<<SPE) ;
            
}

void SPI_Write(char data)
{
        SPDR=data; // must be before the while loop to make sure it sent atleast once and the flag will set to 1 and it is initiallized by 
// zero initial value of the flag is 0
    while(!(SPSR & (1<<SPIF) ));
}