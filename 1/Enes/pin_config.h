#ifndef __PIN_CONFIG_H
#define __PIN_CONFIG_H

#include "stm32f4xx.h"

void delay_s(uint16_t t);
void delay_ms(uint16_t t);
void delay_us(uint16_t t);
void conf_GPIO(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed);
void conf_TIM(TIM_TypeDef* TIMx, uint32_t TIM_Period, uint16_t TIM_Prescaler, uint16_t TIM_CounterMode, uint16_t TIM_ClockDivision, uint8_t TIM_RepetitionCounter);
void conf_UART(USART_TypeDef* USARTx, uint32_t USART_BaudRate, uint16_t USART_HardwareFlowControl, uint16_t USART_Mode, uint16_t USART_Parity, uint16_t USART_StopBits, uint16_t USART_WordLength);

//void conf_NVIC(uint8_t NVIC_IRQChannel, FunctionalState NVIC_IRQChannelCmd, uint8_t NVIC_IRQChannelSubPriority, uint8_t NVIC_IRQChannelPreemptionPriority);

#endif
