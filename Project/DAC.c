/*
 * DAC.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "DAC.h"

void Init_DAC(void)
{
	DrvDAC_Open(E_DAC_PVDDA,E_DAC_NVSSA,0); //DAC_Vrefp= VDDA, DAC_Vrefn= VSSA, DAO=0
	DrvDAC_DALH(1); //Set DALH=1b
	DrvDAC_EnableOutput(); //Enable 12-bit resistance ladder DAC output
	DrvDAC_Enable(); //Enable 12-bit resistance ladder DAC function

}

void DACVal(unsigned int uDAC12BIT)
{
	DrvDAC_DABIT(uDAC12BIT);
}
