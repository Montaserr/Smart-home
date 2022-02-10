/* 
 * File:   IO.h
 * Author: MaH MeD
 *
 * Created on October 4, 2021, 1:43 AM
 */

#ifndef IO_H
#define	IO_H

#define Led0   PC2
#define Led1   PC7
#define Led2   PD3

#define Buzzer PD5

#define Relay  PA2

#define Btn0   PB0
#define Btn1   PD6
#define Btn2   PD2

// PORT CONFIGURETION................

void SetPortDir(int PortNum, int Statue);
void SetPortData(int PortNum, int Data);
void TogglePort(int PortNum);

// PIN CONFIGURETION................

void SetPinDir(int PortNum, int PinNum, int Statue);
void SetPinData(int PortNum, int PinNum, int Data);
void TogglePin(int PortNum, int PinNum);

void Init_Leds();
void Init_Buzzer();
void Init_Relay();
void Init_Buttons();

void Set_Led(int LedNum, int state);
void Set_Buzzer(int state);
void Set_Relay(int state);
int IsPressed(int PortNum, int ButtonNum);





#endif	/* IO_H */

