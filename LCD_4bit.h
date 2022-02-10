/* 
 * File:   LCD_4bit.h
 * Author: MaH MeD
 *
 * Created on October 8, 2021, 2:35 PM
 */

#ifndef LCD_4BIT_H
#define	LCD_4BIT_H



#define LCD_Half_Data  PORTA
#define LCD_Half_Dir   DDRA


#define _ROW0    0
#define _ROW1    1



void Init_Lcd_4bit ();
void Lcd_Write_4bit (char data);
void LcdWrite_str_4bit (char *str);
void LcdWrite_num_4bit (int num);

void Lcd_cmd_4bit (char cmd);
void LCD_enable_4bit();
void LCD_clear_4bit();
void LCD_goto_4bit(int row, int column);




#endif	/* LCD_4BIT_H */

