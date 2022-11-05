/*
 * fsm_timeout.c
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#include "fsm_timeout.h"

void fsm_timeout()
{
	if(timer1_flag == 1 && isAllButtonOff() == 1)
	{
		counter--;
		if(counter < 0)
		{
			counter = 0;
		}
		reset7SEG();
		display7SEG(counter);
		setTimer1(100);
	}
	if(isButton1Pressed() == 1)
	{
		counter = 0;
		reset7SEG();
		display7SEG(counter);
		setTimer1(1000);
	}
	if (isButton2Pressed() == 1)
	{
		counter++;
		if(counter > 9)
		{
			counter = 0;
		}
		reset7SEG();
		display7SEG(counter);
		setTimer1(1000);
	}
	if (isButton3Pressed() == 1)
	{
		counter--;
		if(counter < 0)
		{
			counter = 9;
		}
		reset7SEG();
		display7SEG(counter);
		setTimer1(1000);
	}
}
