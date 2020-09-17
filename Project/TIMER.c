/*
 * TIMER.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "TIMER.h"

void Init_TIMEB(void)
{
	DrvTMBC_Clk_Source(1,2);//TimerB clock source : TBCLK = HS_CK/pre-scale
							//Clock source
							/*0:closed
 	 	 	 	 	 	 	  1:HS_CK
 	 	 	 	 	 	 	  2:HS_CB
 	 	 	 	 	 	 	  3:LS_CK*/
							//Choice clock source pre-scale
							/*0: clock divider.กา1
							  1: clock divider.กา2
						      2: clock divider.กา4
						      3: clock divider.กา8*/

	DrvTMB_Open(E_TMB_MODE0,E_TMB_NORMAL,0x7D);	//TBC0 : 16bit (Timer B overflow value)
													//500Hz: 0x82A ,this value is regulated
													// T = TBC0/TBCLK

	DrvTIMER_ClearIntFlag(E_TMB); //Clear Timer B interrupt flag
	DrvTIMER_EnableInt(E_TMB); //Timer B interrupt enable
}
