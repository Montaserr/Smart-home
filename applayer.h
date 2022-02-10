/* 
 * File:   applayer.h
 * Author: MaH MeD
 *
 * Created on November 21, 2021, 7:02 PM
 */

#ifndef APPLAYER_H
#define	APPLAYER_H

#define LED1      PC0
#define LED2      PC1
#define LED3      PC2
#define LED4      PC3
#define LED5      PC4

void app_start_uart();
char app_home_uart();
int app_options_uart(char option);

void app_start_keypad();
char app_home_keypad();
int app_options_keypad(char option);

int app_Leds ();
int app_Ac();
int app_Door();

void Lm_35();


#endif	/* APPLAYER_H */

