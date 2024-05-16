#include "twi.h"
#include <avr/io.h>
#include "bit.h"


void twi_init_master(void) {
    // Set up TWI module for master mode
    TWSR = 0; // Set prescalar for 1
    TWBR = 72; // Set bit rate register (see datasheet)
    TWCR = (1<<TWEN); // Enable TWI
}