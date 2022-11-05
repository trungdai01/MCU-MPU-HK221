/*
 * display7SEG.c
 *
 *  Created on: Nov 5, 2022
 *      Author: quoct
 */

#include "display7SEG.h"


void reset7SEG()
{
	HAL_GPIO_WritePin(GPIOB, LED7_a_Pin|LED7_b_Pin|LED7_c_Pin|LED7_d_Pin
	                          |LED7_e_Pin|LED7_f_Pin|LED7_g_Pin, RESET);
}

void display7SEG(int num)
{
	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED7_g_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_g_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED7_c_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_f_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_f_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED7_b_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED7_b_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7_g_Pin, SET);
		break;
	case 8:
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, LED7_e_Pin, SET);
		break;
	default:
		break;
	}
}

