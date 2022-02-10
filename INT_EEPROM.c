#include "Config.h"

void write_EEPROM(unsigned int address, char data) {
    
    while (EECR & (1 << EEWE));
    /* Set up address and data registers */
    EEARL = address;
    EEARH |= (address >> 8);

    EEDR = data;
    /* Write logical one to EEMWE */
    EECR |= (1 << EEMWE);
    /* Start eeprom write by setting EEWE */
    EECR |= (1 << EEWE);

}

char read_EEPROM(unsigned int address) {

    /* Wait for completion of previous write */
    while (EECR & (1 << EEWE))
        ;
    /* Set up address register */
    EEARL = address;
    EEARH |= (address >> 8);

    /* Start eeprom read by writing EERE */
    EECR |= (1 << EERE);
    /* Return data from data register */
    return EEDR;
}

void write_EEPROM_str(unsigned int address, char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        write_EEPROM(address, data[i]);
        address++;
    }


}
/*
void read_EEPROM_str(unsigned int address) {
    char user[4];
    for (int i = 0; i < 4; i++) {
        user [i] = read_EEPROM(address);
        address++;
    }
    
}*/

void write_EEPROM_num(unsigned int address, int num) {
    char buffer[5];
    itoa(num, buffer, 10);

    for (int i = 0; i < 4; i++) {
        write_EEPROM(address, buffer[i]);
        address = address + 1;
    }
}
