#include "Config.h"

void init_keypad() {
    KEYPAD_DIR |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);//OUTPUT
    KEYPAD_DIR &= ~((1 << ROW0) | (1 << ROW1) | (1 << ROW2) | (1 << ROW3));//INPUT
    // Set Value 
    KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
}

char getKey() {

    while (1) {
        if (IsPressed(_KEPAD, ROW0)) {
            // 1,2,3
            for (int i = 0; i < 3;) {
                KEYPAD_PORT &= 0xF8;//OUTPUT
                _delay_ms(20);
                KEYPAD_PORT |= (1 << i);
                _delay_ms(20);
                if (IsPressed(_KEPAD, ROW0)) {

                    KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                    _delay_ms(200);
                    return '0' + (3 - i);
                }
                KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                _delay_ms(20);
                i++;
            }
        }
        if (IsPressed(_KEPAD, ROW1)) {
            // 4,5,6
            for (int i = 0; i < 3;) {
                KEYPAD_PORT &= 0xF8;
                _delay_ms(20);
                KEYPAD_PORT |= (1 << i);
                _delay_ms(20);
                if (IsPressed(_KEPAD, ROW1)) {

                    KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                    _delay_ms(200);
                    return '0' + (6 - i);
                }
                KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                _delay_ms(20);
                i++;
            }
        }
        if (IsPressed(_KEPAD, ROW2)) {
            // 7,8,9
            for (int i = 0; i < 3;) {
                KEYPAD_PORT &= 0xF8;
                _delay_ms(20);
                KEYPAD_PORT |= (1 << i);
                _delay_ms(20);
                if (IsPressed(_KEPAD, ROW2)) {

                    KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                    _delay_ms(200);
                    return '0' + (9 - i);
                }
                KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                _delay_ms(20);
                i++;
            }
        }
        if (IsPressed(_KEPAD, ROW3)) {
            // *,0,#
            for (int i = 0; i < 3;) {
                KEYPAD_PORT &= 0xF8;
                _delay_ms(20);
                KEYPAD_PORT |= (1 << i);
                _delay_ms(20);
                if (IsPressed(_KEPAD, ROW3)) {

                    KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                    _delay_ms(200);
                    return i == 0 ? '#' : i == 1 ? '0' : '*';
                }
                KEYPAD_PORT |= (1 << COLUMN0) | (1 << COLUMN1) | (1 << COLUMN2);
                _delay_ms(20);
                i++;
            }
        }
    }
}
