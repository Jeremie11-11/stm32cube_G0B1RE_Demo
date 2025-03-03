/*
 * i_dma.c
 *
 *  Created on: Mar 3, 2025
 *      Author: Jeremie Frueh
 */


#include <i_dma.h>


extern DMA_HandleTypeDef hdma_dma_generator0;

#define DMA_TABLE_SIZE 2
// Counter clock = 16MHz /(Prescaler+1)
static uint32_t PrescalerTim2Table[DMA_TABLE_SIZE] = {1599, 15999};

void dma_init(void)
{

	// ---------- DMA1 ----------
	// Triggered on EXT13 (Blue push button)
	// Memory to Peripheral (Updating TIM2 prescaler value to adjust blinking frequency)

	HAL_DMAEx_EnableMuxRequestGenerator(&hdma_dma_generator0);

	HAL_DMA_Start(&hdma_dma_generator0, (uint32_t)PrescalerTim2Table, (uint32_t)&(TIM2->PSC), DMA_TABLE_SIZE);

}
