/*
 * timer_midterm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#ifndef INC_TIMER_MIDTERM_H_
#define INC_TIMER_MIDTERM_H_

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void runTimer();

#endif /* INC_TIMER_MIDTERM_H_ */
