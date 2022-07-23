#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "GPIO.h"
#include "USART.h"
#include "SPI.h"
#include "device.h"
int main(void)
{
    GPIO_EnableClock(0);
    GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);   /*USART Terimnal*/
    USART_EnableClock();
    USART_INIT();

	GPIO_EnableClock(1);         /*Init Port B PIN 0 for sensor chip select*/
	GPIO_Init(1, 0, OUTPUT, PUSH_PULL);


	GPIO_EnableClock(0);         /*Init port A pin 5,6,7 for TC72 spi*/
    *GPIOA_AFRL |= 0x555 << (5*4);
    GPIO_Init(0,5,ALTERNATE_FUN,PUSH_PULL);
    GPIO_Init(0,6,ALTERNATE_FUN,PUSH_PULL);
    GPIO_Init(0,7,ALTERNATE_FUN,PUSH_PULL);


	SPI_EnableClock();         /*Enable SPI*/
	SPI_Init(MASTER, IDLE_LOW, SAMPLE_SOCAND_TRANSITION);


	StartTimer();             /*Polling*/
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();


	while(1)
	{

	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}


