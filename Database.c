#include "Config.h"





int check_str_user(unsigned int address, char *Input_username) {
    char user[4];
    for (int k = 0; k < 10 ;k++) {
        int f = 0;
        for (int i = 0; i < 4; i++) {
            user [i] = read_EEPROM(address);
            address++;
        }
        for (int j = 0; user[j] != '\0' && f == 0; j++) {
            if (user[j] != Input_username[j]) {
                f = 1;
            } else {
                f = 0;
            }
        }
        if (f == 0) {
            return address;
        }
    }
    return 0;
}

int check_str_pass(unsigned int address, char *Input_username) {
    char user[4];
    int f = 0;
    for (int i = 0; i < 4; i++) {
        user [i] = read_EEPROM(address);
        address++;
    }
    for (int j = 0; user[j] != '\0' && f == 0; j++) {
        if (user[j] != Input_username[j]) {
            f = 1;
        } else {
            f = 0;
        }
    }
    if (f == 0) {
        return address;
    }
    return 0;
}

int check_user(char *username, char *password) {
    int x = check_str_user(0, username);
    if (x) {
        if (check_str_pass(x + 96, password)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int check_admin(char *username, char *password) {
    int x = check_str_user(50, username);
    if (x) {
        if (check_str_pass(x + 96, password)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
