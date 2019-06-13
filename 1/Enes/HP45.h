#ifndef __HP45_H
#define __HP45_H

#include "stm32f4xx.h"
#include "pin_config.h"

#define TOTAL_DATA 									22

#define MATRIX_R_X 									15000
#define MATRIX_R_Y 									15000

#define HP45_ADDRESS_GPIO						GPIOD
#define HP45_ADDRESS_CLOCK 					GPIO_Pin_13
#define HP45_ADDRESS_RESET					GPIO_Pin_15
#define HP45_ADDRESS_RCC_Periph 		RCC_AHB1Periph_GPIOD

#define HP45_PRIMITIVE_GPIO 				GPIOB
#define HP45_PRIMITIVE_LINE 				GPIO_Pin_All
#define HP45_PRIMITIVE_RCC_Periph 	RCC_AHB1Periph_GPIOB

void InitHp45(void);
void fire14Nozzle(uint16_t data14);
void fire300Nozzle(uint16_t *data300);

#endif
