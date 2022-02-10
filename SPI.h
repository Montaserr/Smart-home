/* 
 * File:   SPI.h
 * Author: MaH MeD
 *
 * Created on October 30, 2021, 2:45 PM
 */

#ifndef SPI_H
#define	SPI_H

#define Master              1
#define Slave               0

#define SPI_Int_Enable      1
#define SPI_Int_Disable     0

#define clk_4               0
#define clk_16              1
#define clk_64              2
#define clk_128             3

#define SPI1x               0
#define SPI2x               1

#define SS                  PB4
#define MOSI                PB5
#define MISO                PB6
#define SCK                 PB7

void init_SPI (int Mode,int SPI_Int_Select);
void SPI_SetClK (int SPI_Clk ,int SPI2x_Select);
void SPI_Send (char Data);
void SPI_Send_str(char * Data);
void SPI_Send_num (int num);
char SPI_Receive ();

#endif	/* SPI_H */

