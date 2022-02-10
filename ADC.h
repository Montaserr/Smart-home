/* 
 * File:   ADC.h
 * Author: MaH MeD
 *
 * Created on October 19, 2021, 7:02 PM
 */

#ifndef ADC_H
#define	ADC_H


#define _CH0       PA0
#define _CH1       PA1
#define _CH2       PA2
#define _CH3       PA3
#define _CH4       PA4
#define _CH5       PA5
#define _CH6       PA6
#define _CH7       PA7

// References
#define _AREF           0   // 00
#define _AVCC           1   // 01
#define _2_56V          3   // 11

#define _PRE2           1 
#define _PRE4           2 
#define _PRE8           3 
#define _PRE16          4 
#define _PRE32          5
#define _PRE64          6
#define _PRE128         7        // 111

#define Right_Adjusted  0
#define Left_Adjusted   1

void init_ADC(int selectChannel,int Ref,int LA,int PS);
void Start_Conversion();
int ADC_READ_Right();
int ADC_READ_Left();
void ADC_Int_Enable();


#endif	/* ADC_H */

