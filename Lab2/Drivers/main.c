
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void delay(void);

int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Initialize 2 LEDs which connected to PC13 and PB14 */
	
  // Enable PORTC Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Enable PORTB Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  while (1) {
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		delay();
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);
		
		delay();
		
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		delay();
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);
		
		delay();
  }
}

void delay(void)
{
	for(int i = 0; i < 0x3A98; i++){} //15000
}
