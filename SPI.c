#include "Config.h"

void init_SPI(int MOde, int SPI_Int_Select) {
    //SPCR = 0;
    SPCR |= ((1 << SPE) | (MOde << MSTR) | (SPI_Int_Select << SPIE));

    switch (MOde) {
        case Master:
            SetPinDir(_PB, MOSI, OUT);
            SetPinDir(_PB, SS, OUT);
            SetPinDir(_PB, SCK, OUT);
            
            break;
        case Slave:
            SetPinDir(_PB, MISO, OUT);
            
            break;

    }



}

void SPI_SetClK(int SPI_Clk, int SPI2x_Select) {

    //SPCR &= 0xFC;
    SPCR |= SPI_Clk;
    SPSR |= SPI2x_Select;

}

void SPI_Send(char Data) {
    SPDR = Data;
    while (!(SPSR & (1 << SPIF)));
}

void SPI_Send_str(char * Data) {
    for (int i = 0; Data[i] != '\0'; i++) {
        SPI_Send(Data[i]);
    }
}
void SPI_Send_num(int num){
    
    char buffer[11];
    itoa(num,buffer,10);
    SPI_Send_str(buffer);
    
}
char SPI_Receive(){
    
    while (!(SPSR & (1 << SPIF)));
    
    return SPDR;
}