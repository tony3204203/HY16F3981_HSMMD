/*
 * ADC.c
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "ADC.h"
#include "POWER.h"
#include "CLOCK.h"
void Init_ADC(void)
{
	DrvADC_InputSwitch(OPEN);    //ADC signal input (positive and negative) short(VISHR) control.
	DrvADC_RefInputShort(OPEN);  //Set the ADC reference input (positive and negative) short(VRSHR) control.

	DrvADC_ADGain(0);    		 //ADC gain=1
	DrvADC_DCoffset(0);          //DC offset input voltage selection (VREF=REFP-REFN)
	DrvADC_RefVoltage(0,0);  	 //Set the ADC reference voltage. Vref = VRPS-VRNS
	DrvADC_FullRefRange(1);      //Set the ADC full reference range select.
	                             //0: Full reference range input
	                             //1: 1/2 reference range input

	//Set ADC Clock
	DrvADC_ClkEnable(2);       	 //Setting ADC CLOCK ADCK = HS_CK/4  (HYCON ADC最佳工作時脈為1MHz)
								 //2: ADCK=HS_CK/4
				  	  	  	     //3: ADCK=HS_CK/8
}

void Enable_ADC(unsigned int uINP,unsigned int uINN,unsigned int uADCOSR)
{
	//Set ADC input pin
	DrvADC_PInputChannel(uINP);
	DrvADC_NInputChannel(uINN);

	DrvADC_OSR(uADCOSR); 	//ADC輸出率  OSR = ADCK/X
							/*
	 	 	 	 	 	 	 	 0 : ÷32768，資料輸出率是10sps
	 	 	 	 	 	 	 	 1 : ÷16384，資料輸出率是20sps
	 	 	 	 	 	 	 	 2 : ÷8192，資料輸出率是40sps
	 	 	 	 	 	 	 	 3 : ÷4096，資料輸出率是80sps
	 	 	 	 	 	 	 	 4 : ÷2048，資料輸出率是160sps
	 	 	 	 	 	 	 	 5 : ÷1024，資料輸出率是320sps
	 	 	 	 	 	 	 	 6 : ÷512，資料輸出率是640sps
	 	 	 	 	 	 	 	 7 : ÷256，資料輸出率是1280sps
	 	 	 	 	 	 	 	 8 : ÷128 ，資料輸出率是2560sps
	 	 	 	 	 	 	 	 9 : ÷64，資料輸出率是5120sps
	 	 	 	 	 	 	 	 10 : ÷32，資料輸出率是10240sps
							 */

	DrvADC_Enable();
	DrvADC_DisableInt();//Disable ADC interrupt

	//ComFilter
	DrvADC_CombFilter(ENABLE);
	DrvADC_CombFilter(DISABLE);
	DrvADC_CombFilter(ENABLE);
}

void Disable_ADC(void)
{
	DrvADC_Disable();
}

unsigned int GetADCVal(unsigned int uINP,unsigned int uINN,unsigned int uADCOSR)
{
	unsigned int  ADCvalue;

	Enable_ADC(uINP, uINN, uADCOSR);

	while(!DrvADC_ReadIntFlag());

	ADCvalue = DrvADC_GetConversionData() >> 8 ;

	Disable_ADC();

	return ADCvalue;
}
