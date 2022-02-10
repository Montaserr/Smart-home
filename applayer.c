
#include "Config.h"

char x[] = "ENTER ur User";
char xx[] = "ENTER ur password";
char xxx[] = "Accesed";
char xxxx[] = "Access Denied";
char Y1[] = "user or pass incorrect";
char y2[] = "Wellcome ....";
char y3[] = "1>>AC";
char y4[] = "2>>LEDS";
char y5[] = "3>>DOOR";
char y5_[]= "3>>LOG OUT";
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



char __User[20];
char __pass[20];
int __counter;

void app_start_uart() {
    while (1) {
        uart_send_str(x);
        uart_send(13);
        LCD_clear_4bit();

        LcdWrite_str_4bit(x);

        for (int i = 0; __User[i - 1] != '.'; i++) {

            __User[i] = uart_receive();
            _delay_ms(10);
            LCD_clear_4bit();




        }
        uart_send(13);

        uart_send_str(xx);
        uart_send(13);
        LCD_clear_4bit();

        LcdWrite_str_4bit(xx);


        for (int i = 0; __pass[i - 1] != '.'; i++) {

            __pass[i] = uart_receive();
            _delay_ms(10);
        }
        uart_send(13);



        int z = check_user(__User, __pass);

        if (z == 1) {
            uart_send_str(xxx);
            uart_send(13);
            LCD_clear_4bit();

            LcdWrite_str_4bit(xxx);

            break;



        } else {

            __counter++;


            if (__counter == 3) {
                Set_Buzzer(ON);
                LCD_clear_4bit();

                LcdWrite_str_4bit(xxxx);
                while (1);

            }

            uart_send_str(Y1);
            uart_send(13);
            LCD_clear_4bit();

            LcdWrite_str_4bit(Y1);





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

    data = uart_receive();



    return data;


}
// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_options_uart(char option) {


    if (option == '1') {

        int data;
        data = app_Ac();
        if (data == 0) {
            return 0;
        } else {
            return 1;
        }


    } else if (option == '2') {
        int data;
        data = app_Leds();
        if (data == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (option == '3') {
        int data;
        data = app_Door();
        if (data == 0) {
            return 0;
        } else {
            return 1;
        }


    }

    return 1;

}


// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_Leds() {
    SetPinDir(_PC, LED1, OUT);
    SetPinDir(_PC, LED2, OUT);
    SetPinDir(_PC, LED3, OUT);
    SetPinDir(_PC, LED4, OUT);
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
                SetPinData(_PC, LED1, ON);
                break;
            case '2':
                SetPinData(_PC, LED1, OFF);
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
                SetPinData(_PC, LED2, ON);
                break;
            case '2':
                SetPinData(_PC, LED2, OFF);
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
                SetPinData(_PC, LED3, ON);
                break;
            case '2':
                SetPinData(_PC, LED3, OFF);
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
                SetPinData(_PC, LED4, ON);
                break;
            case '2':
                SetPinData(_PC, LED4, OFF);
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

    } else if (data == '0') {

        return 0;



    }

    return 1;




}

int app_Ac() {

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

        init_Timer(CTC_mode, CS_prescal_1024);
        Set_OC(255);
        Timer_Int_Enable(INT_OC);

    } else if (data == '2') {

        Motor_Stop(Motor1);

        init_Timer(CTC_mode, CS_Timer_off);



    } else if (data == '0') {

        return 0;
    }

    return 1;


}

int app_Door() {

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

        init_Timer(CTC_mode, CS_prescal_1024);


    } else if (data == '2') {

        SetPinDir(_PB, PB3, OUT);

        init_Timer(FPWM_mode, CS_prescal_1024);



        Compare_Match_Mode(COM_Clear_FPWM);

        Set_OC(22); //>>>>>>>>  servo (0)

        _delay_ms(1500);

        init_Timer(CTC_mode, CS_prescal_1024);



    } else if (data == '0') {

        return 0;
    }

    return 1;

}

void Lm_35() {

    int data = 0;
    int volt = 0;
    int temp = 0;

    init_ADC(_CH1, _AVCC, Right_Adjusted, _PRE128);


    Start_Conversion();
    data = ADC_READ_Right();
    volt = (data * 5); //mv 
    temp = (volt / 10);


    if (temp > 28) {
        SetPinData(_PA, PA0, ON);
        Motor_Forward(Motor1);

    } else if (temp < 21) {
        SetPinData(_PA, PA0, OFF);
        Motor_Stop(Motor1);

    }





}

void app_start_keypad() {

    while (1) {

        LCD_clear_4bit();
        LcdWrite_str_4bit(x); //ENTER ur User..



        for (int i = 0; __User[i - 1] != '*'; i++) {

            __User[i] = getKey();
            _delay_ms(10);
            LCD_clear_4bit();
            LcdWrite_str_4bit(__User);


        }


        LCD_clear_4bit();
        LcdWrite_str_4bit(xx); //enter ur pass....


        for (int i = 0; __pass[i - 1] != '*'; i++) {

            __pass[i] = getKey();
            _delay_ms(10);
            LCD_clear_4bit();
            LcdWrite_str_4bit(__pass);
        }




        int z = check_user(__User, __pass);

        if (z == 1) {

            LCD_clear_4bit();
            LcdWrite_str_4bit(xxx); //Accessed...

            break;



        } else {

            __counter++;


            if (__counter == 3) {
                Set_Buzzer(ON);
                LCD_clear_4bit();
                LcdWrite_str_4bit(xxxx);
                while (1);

            }


            LCD_clear_4bit();
            LcdWrite_str_4bit(Y1);
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

    char data;

    //Wellcome....
    LCD_clear_4bit();
    LcdWrite_str_4bit(y2);
    _delay_ms(1500);
    //1>>AC...
    LCD_clear_4bit();
    LcdWrite_str_4bit(y3);
    //2>>LEDS...
    LCD_goto_4bit(_ROW0,6);
    LcdWrite_str_4bit(y4);
    //3>>LOG OUT.....
    LCD_goto_4bit(_ROW1,0);
    LcdWrite_str_4bit(y5_);
    
    

    

    data = getKey();



    return data;


}
// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_options_keypad(char option) {


    if (option == '1') {

        int data;
        data = app_Ac();
        if (data == 0) 
            return 0;
        


    } else if (option == '2') {
        int data;
        data = app_Leds();
        if (data == 0) 
            return 0;
        
    } else if (option == '3') {
        
        //LOG OUT OPTION....
        
        return 1;
    }

    return 0;

}
