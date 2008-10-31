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
#include "AVRLib\timer.h"

#include "AVRStepperDriver.h"



/* Globals */
u08 Run;
u08 FullStepArray[4] = { 1,2,4,8};

void CommandLine(void);

int main(void)
{
	uartInit();
	uartSetBaudRate(115200);
	rprintfInit(uartSendByte);

	a2dInit();
	timerInit();
	vt100Init();




	return 0;
}

void CommandLine(void)
{
	u08 c;
	/* Variable to Run or stop program */
	Run = TRUE;

	/* Clears the screen and sets the cursor under the Title */
	vt100ClearScreen();
	vt100SetCursorPos(1,0);

	rprintfProgStrM("\r\n\t\t\tStepper Motor Driver - Serial Console\r\n");

	cmdlineInit();
	cmdlineSetOutputFunc(uartSendByte);

	cmdlineAddCommand("quit", quitCommandLine);
	cmdlineAddCommand("help", helpDisplay);
	cmdlineAddCommand("step", runMotor);

	cmdlineInputFunc('\r');

	while(Run)
	{
		while( uartReceiveByte(&c) )
			cmdlineInputFunc(c);

		cmdlineMainLoop();

	}

	rprintfCRLF();
	rprintf("Program halted.");


}

void quitCommandLine(void)
{

}

void helpDisplay(void)
{

}
void runMotor(void)
{

}

