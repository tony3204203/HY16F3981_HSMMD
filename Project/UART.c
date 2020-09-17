/*
 * UART.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "UART.h"

void Init_UART(void)
{
	DrvUART_ClkEnable(1,0);//Choose the internal osc as clock source
	//DrvUART_ClkEnable(0,0);//Choose the external osc as clock source

    DrvGPIO_Open(UART_PORT,UART_TXD,E_IO_OUTPUT);
    DrvGPIO_Open(UART_PORT,UART_RXD,E_IO_INPUT);
    DrvGPIO_Open(UART_PORT,UART_RXD|UART_TXD,E_IO_PullHigh);

    DrvGPIO_ClkGenerator(E_HS_CK,1);

    DrvUART_Open(4147,B115200,DRVUART_PARITY_NONE,DRVUART_DATABITS_8,1,2);//for OSC = 4M Hz
    //DrvUART_Open(8294,B115200,DRVUART_PARITY_NONE,DRVUART_DATABITS_8,1,2); //for OSC = 8M Hz

    DrvUART_Disable_AutoBaudrate();
    DrvUART_Close();
    DrvUART_Enable();
}

void UART_SendByte(unsigned int sendByte)
{
	DrvUART_Write(sendByte);
	while(DrvUART_TRStatus(3));
}

void UART_Send24b(unsigned int uartBuffer, unsigned int dataNum, unsigned int sendData[])
{
	unsigned int firstByte, secondByte, thirdByte, fourthByte;

	UART_SendByte(uartBuffer);

	int dataCnt;

	for(dataCnt = 0; dataCnt < dataNum; dataCnt++){

		firstByte = ((sendData[dataCnt] & 0x3F) | 0x80);
		secondByte = ((sendData[dataCnt] >> 6) & 0x3F) | 0x80;
		thirdByte = ((sendData[dataCnt] >> 12) & 0x3F) | 0x80;
		fourthByte = ((sendData[dataCnt] >> 18) & 0x3F) | 0x80;

		UART_SendByte(firstByte);
		UART_SendByte(secondByte);
		UART_SendByte(thirdByte);
		UART_SendByte(fourthByte);
	}

}
