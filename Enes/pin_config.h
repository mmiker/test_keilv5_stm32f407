#ifndef __PIN_CONFIG_H
#define __PIN_CONFIG_H

#include "stm32f4xx.h"

void delay_s(uint16_t t);
void delay_ms(uint16_t t);
void delay_us(uint16_t t);

void conf_GPIO(GPIO_TypeDef *	, uint32_t				, GPIOMode_TypeDef, GPIOOType_TypeDef	, GPIOPuPd_TypeDef, GPIOSpeed_TypeDef);
void conf_TIM(TIM_TypeDef *		, uint32_t				, uint16_t				, uint16_t 					, uint16_t				, uint8_t);
void conf_UART(USART_TypeDef *, uint32_t				, uint16_t				, uint16_t 					, uint16_t				, uint16_t, uint16_t);
void conf_NVIC(uint8_t				, FunctionalState , uint8_t					, uint8_t);

#endif
