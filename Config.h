/* 
 * File:   Config.h
 * Author: MaH MeD
 *
 * Created on October 4, 2021, 1:45 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#define F_CPU 16000000UL

#define _PA   0
#define _PB   1
#define _PC   2
#define _PD   3

#define IN    0
#define OUT   1

#define ON    1
#define OFF   0


#define LCD_Data          _PA
#define LCD_Data_Dir      _PA

#define LCD_Control       _PB
#define LCD_Control_Dir   _PB

#define clear             0x01
#define _8bit_mode        0x38
#define _4bit_mode        0x28
#define Entery_mode       0x06
#define _D_ON_C_OFF       0x0C
#define Return_home       0x02

#define RS                PB0
#define RW                PB1
#define E                 PB2



#include <util/delay.h>
#include <avr/io.h>
#include "IO.h"
#include "LCD.h"
#include <stdlib.h>
#include "LCD_4bit.h"
#include <avr/interrupt.h>
#include "EX_INT.h"
#include "Timer.h"
#include "ADC.h"
#include "UART.h"
#include "SPI.h"
#include "TWI.h"
#include "Motor.h"
#include "INT_EEPROM.h"
#include "keypad.h"
#include "My_timer2.h"

#include <string.h>


#include "Database.h"
#include "applayer_uart.h"
#include "applayer_keypad.h"


#endif	/* CONFIG_H */

