#include "stm32f4xx.h"
#include "HP45.h"
#include "usart.h"
#include <stdlib.h>

#define W_SPACE_X_MM 1 //100
#define W_SPACE_Y_MM 1 //100

#define W_SPACE_X_PIXEL (int)(W_SPACE_X_MM/25.4*300)
#define W_SPACE_Y_PIXEL (int)(W_SPACE_Y_MM/25.4*300)

int main()
{
	char a[] = "AT\r\n", b[10] = {0};
	uint16_t nozzle_area[TOTAL_DATA] = {0};
	uint16_t matrix_for_image[W_SPACE_X_PIXEL][W_SPACE_Y_PIXEL] = {0};
	
	InitHp45();
	InitUsart(USART2);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	conf_GPIO(GPIOD, GPIO_Pin_13, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz);
	
	while(1)
	{
		// Bluetooth
		//sendUsart(USART2, a);
		// resimbekle
		
		// Görüntü isleme kütüphanesi
		// Matris Alinacak
		// matrix_for_image e atilacak
		sendUsart(USART2, a);
		//recvUsart(USART2, b, 2);
		//if((b[0] == 'O') && (b[1] == 'K'))
			GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
		delay_s(1);
		/*
		for(int i = 0; i < 1 ; i++)
			for(int j = 0; j < 1; j++)
				matrix_for_image[i][j] = rand() % 2;
		for(int i = 0; i < 1 ; i++) 	// W_SPACE_Y_PIXEL/150
		{
			for(int j = 0; j < 1; j++) 				//W_SPACE_X_PIXEL
			{
				// Motor pozisyonuna gider
				
					nozzle_area[0] =  matrix_for_image[(1 - 1)  /2 + i * 150][j]				|		matrix_for_image[(45 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(89 - 1) /2 + i * 150][j] << 4		| 	matrix_for_image[(133 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(177 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(221 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(265 - 1)/2 + i * 150][j] << 12;
				 
					nozzle_area[1] =  matrix_for_image[(7 - 1)  /2 + i * 150][j]				|		matrix_for_image[(51 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(95 - 1) /2 + i * 150][j] << 4   | 	matrix_for_image[(139 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(183 - 1)/2 + i * 150][j] << 8   |   matrix_for_image[(227 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(271 - 1)/2 + i * 150][j] << 12;
				
					nozzle_area[2] =  matrix_for_image[(13 - 1) /2 + i * 150][j]				|		matrix_for_image[(57 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(101 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(145 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(189 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(233 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(277 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[3] =  matrix_for_image[(19 - 1) /2 + i * 150][j]				|		matrix_for_image[(63 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(107 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(151 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(195 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(239 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(283 - 1)/2 + i * 150][j] << 12;
						
					nozzle_area[4] =  matrix_for_image[(25 - 1) /2 + i * 150][j]				|		matrix_for_image[(69 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(113 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(157 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(201 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(245 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(289 - 1)/2 + i * 150][j] << 12;
													 
					nozzle_area[5] =  matrix_for_image[(31 - 1) /2 + i * 150][j]				|		matrix_for_image[(75 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(119 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(163 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(207 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(251 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(295 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[6] =  matrix_for_image[(37 - 1) /2 + i * 150][j]				|		matrix_for_image[(81 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(125 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(169 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(213 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(257 - 1)/2 + i * 150][j] << 10 ;
											      // | matrix_for_image[(295 - 1)/2 + i * 150][j] << 12 
														// matrix_for_image[(00 - 1)/2 + i * 150][j]		  |
					nozzle_area[7] =  matrix_for_image[(43 - 1) /2 + i * 150][j] << 2   | 
													  matrix_for_image[(87 - 1) /2 + i * 150][j] << 4   |		matrix_for_image[(131 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(175 - 1)/2 + i * 150][j] << 8   |   matrix_for_image[(219 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(263 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[8] =  matrix_for_image[(5 - 1)  /2 + i * 150][j]	    	|		matrix_for_image[(49 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(93 - 1) /2 + i * 150][j] << 4   | 	matrix_for_image[(137 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(181 - 1)/2 + i * 150][j] << 8		|   matrix_for_image[(225 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(269 - 1)/2 + i * 150][j] << 12;
													 
					nozzle_area[9] =  matrix_for_image[(11 - 1) /2 + i * 150][j]				|		matrix_for_image[(55 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(99 - 1) /2 + i * 150][j] << 4 	| 	matrix_for_image[(143 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(187 - 1)/2 + i * 150][j] << 8 	|   matrix_for_image[(231 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(275 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[10] = matrix_for_image[(17 - 1) /2 + i * 150][j]				|		matrix_for_image[(61 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(105 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(149 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(193 - 1)/2 + i * 150][j] << 8 	|   matrix_for_image[(237 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(281 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[11] = matrix_for_image[(23 - 1) /2 + i * 150][j]				|		matrix_for_image[(67 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(111 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(155 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(199 - 1)/2 + i * 150][j] << 8 	|   matrix_for_image[(243 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(287 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[12] = matrix_for_image[(29 - 1) /2 + i * 150][j]				|		matrix_for_image[(73 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(117 - 1)/2 + i * 150][j] << 4		| 	matrix_for_image[(161 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(205 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(249 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(293 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[13] = matrix_for_image[(35 - 1) /2 + i * 150][j]				|		matrix_for_image[(79 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(123 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(167 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(211 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(255 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(299 - 1)/2 + i * 150][j] << 12;
														//matrix_for_image[(35 - 1)/2 + i * 150][j]			  |
					nozzle_area[14] = matrix_for_image[(41 - 1) /2 + i * 150][j] << 2   | 
													  matrix_for_image[(85 - 1) /2 + i * 150][j] << 4 	| 	matrix_for_image[(129 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(173 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(217 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(261 - 1)/2 + i * 150][j] << 12;									
					
					nozzle_area[15] = matrix_for_image[(3 - 1)  /2 + i * 150][j]				|		matrix_for_image[(47 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(91 - 1) /2 + i * 150][j] << 4 	| 	matrix_for_image[(135 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(179 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(223 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(267 - 1)/2 + i * 150][j] << 12;									
					
					nozzle_area[16] = matrix_for_image[(9 - 1)  /2 + i * 150][j]				|		matrix_for_image[(53 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(97 - 1) /2 + i * 150][j] << 4 	|   matrix_for_image[(141 - 1)/2 + i * 150][j] << 6  |
													  matrix_for_image[(229 - 1)/2 + i * 150][j] << 10  |		matrix_for_image[(273 - 1)/2 + i * 150][j] << 12;									
														//matrix_for_image[(229 - 1)/2 + i * 150][j] << 8	  |
					nozzle_area[17] = matrix_for_image[(15 - 1) /2 + i * 150][j]				|		matrix_for_image[(59 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(103 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(147 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(191 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(235 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(279 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[18] = matrix_for_image[(21 - 1) /2 + i * 150][j]				|		matrix_for_image[(65 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(109 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(153 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(197 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(241 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(285 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[19] = matrix_for_image[(27 - 1) /2 + i * 150][j]				|		matrix_for_image[(71 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(115 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(159 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(203 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(247 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(291 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[20] = matrix_for_image[(33 - 1) /2 + i * 150][j]				|		matrix_for_image[(77 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(121 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(165 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(209 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(253 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(297 - 1)/2 + i * 150][j] << 12;
					
					nozzle_area[21] = matrix_for_image[(39 - 1) /2 + i * 150][j]				|		matrix_for_image[(83 - 1) /2 + i * 150][j] << 2  | 
													  matrix_for_image[(127 - 1)/2 + i * 150][j] << 4 	| 	matrix_for_image[(171 - 1)/2 + i * 150][j] << 6  | 
													  matrix_for_image[(215 - 1)/2 + i * 150][j] << 8  	|   matrix_for_image[(259 - 1)/2 + i * 150][j] << 10 |
													  matrix_for_image[(297 - 1)/2 + i * 150][j] << 12;

				fire300Nozzle(nozzle_area);
			}
		}*/
	}
}
