#include "pin_config.h"

// TIM2 ---- 84 Mhz

void delay_s(uint16_t t)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  																				// TIMx'i kullanabilmek için gerekli Clock hat baglantisi
	conf_TIM(TIM2, 16000, 21000, TIM_CounterMode_Up, TIM_CKD_DIV1, 50);														// TIMx konfigurasyonu için özel fonksiyon
	
	//conf_NVIC(TIM2_IRQn, ENABLE, 0x01, 0x00);																										// Interrupt konfigurasyonu için özel fonksiyon
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);																									// TIMx'i interrupt olarak kullanmak için gerekli
	
	TIM_Cmd(TIM2, ENABLE);																																				// TIM2 aktif
	
	for(; t > 0; t--)
	{
		TIM_SetCounter(TIM2, 0);
		while(TIM_GetCounter(TIM2) < 4000);
	}
	
	TIM_Cmd(TIM2, DISABLE);
}

void delay_ms(uint16_t t)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  																				// TIMx'i kullanabilmek için gerekli Clock hat baglantisi
	conf_TIM(TIM2, 16000, 21, TIM_CounterMode_Up, TIM_CKD_DIV1, 50);															// TIMx konfigurasyonu için özel fonksiyon
	
	//conf_NVIC(TIM2_IRQn, ENABLE, 0x01, 0x00);																										// Interrupt konfigurasyonu için özel fonksiyon
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);																									// TIMx'i interrupt olarak kullanmak için gerekli
	
	TIM_Cmd(TIM2, ENABLE);																																				// TIM2 aktif
	
	for(; t > 0; t--)
	{
		TIM_SetCounter(TIM2, 0);
		while(TIM_GetCounter(TIM2) < 4000);
	}
	
	TIM_Cmd(TIM2, DISABLE);
}

void delay_us(uint16_t t)																																				// KUVVET 1000 ise t=1 1sn, t=2 2sn ;  KUVVET 1 ise t=1 1us, t=2 2us
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  																				// TIMx'i kullanabilmek için gerekli Clock hat baglantisi
	conf_TIM(TIM2, 16000, 1, TIM_CounterMode_Up, TIM_CKD_DIV1, 50);																// TIMx konfigurasyonu için özel fonksiyon
	
	//conf_NVIC(TIM2_IRQn, ENABLE, 0x01, 0x00);																										// Interrupt konfigurasyonu için özel fonksiyon
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);																									// TIMx'i interrupt olarak kullanmak için gerekli
	
	TIM_Cmd(TIM2, ENABLE);																																				// TIM2 aktif
	
	for(; t > 0; t--)
	{
		TIM_SetCounter(TIM2, 0);
		while(TIM_GetCounter(TIM2) < 84);
	}
	
	TIM_Cmd(TIM2, DISABLE);
}

void conf_GPIO(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed)
{
	GPIO_InitTypeDef GPIO_InitStructure = {
		.GPIO_Pin   = GPIO_Pin,
		.GPIO_Mode  = GPIO_Mode, 
		.GPIO_OType = GPIO_OType,
		.GPIO_PuPd = GPIO_PuPd,
		.GPIO_Speed = GPIO_Speed};
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void conf_TIM(TIM_TypeDef* TIMx, uint32_t TIM_Period, uint16_t TIM_Prescaler, uint16_t TIM_CounterMode, uint16_t TIM_ClockDivision, uint8_t TIM_RepetitionCounter)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {
		.TIM_Period            = TIM_Period,
		.TIM_Prescaler         = TIM_Prescaler,
		.TIM_CounterMode       = TIM_CounterMode,
		.TIM_ClockDivision     = TIM_ClockDivision,
		.TIM_RepetitionCounter = TIM_RepetitionCounter};
	TIM_DeInit(TIMx);
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure);
}

void conf_NVIC(uint8_t NVIC_IRQChannel, FunctionalState NVIC_IRQChannelCmd, uint8_t NVIC_IRQChannelSubPriority, uint8_t NVIC_IRQChannelPreemptionPriority)
{
	NVIC_InitTypeDef NVIC_InitStructure = {
		.NVIC_IRQChannel                   = NVIC_IRQChannel,
		.NVIC_IRQChannelCmd                = NVIC_IRQChannelCmd,
		.NVIC_IRQChannelSubPriority        = NVIC_IRQChannelSubPriority,
		.NVIC_IRQChannelPreemptionPriority = NVIC_IRQChannelPreemptionPriority};
	NVIC_Init(&NVIC_InitStructure);
}

/*
void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		//User Code
		
		//User Code
	}
}*/

void conf_UART(USART_TypeDef* USARTx, uint32_t USART_BaudRate, uint16_t USART_HardwareFlowControl, uint16_t USART_Mode, uint16_t USART_Parity, uint16_t USART_StopBits, uint16_t USART_WordLength)
{
	USART_InitTypeDef USART_InitStructure = {
		.USART_BaudRate = USART_BaudRate,
		.USART_HardwareFlowControl = USART_HardwareFlowControl,
		.USART_Mode = USART_Mode,
		.USART_Parity = USART_Parity,
		.USART_StopBits = USART_StopBits,
		.USART_WordLength = USART_WordLength};
	
	USART_Init(USARTx, &USART_InitStructure);
}
