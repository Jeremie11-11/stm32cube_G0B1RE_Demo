/*
 * i_gpio.c
 *
 *  Created on: 1 mars 2025
 *      Author: Jeremie Frueh
 */

#include "i_gpio.h"
#include "i_timer.h"


#define PERIOD_TABLE_SIZE 2
const uint32_t PeriodTable[PERIOD_TABLE_SIZE] = {1000, 500};
static uint32_t push_button_state = 0;


void gpio_init(void)
{
	tim_set_blinking_period(PeriodTable[push_button_state]);
}

void gpio_update_push_button(void)
{
	// Update push button state
	push_button_state++;
	if(push_button_state >= PERIOD_TABLE_SIZE)
		push_button_state = 0;

	// Set blinking period
	tim_set_blinking_period(PeriodTable[push_button_state]);
}

