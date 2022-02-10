/*
 * File:   main.c
 * Author: MaH MeD
 *
 * Created on October 4, 2021, 1:42 AM
 */


#include <avr/io.h>
#include "Config.h"
ISR(USART_RXC_vect){
    int _f1=1;
    char zz=uart_receive();
    app_start_uart();
    while (_f1){
        char option = app_home_uart();
        _f1 = app_options_uart(option);
        
    }
    
    
}

ISR(TIMER0_OVF_vect) {

    static int x;
    x++;
    if (x == 62 * sec) {
        Lm_35();
        x = 0;
    }

}

int main(void) {

    char object[] = "1111";
    char object_1[] = "2222";
    char admin[] = "admn";
    write_EEPROM_str(0, object);
    write_EEPROM_str(4, object_1);
    write_EEPROM_str(50, admin);
    write_EEPROM_num(100, 1111);
    write_EEPROM_num(104, 2222);
    write_EEPROM_num(150, 3333);


    Init_Buzzer();
    init_keypad();

    init_uart(9600, Rx_enable, Tx_enable);
    UCSRB |=(1<<RXCIE);
    Init_Lcd_4bit();
    _delay_ms(10);




    sei();

    int __f = 1;

    while (1) {

        if (__f == 1)
            app_start_keypad();

        char option = app_home_keypad();

        __f = app_options_keypad(option);



    }
}