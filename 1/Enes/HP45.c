#include "HP45.h"

void InitHp45(void)
{
	RCC_AHB1PeriphClockCmd(HP45_ADDRESS_RCC_Periph  , ENABLE);																																			// GPIOx'i kullanabilmek için gerekli Clock hat baglantisi
	RCC_AHB1PeriphClockCmd(HP45_PRIMITIVE_RCC_Periph, ENABLE);
	
	conf_GPIO(HP45_ADDRESS_GPIO  , HP45_ADDRESS_CLOCK , GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);							// GPIOx konfigurasyonu için ozel fonksiyon
	conf_GPIO(HP45_ADDRESS_GPIO  , HP45_ADDRESS_RESET , GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);
	conf_GPIO(HP45_PRIMITIVE_GPIO, HP45_PRIMITIVE_LINE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);
}

void fire14Nozzle(uint16_t data14)
{
	GPIO_SetBits(HP45_ADDRESS_GPIO, HP45_ADDRESS_CLOCK);
	delay_us(2);
	
	GPIO_Write(HP45_PRIMITIVE_GPIO, data14);
	delay_us(2);
	
	GPIO_Write(HP45_PRIMITIVE_GPIO, 0x0000);
	delay_us(2);
	
	GPIO_ResetBits(HP45_ADDRESS_GPIO, HP45_ADDRESS_CLOCK);
	delay_us(1);
}

void fire300Nozzle(uint16_t *data300)
{
	GPIO_ResetBits(HP45_ADDRESS_GPIO, HP45_ADDRESS_RESET);
	
	for(int i = 0; i < TOTAL_DATA; i++)
		fire14Nozzle(data300[i]);
	
	GPIO_SetBits(HP45_ADDRESS_GPIO, HP45_ADDRESS_RESET);
	delay_us(1);
}
