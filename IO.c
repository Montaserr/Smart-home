#include "Config.h"

void SetPortDir(int PortNum, int Statue) {

    if (Statue) {
        switch (PortNum) {
            case _PA:
                DDRA = 0xFF;
                break;
            case _PB:
                DDRB = 0xFF;
                break;
            case _PC:
                DDRC = 0xFF;
                break;
            case _PD:
                DDRD = 0xFF;
                break;
        }
    } else {
        switch (PortNum) {
            case _PA:
                DDRA = 0x00;
                break;
            case _PB:
                DDRB = 0x00;
                break;
            case _PC:
                DDRC = 0x00;
                break;
            case _PD:
                DDRD = 0x00;
                break;

        }

    }

}

void SetPortData(int PortNum, int Data) {
    switch (Data) {
        case ON:
            Data = 0xFF;
            break;
        case OFF:
            Data = 0x00;
            break;
    }

    switch (PortNum) {
        case _PA:
            PORTA = Data;
            break;
        case _PB:
            PORTB = Data;
            break;
        case _PC:
            PORTC = Data;
            break;
        case _PD:
            PORTD = Data;
            break;

    }

}

void TogglePort(int PortNum) {

    switch (PortNum) {
        case _PA:
            PORTA ^= 0xFF;
            break;
        case _PB:
            PORTB ^= 0xFF;
            break;
        case _PC:
            PORTC ^= 0xFF;
            break;
        case _PD:
            PORTD ^= 0xFF;
            break;

    }


}

void SetPinDir(int PortNum, int PinNum, int Statue) {
    if (Statue) {
        switch (PortNum) {
            case _PA:
                DDRA |= (1 << PinNum);
                break;
            case _PB:
                DDRB |= (1 << PinNum);
                break;
            case _PC:
                DDRC |= (1 << PinNum);
                break;
            case _PD:
                DDRD |= (1 << PinNum);
                break;
        }
    } else {
        switch (PortNum) {
            case _PA:
                DDRA &= ~(1 << PinNum);
                break;
            case _PB:
                DDRB &= ~(1 << PinNum);
                break;
            case _PC:
                DDRC &= ~(1 << PinNum);
                break;
            case _PD:
                DDRD &= ~(1 << PinNum);
                break;

        }

    }


}

void SetPinData(int PortNum, int PinNum, int Data) {
    if (Data) {
        switch (PortNum) {
            case _PA:
                PORTA |= (1 << PinNum);
                break;
            case _PB:
                PORTB |= (1 << PinNum);
                break;
            case _PC:
                PORTC |= (1 << PinNum);
                break;
            case _PD:
                PORTD |= (1 << PinNum);
                break;
        }
    } else {
        switch (PortNum) {
            case _PA:
                PORTA &= ~(1 << PinNum);
                break;
            case _PB:
                PORTB &= ~(1 << PinNum);
                break;
            case _PC:
                PORTC &= ~(1 << PinNum);
                break;
            case _PD:
                PORTD &= ~(1 << PinNum);
                break;

        }

    }


}

void TogglePin(int PortNum, int PinNum) {

    switch (PortNum) {
        case _PA:
            PORTA ^= (1 << PinNum);
            break;
        case _PB:
            PORTB ^= (1 << PinNum);
            break;
        case _PC:
            PORTC ^= (1 << PinNum);
            break;
        case _PD:
            PORTD ^= (1 << PinNum);
            break;

    }

}

void Init_Leds() {

    SetPinDir(_PC, Led0, OUT);
    SetPinDir(_PC, Led1, OUT);
    SetPinDir(_PD, Led2, OUT);
}

void Init_Buzzer() {

    SetPinDir(_PD, Buzzer, OUT);
}

void Init_Relay() {
    SetPinDir(_PA, Relay, OUT);
}

void Init_Buttons() {
    SetPinDir(_PB, Btn0, OUT);
    SetPinDir(_PD, Btn1, OUT);
    SetPinDir(_PD, Btn2, OUT);

}

void Set_Led(int LedNum, int state) {
    switch (LedNum) {
        case Led0:
            SetPinData(_PC, Led0, state);
            break;
        case Led1:
            SetPinData(_PC, Led1, state);
            break;
        case Led2:
            SetPinData(_PD, Led2, state);
            break;

    }
}

void Set_Buzzer(int state) {
    SetPinData(_PD, Buzzer, state);
}

void Set_Relay(int state) {
    SetPinData(_PA, Relay, state);

}

int IsPressed(int PortNum, int ButtonNum) {
    switch (PortNum) {
        case _PA:
            return (PINA & (1 << ButtonNum)) ? 1 : 0;
            break;
        case _PB:
            return (PINB & (1 << ButtonNum)) ? 1 : 0;
            break;
        case _PC:
            return (PINC & (1 << ButtonNum)) ? 1 : 0;
            break;
        case _PD:
            return (PIND & (1 << ButtonNum)) ? 1 : 0;
            break;
        default:
            return 0;

    }
}
