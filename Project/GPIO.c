/*
 * GPIO.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "GPIO.h"

void Init_GPIO(void)
{
	DrvGPIO_LCDIOOpen(Work_sequence_PORT,Work_sequence_Timer_BIT,E_IO_OUTPUT);  //PT8.7 : For detect Timer rate
	DrvGPIO_LCDIOOpen(Work_sequence_PORT,Work_sequence_ADC_BIT,E_IO_OUTPUT);  //PT8.6 : For detect ADC rate
	DrvGPIO_LCDIOOpen(Work_sequence_PORT,Work_sequence_UART_BIT,E_IO_OUTPUT);  //PT8.5 : For detect UART rate
	DrvGPIO_LCDIOOpen(HB_PORT,HB_ctrl_L_BIT,E_IO_OUTPUT);  //PT6.3 : For control H-bridge circuit
	DrvGPIO_LCDIOOpen(HB_PORT,HB_ctrl_R_BIT,E_IO_OUTPUT);	//PT6.2 : For control H-bridge circuit
}

void HB_Ctrl(unsigned int LED_Stat,unsigned int uDAC12BIT)
{
	DACVal(uDAC12BIT);
	switch(LED_Stat){
		case LED_660_ON:
			DrvGPIO_LCDIOSetBit(HB_PORT,HB_ctrl_R_Pin);
			DrvGPIO_LCDIOClrBit(HB_PORT,HB_ctrl_L_Pin);
			break;

		case LED_940_ON:
			DrvGPIO_LCDIOSetBit(HB_PORT,HB_ctrl_L_Pin);
			DrvGPIO_LCDIOClrBit(HB_PORT,HB_ctrl_R_Pin);
			break;

		case LED_OFF:
			DrvGPIO_LCDIOSetBit(HB_PORT,HB_ctrl_R_Pin);
			DrvGPIO_LCDIOSetBit(HB_PORT,HB_ctrl_L_Pin);
			break;
	}


}
