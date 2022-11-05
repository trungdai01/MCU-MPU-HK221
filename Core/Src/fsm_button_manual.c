/*
 * fsm_button_manual.c
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#include "fsm_button_manual.h"

void modifyButton()
{
	if(isButton1Pressed() == 1)
	{
		counter = 0;
		reset7SEG();
		setTimer1(1000);
	}

	if(isButton2Pressed() == 1 || isButton2LongPressed() == 1)
	{
		counter++;
		if(counter > 9)
		{
			counter = 0;
		}
		reset7SEG();
		setTimer1(1000);
	}

	if(isButton3Pressed() == 1 || isButton3LongPressed() == 1)
	{
		counter--;
		if(counter < 0)
		{
			counter = 9;
		}
		reset7SEG();
		setTimer1(1000);
	}
}
void fsm_simple_buttons_run()
{
	modifyButton();
	display7SEG(counter);
}
