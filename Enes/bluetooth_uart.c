#include "bluetooth_uart.h"

void InitBluetoothUart(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	conf_GPIO(GPIOA, GPIO_Pin_2, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_100MHz);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	
	conf_UART(USART2, 9600, USART_HardwareFlowControl_None, USART_Mode_Tx, USART_Parity_No, USART_StopBits_1, USART_WordLength_8b);
}
