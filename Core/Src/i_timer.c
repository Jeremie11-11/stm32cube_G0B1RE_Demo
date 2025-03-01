/*
 * i_timer.c
 *
 *  Created on: 1 mars 2025
 *      Author: Jeremie Frueh
 */

#include "i_timer.h"


extern TIM_HandleTypeDef htim2;


void tim_init(void)
{
	HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_1);
}

void tim_set_blinking_period(uint32_t period_ms)
{
	TIM2->ARR = period_ms;
	TIM2->CCR1 = period_ms/2;
}

