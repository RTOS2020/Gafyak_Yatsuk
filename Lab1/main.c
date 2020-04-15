#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void delay(int ms) {
	for(int i = 0; i < 100000 * ms; i++) { }
}

int main(void){ 	
	char oleksandr[] = {'_','_','_',' ','*','_','*','*',' ','*',' ','_','*','_',' ','*','*','*',' ','*','_',' ','_','*',' ','_','*','*',' ','*','_','*'};
	int length = sizeof(oleksandr) / sizeof(char);
		
	int *GPIO_C_CRH = (int*)(0x40011004);
	int *GPIO_C_ODR = (int*)(0x4001100C);

	int *apb2enr = (int*)0x40021018;

	int j = 0;

	*apb2enr |= 0x00008;		
	*GPIO_C_CRH = 0x00100000;
	
	for(;;j++) {
		char element = oleksandr[j % length];
		if(element == '*') {
			*GPIO_C_ODR=0x00000100;
			delay(1000);
		} else if(element == '_') {
			*GPIO_C_ODR=0x00000100;
			delay(4000);
		} else if(element == ' ') {
			*GPIO_C_ODR=0x0000000;
			delay(7000);
		}
		if(j % length == length - 1) delay(3000);
	}
}
