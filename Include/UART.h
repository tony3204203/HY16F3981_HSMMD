/*
 * UART.h
 *
 *  Created on: Jun 17, 2020
 *      Author: tony3
 */

#include "DrvUART.h"
#include "DrvGPIO.h"
#include "my define.h"

#ifndef UART_H_
#define UART_H_

/*----------------------------------------------------------------------------*/
/* DEFINITIONS UART pin                                                       */
/*----------------------------------------------------------------------------*/
#define  UART_PORT E_PT2
#define  UART_TXD  BIT0
#define  UART_RXD  BIT1

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void Init_UART(void);
void UART_SendByte(unsigned int sendByte);
void UART_Send24b(unsigned int uartBuffer, unsigned int dataNum, unsigned int sendData[]);

#endif
