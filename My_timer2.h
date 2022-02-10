

#ifndef MY_TIMER2_H



#define _mode_normal 0
#define _mode_ctc 0x08
#define _mode_pwm 0x40
#define _mode_fpwm 0x48

#define timer_off 0
#define no_pre 1
#define pre8 2
#define pre64 3
#define pre256 4
#define pre1024 5
#define ext_falling 6
#define ext_rising 7

#define INT_TOV2       TOIE2     
#define INT_TOC2       OCIE2

#define ClearOnComp   2
#define SetOnComp     3

void init_timer2(int _mode , int c_s);
void Timer2_enable_INT(int selectINT);
void setOutCompare2(unsigned char compareValue);
void setOC0Mode2(int OC0_Mode);


//#include <avr/iom32a.h>
#include "config.h"
#include <avr/io.h>


#endif	/* MY_TIMER2_H */

