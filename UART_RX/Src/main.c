#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>

int main()
{
	uart_init();

	while(1)
	{
		int ch;
		ch=uart_read();
		uart_write(ch);
		for(int i=0;i<100000;i++);
	}





}
