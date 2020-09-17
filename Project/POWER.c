/*
 * POWER.c
 *
 *  Created on: Jun 19, 2020
 *      Author: tony3
 */

#include "POWER.h"
#include "CLOCK.h"

void Init_PMU(void)
{
	DrvPMU_VDDA_LDO_Ctrl(E_LDO);   //set VDDA source
	DrvPMU_VDDA_Voltage(E_VDDA3_3); //VDDA=3.3V
	DrvPMU_BandgapEnable();
	DrvPMU_REFO_Enable();
	Delay(0x1000);
	DrvPMU_AnalogGround(ENABLE); //ADC analog ground source selection.
}
