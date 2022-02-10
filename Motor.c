#include "Config.h"

void init_Motor(int Motor_No) {

    if (Motor_No) {
        SetPinDir(_PC, H_A3, OUT);
        SetPinDir(_PC, H_A4, OUT);
        SetPinDir(_PD, H_EN2, OUT);
        // Enable
        SetPinData(_PD, H_EN2, ON);
    } else {
        SetPinDir(_PD, H_A1, OUT);
        SetPinDir(_PD, H_A2, OUT);
        SetPinDir(_PD, H_EN1, OUT);
        // Enable
        SetPinData(_PD, H_EN1, ON);
    }


}

void Motor_Forward(int Motor_No) {

    if (Motor_No) {
        SetPinData(_PC, H_A3, ON);
        SetPinData(_PC, H_A4, OFF);
    } else {
        SetPinData(_PD, H_A1, ON);
        SetPinData(_PD, H_A2, OFF);
        SetPinData(_PD, H_EN1, ON);
    }

}

void Motor_Reverse(int Motor_No) {
 if (Motor_No) {
        SetPinData(_PC, H_A3, OFF);
        SetPinData(_PC, H_A4, ON);
    } else {
        SetPinData(_PD, H_A1, OFF);
        SetPinData(_PD, H_A2, ON);
    }
}


void Motor_Stop(int Motor_No){
     if (Motor_No) {
        SetPinData(_PC, H_A3, OFF);
        SetPinData(_PC, H_A4, OFF);
        SetPinData(_PD, H_EN2, OFF);
    } else {
        SetPinData(_PD, H_A1, OFF);
        SetPinData(_PD, H_A2, OFF);
        SetPinData(_PD, H_EN1, OFF);
    }
}

