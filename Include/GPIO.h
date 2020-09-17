/*
 * GPIO.h
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "DrvGPIO.h"
#include "my define.h"
#include "HY16F3981.h"
#include "DAC.h"

#ifndef GPIO_H_
#define GPIO_H_

/*----------------------------------------------------------------------------*/
/* DEFINITIONS UART pin                                                       */
/*----------------------------------------------------------------------------*/

/* Test work sequence */
#define Work_sequence_PORT E_PT8
#define Work_sequence_UART_BIT BIT5  //0x20
#define UART_Pin 5
#define Work_sequence_ADC_BIT BIT6	//0x40
#define ADC_Pin 6
#define Work_sequence_Timer_BIT BIT7 //0x80
#define Timer_Pin 7

/* LED Status */
#define LED_660_ON 0
#define LED_940_ON 1
#define LED_OFF 2

/* H Bridge control */
#define HB_PORT E_PT6
#define HB_ctrl_R_BIT BIT2 //0x04
#define HB_ctrl_R_Pin 2
#define HB_ctrl_L_BIT BIT3 //0x08
#define HB_ctrl_L_Pin 3

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void Init_GPIO(void);
void HB_Ctrl(unsigned int LED_Stat,unsigned int uDABIT);

#endif /* GPIO_H_ */
