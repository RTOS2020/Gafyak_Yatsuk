
#include "stm32f10x.h"

void delay();

int main(void)
{
  /* Initialize LED which connected to GPIOB and GPIOC */
  // Enable PORTC Clock
	RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
  /* Configure the GPIOC_LED pin */
	GPIOC -> CRH &= 0; 
  GPIOC -> CRH |= GPIO_CRH_MODE; 

  // Enable PORTB Clock
	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
  /* Configure the GPIOB_LED pin */
	GPIOB -> CRH &= 0; 
  GPIOB -> CRH |= GPIO_CRH_MODE; 

  while (1) {
		GPIOC->ODR^=GPIO_Pin_13;
		GPIOB->ODR=GPIO_Pin_14;
		
		delay();
		
		GPIOB->ODR^=GPIO_Pin_13;
		
		delay();
		
		GPIOC->ODR=GPIO_Pin_13;
		GPIOB->ODR=GPIO_Pin_14;
		
		delay();
		
		GPIOB->ODR^=GPIO_Pin_14;
		
		delay();

  }
}

void delay(void)
{
	for(int i = 0; i < 0x3A98; i++){} //15000
}
