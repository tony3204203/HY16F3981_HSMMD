/*----------------------------------------------------------------------------*/
/* Display.h                                                                  */
/*----------------------------------------------------------------------------*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "DrvLCD.h"

void DisplayInit(void);
void ClearLCDframe(void);
void DisplayHYcon(void);
void DisplayPASS(unsigned char LcdBuffer);
void LCD_DATA_DISPLAY(unsigned int LcdBuffer);
void DisplayTest(void);
void RAM2LCD(unsigned char *Buffer_Adr, unsigned char length);

#endif /* DISPLAY_H_ */
