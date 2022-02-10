#include "Config.h"

int TWI_start(char address_R_W) {
    char status_bus;

    // SEND START CONDITION....
    TWCR |= ((1 << TWINT) | (1 << TWSTA) | (1 << TWEN));

    //WAIT INTERRUPT FLAG...... 
    while (!(TWCR & (1 << TWINT)));

    // CHECK STATUS REGISTER......
    status_bus = TWSR & 0xF8;

    if (status_bus != 0x08) {
        return 0;
    }
    TWDR = address_R_W;

    TWCR |= ((1 << TWINT) | (1 << TWEN));

    //WAIT INTERRUPT FLAG...... 
    while (!(TWCR & (1 << TWINT)));

    // CHECK STATUS REGISTER......
    status_bus = TWSR & 0xF8;

    //CHECK IF ACK HAS BEEN RECIVED FOR MASTER TRANMITTER MODE.....
    if (status_bus == 0x18) {
        return 1;
    }
    //CHECK IF ACK HAS BEEN RECIVED FOR MASTER RECIEVER MODE.....
    if (status_bus == 0x40) {
        return 2;
    }

    return 1;


}

void TWI_stop() {

    // SEND START CONDITION....
    TWCR |= ((1 << TWINT) | (1 << TWSTO) | (1 << TWEN));

    while (TWCR & (1 << TWSTO));
}

int TWI_write(char Data) {
    char status_bus;

    TWDR = Data;

    TWCR |= ((1 << TWINT) | (1 << TWEN));

    while (!(TWCR & (1 << TWINT)));

    status_bus = TWSR & 0xF8;

    if (status_bus == 0x28) {
        return 1;
    } else {
        return 0;

    }


}

char TWI_read() {

    TWCR |= ((1 << TWINT) | (1 << TWEA) | (1 << TWEN));

    while (!(TWCR & (1 << TWINT)));

    return TWDR;


}


