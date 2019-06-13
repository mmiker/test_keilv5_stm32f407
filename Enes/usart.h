#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"
#include "pin_config.h"

void InitUsart(USART_TypeDef * USARTx);
void recvUsart(USART_TypeDef * USARTx, volatile char *s, uint32_t);
void sendUsart(USART_TypeDef * USARTx, volatile char *s);

#endif
