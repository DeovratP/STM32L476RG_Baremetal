#include "stm32l4xx.h"                  // Device header

void delayMS(int delay);
int main(void)
{
	
	RCC->AHB2ENR = 1;
	GPIOA->MODER = 0xABFFF7FF;
	while(1)
	{
		GPIOA->BSRR = 0x00000020;
		delayMS(200);
    GPIOA->BSRR = 0x00200000;
		delayMS(400);
	}
}

void delayMS(int delay)
{
	int i;
	for(;delay>0;delay--)
	{
		for(i = 0;i<3195;i++);
	}
}
