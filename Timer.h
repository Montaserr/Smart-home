/* 
 * File:   Timer.h
 * Author: MaH MeD
 *
 * Created on October 16, 2021, 4:13 PM
 */

#ifndef TIMER_H
#define	TIMER_H


#define Normal_mode             0x00
#define PWM_mode                0x40
#define CTC_mode                0x08
#define FPWM_mode               0x48


#define CS_Timer_off            0
#define CS_NO_prescaling        1
#define CS_prescal_8            2
#define CS_prescal_64           3
#define CS_prescal_256          4
#define CS_prescal_1024         5
#define CS_EX_Clock_Falling     6
#define CS_EX_Clock_Rising      7

#define INT_TOV                 TOIE0
#define INT_OC                  OCIE0

#define min                     0
#define sec                     5

#define COM_OFF_NON_PWM         0 
#define COM_Toggle_NON_PWM      0x10 
#define COM_Clear_NON_PWM       0x20    
#define COM_set_NON_PWM         0x30 

#define COM_OFF_PWM             0                     
#define COM_Clear_PWM           0x20    
#define COM_set_PWM             0x30 

#define COM_OFF_FPWM            0                     
#define COM_Clear_FPWM          0x20    
#define COM_set_FPWM            0x30 

#define Sec_factor              61


void init_Timer(int mode, int clockSelect);
void Set_OC(unsigned char OutCompareValue);
void Timer_Int_Enable(int selectInt);
void Timer_Int_Disable(int selectInt);
void Compare_Match_Mode(int mode);


#endif	/* TIMER_H */

