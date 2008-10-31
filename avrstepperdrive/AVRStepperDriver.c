/*
 * AVRStepperDriver.c
 *
 *  Created on: Oct 28, 2008
 *      Author: Hue Thai
 *      AVRStepperDriver
 */


#include <avr/io.h>
#include "AVRLib\uart.h"
#include "AVRLib\cmdline.h"
#include "AVRLib\vt100.h"
#include "AVRLib\a2d.h"
#include "AVRLib\rprintf.h"



/* Globals */
u08 Run;
u08 FullStepArray[4] = { 1,2,4,8};


int main(void)
{
	uartInit();
	uartSetBaudRate(115200);
	rprintfInit(uartSendByte);

	Run = TRUE;

	while(Run)
	{

	}

	return 0;
}
