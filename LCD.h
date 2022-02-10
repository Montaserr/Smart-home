/* 
 * File:   LCD.h
 * Author: MaH MeD
 *
 * Created on October 4, 2021, 3:45 AM
 */

#ifndef LCD_H
#define	LCD_H

#include "Config.h"




void Init_Lcd ();
void Lcd_Write (char data);
void LcdWrite_str (char *str);
void LcdWrite_num (int num);

void Lcd_cmd (char cmd);
void LCD_enable();
void LCD_clear();
void LCD_goto(int row, int column);






#endif	/* LCD_H */

