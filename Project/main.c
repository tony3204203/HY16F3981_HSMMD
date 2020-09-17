/**********************************************************************
 *HY16F3981
 * main.c
 * Created on:2019/09/18

 * --------------------------------------------------------------------
 * Program Description:
 * --------------------
 *Detect Red,IR,close light and left,right,mouth air flow
 *Use TimerB to get ADC value ,and use UART to transmission six data for computer
 **********************************************************************/
/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include "main.h"

/*----------------------------------------------------------------------------*/
/* STRUCTURES                                                                 */
/*----------------------------------------------------------------------------*/
volatile typedef union _MCUSTATUS
{
  char  _byte;
  struct
  {
    unsigned b_ADCdone:1;
    unsigned b_TMAdone:1;
    unsigned b_TMBdone:1;
    unsigned b_TMC0done:1;
    unsigned b_TMC1done:1;
    unsigned b_RTCdone:1;
    unsigned b_UART_TxDone:1;
    unsigned b_UART_RxDone:1;
  };
} MCUSTATUS;

/*----------------------------------------------------------------------------*/
/* Global CONSTANTS                                                           */
/*----------------------------------------------------------------------------*/
MCUSTATUS  MCUSTATUSbits;

unsigned int bioData[6];

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/
int main(void)
{
	Delay(100000);
	Init_INTCLK();
	Delay(10000);
	Init_UART();
	Delay(10000);
	Init_PMU();
	Delay(10000);
	Init_DAC();
	Delay(100000);
	Init_ADC();
	Delay(10000);
	Init_GPIO();
	Delay(10000);

	SYS_EnableGIE(4,0x1FF); //Enable GIE(Global Interrupt)
	MCUSTATUSbits._byte = 0;

	Init_TIMEB();

	while(1);

}

/*---------------------------------------------------------------------------*/
/* Hardware Communication Interrupt                                          */
/* UART/SPI/I2C Interrupt Service Routines                                   */
/*---------------------------------------------------------------------------*/
void HW0_ISR(void)
{

}

/*---------------------------------------------------------------------------*/
/* WDT & RTC & Timer A/B/C Interrupt Service Routines                        */
/*---------------------------------------------------------------------------*/
void HW1_ISR(void)
{
	if(DrvTIMER_GetIntFlag(E_TMB)){

		HB_Ctrl(LED_OFF,0);
		bioData[0] = GetADCVal(ADC_Input_AIO2, ADC_Input_AIO8, 8);
		bioData[1] = GetADCVal(ADC_Input_AIO4, ADC_Input_AIO8, 8);
		HB_Ctrl(LED_940_ON,2000);
		bioData[2] = GetADCVal(ADC_Input_AIO2, ADC_Input_AIO8, 8);
		bioData[3] = GetADCVal(ADC_Input_AIO5, ADC_Input_AIO8, 8);
		HB_Ctrl(LED_660_ON,2000);
		bioData[4] = GetADCVal(ADC_Input_AIO2, ADC_Input_AIO8, 8);
		bioData[5] = GetADCVal(ADC_Input_AIO6, ADC_Input_AIO8, 8);
		UART_Send24b(0xC3, 6, bioData);

		DrvTIMER_ClearIntFlag(E_TMB); // Clear TMB interrupt flag

	}
}

/*----------------------------------------------------------------------------*/
/* HW2 ADC Interrupt Subroutines                                              */
/*----------------------------------------------------------------------------*/
void HW2_ISR(void)
{

}

/*---------------------------------------------------------------------------*/
/* CMP/OPA Interrupt Service Routines                                        */
/*---------------------------------------------------------------------------*/
void HW3_ISR(void)
{

}

/*---------------------------------------------------------------------------*/
/* PT1 Interrupt Service Routines                                            */
/*---------------------------------------------------------------------------*/
void HW4_ISR(void)
{

}

/*---------------------------------------------------------------------------*/
/* PT2 Interrupt Service Routines                                            */
/*---------------------------------------------------------------------------*/
void HW5_ISR(void)
{

}

/*---------------------------------------------------------------------------*/
/* End Of File                                                               */
/*---------------------------------------------------------------------------*/

