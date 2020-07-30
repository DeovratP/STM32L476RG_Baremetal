#include "stm32l4xx.h"                  // Device header
void delayMs(int delay);

int main(void)
{
	RCC->AHB2ENR |= 0x00000001; // Irrespective of original value of AHB2ENR, 
	                            // The clock for GPIOA should be enabled
	GPIOA->MODER = 0xABFFF7FF;  // 0b 0000 0000 0000 0000 0000 0100 0000 0000 
	                            // Do not use OR here
	
	while(1)
	{
		GPIOA->ODR = 0x20;
    delayMs(500);
		GPIOA->ODR &=~ 0x20;
		delayMs(500);
	}
}

void delayMs(int delay){
int i;
    for(;delay>0; delay --){
        for (i=0; i<3195;i++);
    }
}
