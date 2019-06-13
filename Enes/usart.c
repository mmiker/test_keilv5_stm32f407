#include "usart.h"
/*
						Pins pack 1 	Pins pack 2 	Pins pack 3 	
U(S)ARTx		TX 			RX 		TX 			RX 		TX 			RX 		APB
USART1 			PA9 		PA10 	PB6 		PB7 									2
USART2			PA2 		PA3 	PD5 		PD6 									1
USART3 			PB10 		PB11 	PC10 		PC11 	PD8 		PD9 		1
UART4 			PA0 		PA1 	PC10 		PC11 									1
UART5 			PC12 		PD2 																1
USART6 			PC6 		PC7 	PG14 		PG9 									2
UART7 			PE8 		PE7 	PF7 		PF6 									1
UART8 			PE1 		PE0 																1
https://stm32f4-discovery.net/2014/04/library-04-connect-stm32f429-discovery-to-computer-with-usart/
*/

void InitUsart(USART_TypeDef * USARTx)
{
//if (USARTx == USART2)
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	conf_GPIO(GPIOA, GPIO_Pin_2 | GPIO_Pin_3, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	conf_UART(USARTx, 9600, USART_HardwareFlowControl_None, USART_Mode_Tx | USART_Mode_Rx, USART_Parity_No, USART_StopBits_1, USART_WordLength_8b);
	//USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USARTx, ENABLE);
	//conf_NVIC(USART2_IRQn, ENABLE, 0, 0);
}
/*
void USART2_IRQHandler(void)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
   USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}*/

void recvUsart(USART_TypeDef * USARTx, volatile char * s, uint32_t size)
{
	for (int i = 0; i < size; i++)
	{
		while(!USART_GetFlagStatus(USARTx, USART_FLAG_RXNE));
		*s = (char) USART_ReceiveData(USARTx);
		s++;
	}
}

void sendUsart(USART_TypeDef * USARTx, volatile char * s)
{
	while(*s)
	{
		while(!(USARTx->SR & 0x00000040)); //!USART_GetFlagStatus(USARTx, USART_FLAG_TC));
		USART_SendData(USARTx, *s);
		s++;
	}
	for (int i = 0; i < 2; i++)
	{
		while(!USART_GetFlagStatus(USARTx, USART_FLAG_RXNE));
		*s = (char) USART_ReceiveData(USARTx);
		s++;
	}
}
