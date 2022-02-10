
#include "Config.h"
#include "My_timer2.h"

char x[] = "Enter admin user :";
char xx[] = "Enter admin password :";
char xxx[] = "Accesed";
char xxxx[] = "Access Denied";
char Y1[] = "user or password is incorrect";
char y2[] = "Wellcome ....";
char y3[] = "1 >>> DOOR";
char y4[] = "2 >>> LEDS";
char y5[] = "3 >>> AC";

char y55[] = "4 >>> Delete user";
char y56[] = "5 >>> LOG OUT";

char y6[] = "1 >>> LED1";
char y7[] = "2 >>> LED2";
char y8[] = "3 >>> LED3";
char y9[] = "4 >>> LED4";
char y10[] = "5 >>> LED5 (Dimming LED)";
char y11[] = "0 >>> Return Home";

char y12[] = "1 >>> ON";
char y13[] = "2 >>> OFF";

char y14[] = "1 >>> ON";
char y15[] = "2 >>> OFF";
char y16[] = "1 >>> OPEN";
char y17[] = "2 >>> CLOSE";
char y18[] = "1 >>> LEVEL 1";
char y19[] = "2 >>> LEVEL 2";
char y20[] = "3 >>> LEVEL 3";
char y21[] = "4 >>>  OFF";

char y22[] = "Enter user :";

char y23[] = "User is deleted...";


char __User[20];
char __pass[20];
int __counter;

void app_start_uart() {
    while (1) {
        uart_send_str(x);
        uart_send(13);


        for (int i = 0; __User[i - 1] != '.'; i++) {

            __User[i] = uart_receive();
            _delay_ms(10);
        }
        uart_send(13);
        uart_send_str(xx);
        uart_send(13);





        for (int i = 0; __pass[i - 1] != '.'; i++) {

            __pass[i] = uart_receive();
            _delay_ms(10);
        }
        uart_send(13);



        int z = check_admin(__User, __pass);

        if (z == 1) {
            uart_send_str(xxx);
            uart_send(13);
            for (int i = 0; i < 5; i++) {

                __User[i] = 0;
            }
            for (int i = 0; i < 5; i++) {

                __pass[i] = 0;
            }



            break;



        } else {

            __counter++;


            if (__counter == 3) {
                Set_Buzzer(ON);
                uart_send_str(xxxx);
                uart_send(13);


                while (1);

            }

            uart_send_str(Y1);
            uart_send(13);
            for (int i = 0; i < 5; i++) {

                __User[i] = 0;
            }
            for (int i = 0; i < 5; i++) {

                __pass[i] = 0;
            }








        }




    }

}

char app_home_uart() {

    char data;

    uart_send(13);
    uart_send_str(y2);
    uart_send(13);

    uart_send_str(y3);
    uart_send(13);

    uart_send_str(y4);
    uart_send(13);

    uart_send_str(y5);
    uart_send(13);

    uart_send_str(y55);
    uart_send(13);

    uart_send_str(y56);
    uart_send(13);

    data = uart_receive();



    return data;


}
// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_options_uart(char option) {


    if (option == '1') {
        app_Door_uart();
        return 1;

    } else if (option == '2') {

        app_Leds_uart();
        return 1;

    } else if (option == '3') {
        app_Ac_uart();
        return 1;

    } else if (option == '4') {
        Delete_user();
        return 1;

    } else if (option == '5') {

        return 0;

    }

    return 1;
}


// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_Leds_uart() {
    SetPinDir(_PB, LED1, OUT);
    SetPinDir(_PB, LED2, OUT);
    SetPinDir(_PB, LED3, OUT);
    SetPinDir(_PB, LED4, OUT);
    SetPinDir(_PC, LED5, OUT);
    char data;
    uart_send(13);
    uart_send_str(y6);
    uart_send(13);

    uart_send_str(y7);
    uart_send(13);

    uart_send_str(y8);
    uart_send(13);

    uart_send_str(y9);
    uart_send(13);

    uart_send_str(y10);
    uart_send(13);

    uart_send_str(y11);
    uart_send(13);

    data = uart_receive();

    if (data == '1') {
        char data1;
        uart_send(13);
        uart_send_str(y12);
        uart_send(13);
        uart_send_str(y13);
        uart_send(13);
        uart_send_str(y11);
        uart_send(13);
        data1 = uart_receive();

        switch (data1) {
            case '1':
                SetPinData(_PB, LED1, ON);
                
                break;
            case '2':
                SetPinData(_PB, LED1, OFF);
                break;
            case '0':
                return 0;
                break;
        }


    } else if (data == '2') {
        char data1;
        uart_send(13);
        uart_send_str(y12);
        uart_send(13);
        uart_send_str(y13);
        uart_send(13);
        uart_send_str(y11);
        uart_send(13);
        data1 = uart_receive();
        switch (data1) {
            case '1':
                SetPinData(_PB, LED2, ON);
                break;
            case '2':
                SetPinData(_PB, LED2, OFF);
                break;
            case '0':
                return 0;
                break;
        }

    } else if (data == '3') {
        char data1;
        uart_send(13);
        uart_send_str(y12);
        uart_send(13);
        uart_send_str(y13);
        uart_send(13);
        uart_send_str(y11);
        uart_send(13);
        data1 = uart_receive();

        switch (data1) {
            case '1':
                SetPinData(_PB, LED3, ON);
                break;
            case '2':
                SetPinData(_PB, LED3, OFF);
                break;
            case '0':
                return 0;
                break;
        }

    } else if (data == '4') {
        char data1;
        uart_send(13);
        uart_send_str(y12);
        uart_send(13);
        uart_send_str(y13);
        uart_send(13);
        uart_send_str(y11);
        uart_send(13);
        data1 = uart_receive();
        switch (data1) {
            case '1':
                SetPinData(_PB, LED4, ON);
                break;
            case '2':
                SetPinData(_PB, LED4, OFF);
                break;
            case '0':
                return 0;
                break;
        }

    } else if (data == '5') {
        char data1;
        uart_send(13);
        uart_send_str(y12);
        uart_send(13);
        uart_send_str(y13);
        uart_send(13);
        uart_send_str(y11);
        uart_send(13);
        data1 = uart_receive();
        switch (data1) {
            case '1':
                SetPinData(_PC, LED5, ON);
                break;
            case '2':
                SetPinData(_PC, LED5, OFF);
                break;
            case '0':
                return 0;
                break;
        }

    } else if (data == '6') {

        //Dimming.....
        SetPinDir(_PD, PD7, OUT);
        init_timer2(_mode_fpwm, pre1024);

        char data1;
        uart_send(13);
        uart_send_str(y18);
        uart_send(13);
        uart_send_str(y19);
        uart_send(13);
        uart_send_str(y20);
        uart_send(13);
        uart_send_str(y21);
        uart_send(13);
        data1 = uart_receive();

        if (data1 == '1') {
            setOC0Mode2(ClearOnComp);
            setOutCompare2(200);
        } else if (data1 == '2') {
            setOC0Mode2(ClearOnComp);
            setOutCompare2(100);
        } else if (data1 == '3') {
            setOC0Mode2(ClearOnComp);
            setOutCompare2(20);
        } else if (data1 == '4') {
            init_timer2(_mode_fpwm, timer_off);
        }









    } else if (data == '0') {

        return 0;



    }


    return 1;




}

int app_Ac_uart() {

    char data;
    //ON......
    uart_send(13);
    uart_send_str(y14);
    uart_send(13);

    //OFF.....
    uart_send(13);
    uart_send_str(y15);
    uart_send(13);
    //Return home......
    uart_send(13);
    uart_send_str(y11);
    uart_send(13);

    data = uart_receive();




    if (data == '1') {

        init_Motor(Motor1);
        Motor_Forward(Motor1);


        init_Timer(Normal_mode, CS_prescal_1024);
        Timer_Int_Enable(INT_TOV);

    } else if (data == '2') {

        Motor_Stop(Motor1);
        init_Timer(Normal_mode, CS_Timer_off);
        Timer_Int_Disable(INT_TOV);



    } else if (data == '0') {

        return 0;
    }

    return 1;


}

int app_Door_uart() {

    char data;
    //Open......
    uart_send(13);
    uart_send_str(y16);
    uart_send(13);

    //Close.....
    uart_send(13);
    uart_send_str(y17);
    uart_send(13);
    //Return home......
    uart_send(13);
    uart_send_str(y11);
    uart_send(13);
    data = uart_receive();
    if (data == '1') {
        SetPinDir(_PB, PB3, OUT);
        init_Timer(FPWM_mode, CS_prescal_1024);
        Compare_Match_Mode(COM_Clear_FPWM);
        Set_OC(38); //>>>>>>>>  servo (90)
        _delay_ms(1500);


        init_Timer(Normal_mode, CS_prescal_1024);


    } else if (data == '2') {
        SetPinDir(_PB, PB3, OUT);
        init_Timer(FPWM_mode, CS_prescal_1024);
        Compare_Match_Mode(COM_Clear_FPWM);
        Set_OC(22); //>>>>>>>>  servo (0)
        _delay_ms(1500);

        init_Timer(Normal_mode, CS_prescal_1024);
    } else if (data == '0') {
        return 0;
    }
    return 1;
}

void Lm_35() {
    int data = 0;
    int volt = 0;
    int temp = 0;
    init_ADC(_CH0, _AVCC, Right_Adjusted, _PRE128);
    Start_Conversion();
    data = ADC_READ_Right();
    volt = (data * 5); //mv 
    temp = (volt / 10);
    if (temp > 28) {
        Motor_Forward(Motor1);
    } else if (temp < 21) {
        Motor_Stop(Motor1);
    }
}

int Delete_user() {

    uart_send(13);
    uart_send_str(y22);
    uart_send(13);
    for (int i = 0; __User[i - 1] != '.'; i++) {

        __User[i] = uart_receive();
        _delay_ms(10);
        LCD_clear_4bit();
    }

    int address = 0;

    char user[4];
    for (int k = 0; k < 10; k++) {
        int f = 0;
        for (int i = 0; i < 4; i++) {
            user [i] = read_EEPROM(address);
            address++;
        }
        for (int j = 0; user[j] != '\0' && f == 0; j++) {
            if (user[j] != __User[j]) {
                f = 1;
            } else {
                f = 0;
            }
        }
        if (f == 0) {
            write_EEPROM(address, 0);
            uart_send(13);
            uart_send_str(y23);
            uart_send(13);
        }
    }
    for (int i = 0; i < 5; i++) {

        __User[i] = 0;
    }
    return 0;



}