#include "Config.h"

void Init_Lcd_4bit() {

    LCD_Half_Dir |= 0xF0;

    SetPinDir(LCD_Control_Dir, RS, OUT);
    SetPinDir(LCD_Control_Dir, RW, OUT);
    SetPinDir(LCD_Control_Dir, E, OUT);

    SetPinData(LCD_Control, RW, OFF);

    // Configuration LCD.....
    
    LCD_clear_4bit();
    
    // slect 8-bit mode
    Lcd_cmd_4bit(0x02);
    
    Lcd_cmd_4bit(0x28);
   

    Lcd_cmd_4bit(0x0C);
    

    Lcd_cmd_4bit(0x06);
    

    
   
    LCD_clear_4bit();
    _delay_ms(1);
}

void Lcd_cmd_4bit(char cmd) {
    //select command Register......
    SetPinData(LCD_Control, RS, OFF);
    //set command....
    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (cmd & 0xF0);
    LCD_enable_4bit();
    _delay_ms(1);
    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (cmd << 4);

    // Send triger....
    LCD_enable_4bit();
    _delay_ms(1);

}

void LCD_enable_4bit() {
    SetPinData(LCD_Control, E, ON);
    _delay_ms(5);
    SetPinData(LCD_Control, E, OFF);
}

void LCD_clear_4bit() {

    Lcd_cmd_4bit(0x01);
    _delay_ms(1);

}

void Lcd_Write_4bit(char data) {
    SetPinData(LCD_Control, RS, ON);
    //set command....
    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (data & 0xF0);
    LCD_enable_4bit();
    _delay_ms(1);
    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (data << 4);

    // Send triger....
    LCD_enable_4bit();
    _delay_ms(1);
}

void LcdWrite_str_4bit(char *str) {

    for (int i = 0; str[i] != '\0'; i++) {

        Lcd_Write_4bit(str[i]);

    }
}

void LcdWrite_num_4bit(int num) {

    char buffer[11];

    itoa(num, buffer, 10);
    

    LcdWrite_str_4bit(buffer);

}
void LCD_goto_4bit(int row, int column){
    
    switch(row){
        case _ROW0:
            Lcd_cmd_4bit(0x80 | column);
            break;
        case _ROW1:
            Lcd_cmd_4bit(0xC0 | column);
            break;       
    }
}