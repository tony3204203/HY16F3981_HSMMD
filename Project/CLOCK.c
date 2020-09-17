/*
 * CLOCK.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "CLOCK.h"

void Init_INTCLK(void)
{
	DrvCLOCK_EnableHighOSC(E_INTERNAL, 10);
	DrvCLOCK_SelectIHOSC(1); //³]¸m¤º³¡¾_Àú (1) = 4MHz

	//DrvCLOCK_EnableLowOSC(E_INTERNAL,50);

	DrvCLOCK_SelectMCUClock(0, 0); //HS_CK,0
	DrvCLOCK_CalibrateHAO(1);



}

void Init_EXTCLK(void)
{
	DrvCLOCK_EnableHighOSC(E_EXTERNAL, 30); // EXTERNAL OSC stable time is 30ms , user guide p.26
	DrvCLOCK_SelectMCUClock(0, 0); // System clock source = HS_CK = HSXT/2
								   // HS_CK = 4M is good for ADC's work rate(1M) , user guide p.34
								   // Choice clock source
									/* 0:HS_CK
	   	   	   	   	   	   	   	   	   1:LS_CK*/
								   // Choice clock source pre-scale
	                                /* 0:clock divider.¡Ò1
	                                   1:clock divider.¡Ò2*/
}

void Delay(unsigned int num)
{
  for(;num>0;num--)
    asm("NOP");
}
