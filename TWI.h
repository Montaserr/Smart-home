/* 
 * File:   TWI.h
 * Author: MaH MeD
 *
 * Created on November 8, 2021, 6:56 PM
 */

#ifndef TWI_H
#define	TWI_H

#define mAddress     0x06
#define SLA_R        0x03  //SLA+R == 0000001+1
#define SLA_w        0x02  //SLA+W == 0000001+0

int TWI_start(char address_R_W);
void TWI_stop();
int TWI_write(char Data);
char TWI_read();    

#endif	/* TWI_H */

