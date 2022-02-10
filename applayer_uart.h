/* 
 * File:   applayer_uart.h
 * Author: MaH MeD
 *
 * Created on November 30, 2021, 4:41 PM
 */

#ifndef APPLAYER_UART_H
#define	APPLAYER_UART_H


#define LED1      PB4
#define LED2      PB5
#define LED3      PB6
#define LED4      PB7
#define LED5      PC7

void app_start_uart();
char app_home_uart();
int app_options_uart(char option);


int app_Leds_uart ();
int app_Ac_uart();
int app_Door_uart();
void Lm_35();

int Delete_user();

#endif	/* APPLAYER_UART_H */

