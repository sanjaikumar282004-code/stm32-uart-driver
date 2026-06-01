#include "stm32f4xx.h"
#include "uart.h"

#define LED (1U<<5)

int main()
{
    uart_init();

    // Configure PA5 as output
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);

    int ch;
    int blink = 0;

    while(1)
    {
        // Check if UART data received
        if(USART2->SR & (1U<<5))
        {
            ch = uart_read();

            // Echo received character
            uart_write(ch);

            // Start blinking
            if(ch == '1')
            {
                blink = 1;
            }

            // Stop blinking
            else if(ch == '0')
            {
                blink = 0;
                GPIOA->ODR &= ~LED;
            }

            // Any other character ignored
        }

        // Blink continuously if enabled
        if(blink)
        {
            GPIOA->ODR ^= LED;

            for(int i=0; i<1000000; i++);
        }
    }
}
