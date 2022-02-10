#include "Config.h"

void init_INT(int _IntNum, int mode) {


    switch (_IntNum) {
        case INT0:

            // select mode from (Rising ,Falling ,Any_Change ,Low_Level)....

            MCUCR &= ~((1 << ISC00) | (1 << ISC01));
            MCUCR |= mode ;

            //Enable INT0..........

            GICR |= (1 << INT0);

            break;
        case INT1:
            // select mode from (Rising ,Falling ,Any_Change ,Low_Level)....

            MCUCR &= ~((1 << ISC10) | (1 << ISC11));
            MCUCR |= (mode << 2);

            //Enable INT1..........

            GICR |= (1 << INT1);

            break;
        case INT2:
            // select mode from (INT2_Rising ,INT2_Falling )....
            MCUCSR |= (mode << ISC2);

            //Enable INT2..........

            GICR |= (1 << INT2);

            break;


    }

}



