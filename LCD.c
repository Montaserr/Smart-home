#include "Config.h"

void Init_Lcd() {
    SetPortDir(LCD_Data_Dir, OUT);

    SetPinDir(LCD_Control_Dir, RS, OUT);
    SetPinDir(LCD_Control_Dir, RW, OUT);
    SetPinDir(LCD_Control_Dir, E, OUT);

    SetPinData(LCD_Control, RW, OFF);

    // Configuration LCD.....
    _delay_us(10);
    LCD_clear();

    // slect 8-bit mode
    Lcd_cmd(_8bit_mode);
    _delay_us(10);

    Lcd_cmd(_D_ON_C_OFF);
    _delay_us(10);

    Lcd_cmd(Entery_mode);
    _delay_us(10);

    Lcd_cmd(Return_home);
    _delay_us(10);
}

void Lcd_cmd(char cmd) {
    //select command Register......
    SetPinData(LCD_Control, RS, OFF);
    //set command....
    SetPortData(LCD_Data, cmd);
    // Send triger....
    LCD_enable();


}

void LCD_enable() {
    SetPinData(LCD_Control, E, ON);
    _delay_us(50);
    SetPinData(LCD_Control, E, OFF);
}

void LCD_clear() {

    Lcd_cmd(0x01);
    _delay_us(10);

}

void Lcd_Write(char data) {
    SetPinData(LCD_Control, RS, ON);

    SetPortData(LCD_Data, data);

    LCD_enable();
}

void LcdWrite_str(char *str) {

    for (int i = 0; str[i] != '\0'; i++) {

        Lcd_Write(str[i]);

    }
}

void LcdWrite_num(int num) {

    char buffer[11];
    
    itoa(num, buffer, 10);

    LcdWrite_str( buffer );

}