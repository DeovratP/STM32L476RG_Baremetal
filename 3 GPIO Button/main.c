#include "stm32l4xx.h"                  // Device header

int main(void)
{
	RCC->AHB2ENR = 0x5; // enable clock of port A and C
	GPIOA->MODER = 0xABFFF7FF; //Need to set mode of PA05
	GPIOC->MODER = 0xF3FFFFFF; //Need to set mode of PC13
	
	while (1)
	{
		//PC13 is pull-up. Is high when not pressed.
		if(GPIOC->IDR & 0x00002000) //if PC13 is high
		{
			GPIOA->BSRR = 0x00200000 ; //set LED OFF
		} else GPIOA->BSRR = 0x00000020 ; // reset LED ON
	}
}
