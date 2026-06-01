#include "stm32f4xx.h"
#include "uart.h"


int main()
{
	uart_init();

	while(1)
	{

		uart_write('7');
		for(int i=0;i<1000000;i++);
	}





}
