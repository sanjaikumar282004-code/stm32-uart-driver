#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>

int main()
{
	uart_init();

	while(1)
	{
		for(int j=0;j<100;j++)
		{
			printf("The j= %d\n\r",j);
		}
		for(int i=0;i<1000000;i++);
	}





}
