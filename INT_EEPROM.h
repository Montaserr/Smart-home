

#ifndef INT_EEPROM_H
#define	INT_EEPROM_H


char read_EEPROM(unsigned int  address);
//void read_EEPROM_str(unsigned int  address);
char read_EEPROM_num(unsigned int  address);

void write_EEPROM_num(unsigned int  address ,int num);
void write_EEPROM_str(unsigned int  address ,char *data);
void write_EEPROM(unsigned int  address ,char data);

#endif	/* INT_EEPROM_H */

