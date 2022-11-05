/*
 * button_midterm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#ifndef INC_BUTTON_MIDTERM_H_
#define INC_BUTTON_MIDTERM_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

static uint16_t buttonPin[3];

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
int isButton2LongPressed();
int isButton3LongPressed();
int isAllButtonOff();

void getKeyInput();

#endif /* INC_BUTTON_MIDTERM_H_ */
