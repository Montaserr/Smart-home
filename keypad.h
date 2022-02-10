/* 
 * File:   keypad.h
 * Author: MaH MeD
 *
 * Created on November 30, 2021, 1:40 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H


#define KEYPAD_PORT    PORTC
#define KEYPAD_DIR     DDRC
#define _KEPAD         _PC

#define COLUMN0        PC0
#define COLUMN1        PC1
#define COLUMN2        PC2
/////////////////////
#define ROW0           PC3      
#define ROW1           PC4    
#define ROW2           PC5    
#define ROW3           PC6 

void init_keypad();
char getKey();



#endif	/* KEYPAD_H */

