#include "Config.h"

void init_uart(int BaudRate, int RX_EN, int TX_EN) {
    UCSRB |= ((RX_EN << RXEN) | (TX_EN << TXEN));

    int _ubrr = (F_CPU / 16.0 / BaudRate) - 1;

    UBRRL = _ubrr;
    if (_ubrr > 255) {
        UBRRH = (_ubrr >> 8);
    }




}

void uart_send(char data) {

    while (!(UCSRA & (1 << UDRE)));

    UDR = data;

}

void uart_send_str(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {

        uart_send(str[i]);

    }
}

void uart_send_Num(int num) {
    char buffer[11];
    itoa(num, buffer, 10);
    uart_send_str(buffer);
}

char uart_receive() {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

