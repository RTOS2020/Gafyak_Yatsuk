
void delay(void);

int main(void)
{
	int *GPIO_C13_CRH = (int*)(0x40011004);
        int *GPIO_B14_CRH = (int*)(0x40010C04);
	
	int *GPIO_C13_ODR = (int*)(0x4001100C);
	int *GPIO_B14_ODR = (int*)(0x40010C0C);
	
	int *APB2ENR = (int*)0x40021018;
	
	*APB2ENR|=0x00018;     
	
	*GPIO_C13_CRH = 0x30000000;
	*GPIO_B14_CRH = 0x00000033;

  while (1) {
		*GPIO_C13_ODR = 0x00002000;
		*GPIO_B14_ODR = 0x00002000;
		
		delay();
		
		*GPIO_B14_ODR = 0x00000000;
		
		delay();
		
		*GPIO_C13_ODR = 0x00000000;
		*GPIO_B14_ODR = 0x00002000;		
		
		delay();
		
		*GPIO_B14_ODR = 0x00000000;
		
		delay();
  }
}

void delay(void)
{
	for(int i = 0; i < 0x3A98; i++){} //15000
}
