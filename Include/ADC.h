/*
 * ADC.h
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "SpecialMacro.h"
#include "DrvADC.h"

#ifndef ADC_H_
#define ADC_H_


/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void Init_ADC(void);
void Enable_ADC(unsigned int uINP,unsigned int uINN,unsigned int uADCOSR);
void Disable_ADC(void);
unsigned int GetADCVal(unsigned int uINP,unsigned int uINN,unsigned int uADCOSR);

#endif /* ADC_H_ */
