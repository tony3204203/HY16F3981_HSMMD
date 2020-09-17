/*
 * SystemClock.h
 *
 *  Created on: Jun 18, 2020
 *      Author: tony3
 */

#include "DrvCLOCK.h"

#ifndef SYSTEMCLOCK_H_
#define SYSTEMCLOCK_H_

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void Init_INTCLK(void);
void Init_EXTCLK(void);
void Delay(unsigned int num);

#endif /* SYSTEMCLOCK_H_ */
