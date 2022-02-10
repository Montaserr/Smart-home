#include "Config.h"



char x1[] = "ENTER ur User";
char x2[] = "ENTER ur password";
char x3[] = "Accesed";
char x4[] = "Access Denied";

char x5[] = "incorrect";
char x6[] = "Wellcome ....";
char x7[] = "1>>AC";
char x8[] = "2>>LEDS";
char x9[] = "3>>LOG OUT";

char x10[] = "LED>>1 2 3 4 5 6";

char x11[] = "0 >>> Return Home";

char x12[] = "1>>ON";
char x13[] = "2>>OFF";
char x14[] = "1>>OPEN";
char x15[] = "2>>CLOSE";

char x16[] = "1>>LVL1 2>>LVL1";
char x17[] = "3>>LVL3 4>>OFF";


char __User[10];
char __pass[10];
int __counter = 0;

void app_start_keypad() {

    while (1) {

        LCD_clear_4bit();
        LcdWrite_str_4bit(x1); //ENTER ur User..



        for (int i = 0; __User[i - 1] != '*'; i++) {

            __User[i] = getKey();
            _delay_ms(10);
            LCD_clear_4bit();
            LcdWrite_str_4bit(__User);


        }


        LCD_clear_4bit();
        LcdWrite_str_4bit(x2); //enter ur pass....


        for (int i = 0; __pass[i - 1] != '*'; i++) {

            __pass[i] = getKey();
            _delay_ms(10);
            LCD_clear_4bit();
            LcdWrite_str_4bit(__pass);
        }




        int z = check_user(__User, __pass);

        if (z == 1) {

            LCD_clear_4bit();
            LcdWrite_str_4bit(x3); //Accessed...
            _delay_ms(1500);
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
                LCD_clear_4bit();
                LcdWrite_str_4bit(x4);
                while (1);

            }


            LCD_clear_4bit();
            LcdWrite_str_4bit(x5);
            _delay_ms(500);

            for (int i = 0; i < 5; i++) {

                __User[i] = 0;
            }
            for (int i = 0; i < 5; i++) {

                __pass[i] = 0;
            }







        }




    }

}

char app_home_keypad() {

    char data = 0;

    //Wellcome....
    LCD_clear_4bit();
    LcdWrite_str_4bit(x6);
    _delay_ms(1500);
    //1>>AC...
    LCD_clear_4bit();
    LcdWrite_str_4bit(x7);
    //2>>LEDS...
    LCD_goto_4bit(_ROW0, 6);
    LcdWrite_str_4bit(x8);
    //3>>LOG OUT.....
    LCD_goto_4bit(_ROW1, 0);
    LcdWrite_str_4bit(x9);





    data = getKey();



    return data;


}
// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_options_keypad(char option) {


    if (option == '1') {

        app_Ac_keypad();

        return 0;



    } else if (option == '2') {

        app_Leds_keypad();

        return 0;

    } else if (option == '3') {

        //LOG OUT OPTION....

        return 1;
    }

    return 0;

}

int app_Leds_keypad() {
    SetPinDir(_PB, LED1, OUT);
    SetPinDir(_PB, LED2, OUT);
    SetPinDir(_PB, LED3, OUT);
    SetPinDir(_PB, LED4, OUT);
    SetPinDir(_PC, LED5, OUT);
    char data = 0;

    LCD_clear_4bit();
    LcdWrite_str_4bit(x10);

    LCD_goto_4bit(_ROW1, 0);
    LcdWrite_str_4bit(x11);



    data = getKey();

    if (data == '1') {
        char data1 = 0;

        LCD_clear_4bit();
        LcdWrite_str_4bit(x12);

        LCD_goto_4bit(_ROW0, 10);
        LcdWrite_str_4bit(x13);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x11);


        data1 = getKey();

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
        char data1 = 0;
        LCD_clear_4bit();
        LcdWrite_str_4bit(x12);

        LCD_goto_4bit(_ROW0, 10);
        LcdWrite_str_4bit(x13);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x11);


        data1 = getKey();
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
        char data1 = 0;

        LCD_clear_4bit();
        LcdWrite_str_4bit(x12);

        LCD_goto_4bit(_ROW0, 10);
        LcdWrite_str_4bit(x13);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x11);


        data1 = getKey();

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
        char data1 = 0;
        LCD_clear_4bit();
        LcdWrite_str_4bit(x12);

        LCD_goto_4bit(_ROW0, 10);
        LcdWrite_str_4bit(x13);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x11);


        data1 = getKey();
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
        char data1 = 0;
        LCD_clear_4bit();
        LcdWrite_str_4bit(x12);

        LCD_goto_4bit(_ROW0, 10);
        LcdWrite_str_4bit(x13);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x11);


        data1 = getKey();
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
        //Dimming.....
        SetPinDir(_PD, PD7, OUT);
        init_timer2(_mode_fpwm, pre1024);

        char data1;
        LCD_clear_4bit();
        LcdWrite_str_4bit(x16);

        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x17);
        data1 = getKey();

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

int app_Ac_keypad() {

    char data = 0;
    LCD_clear_4bit();
    LcdWrite_str_4bit(x12);

    LCD_goto_4bit(_ROW0, 10);
    LcdWrite_str_4bit(x13);

    LCD_goto_4bit(_ROW1, 0);
    LcdWrite_str_4bit(x11);

    data = getKey();




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

