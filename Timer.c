#include "Config.h"

void init_Timer(int mode, int ClockSelect) {

    TCCR0 = 0x00;

    TCCR0 |= mode;

    TCCR0 |= ClockSelect;
    

}

void Set_OC(unsigned char OutCompareValue) {
    OCR0 = OutCompareValue;
}

void Timer_Int_Enable(int selectInt) {
    
    TIMSK |= (1 << selectInt);
}
void Timer_Int_Disable(int selectInt) {
    
    TIMSK &= ~(1 << selectInt);
}
void Compare_Match_Mode(int mode){
    TCCR0 &= 0xDF;
    TCCR0 |= mode;
}
