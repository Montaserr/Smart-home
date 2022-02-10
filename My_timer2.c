#include "Config.h"

void init_timer2(int _mode, int c_s) {
    TCCR2 &= ~((1 << WGM20) | (1 << WGM21));
    TCCR2 &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
    
    
    
    TCCR2 |= _mode;
    TCCR2 |= c_s;
    
}
void Timer2_enable_INT(int selectINT){
    
    TIMSK |= (1<<selectINT);
}

void setOutCompare2(unsigned char compareValue){
    OCR2 = compareValue;
}

void setOC0Mode2(int OC0_Mode){
    // Config Data Direction for OC0 pin ***********
    SetPinDir(_PD, PD7, OUT);
    TCCR2 &= ~((1<<COM21)|(1<<COM20));
    TCCR2 |= (OC0_Mode << COM20);
}