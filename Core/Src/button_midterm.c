/*
 * button_midterm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#include "button_midterm.h"

static uint16_t buttonPin[3] = {
		RESET_Pin,
		INC_Pin,
		DEC_Pin
};

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button2_long_flag = 0;
int button3_long_flag = 0;

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int timerKeyPressed[3] = {300, 300, 300} ;

int isButton1Pressed()
{
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed()
{
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed()
{
	if(button3_flag == 1)
	{
		button3_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2LongPressed()
{
	if(button2_long_flag == 1)
	{
		button2_long_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3LongPressed()
{
	if(button3_long_flag == 1)
	{
		button3_long_flag = 0;
		return 1;
	}
	return 0;
}

int isAllButtonOff()
{
	if(isButton1Pressed() == 1) return 0;
	if(isButton2Pressed() == 1) return 0;
	if(isButton3Pressed() == 1) return 0;
	if(isButton2LongPressed() == 1) return 0;
	if(isButton3LongPressed() == 1) return 0;
	return 1;
}
void subKeyProcess(int index)
{
	switch(index)
	{
	case 0:
		button1_flag = 1;
		break;
	case 1:
		button2_flag = 1;
		break;
	case 2:
		button3_flag = 1;
		break;
	default:
		break;
	}
}

void longKeyProcess(int index)
{
	switch(index)
	{
	case 1:
		button2_long_flag = 1;
		break;
	case 2:
		button3_long_flag = 1;
		break;
	default:
		break;
	}
}

void getKeyInput()
{
	for(int i = 0; i < 3; i++)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOC, buttonPin[i]);

		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i]))
		{
			if(KeyReg3[i] != KeyReg2[i])
			{
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE)
				{
					subKeyProcess(i);
					timerKeyPressed[i] = 300;
				}
			}
			else
			{
				timerKeyPressed[i]--;
				if(timerKeyPressed[i] == 0)
				{
					if(KeyReg2[i] == PRESSED_STATE)
					{
						longKeyProcess(i);
					}
					timerKeyPressed[i] = 100;
				}
			}
		}
	}
}
