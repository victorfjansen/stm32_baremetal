#include "stm32f4xx.h"

#define TIM2_EN			(1U<<0)
#define TIM2_CEN		(1U<<0)

void tim2_1hz_init(void) {
	/*enable clock access to timer 2*/
	RCC->APB1ENR |= TIM2_EN;

	/*Set the prescaler value*/
	TIM2->PSC = 1600 - 1;  // 16 000 000/ 1600 = 10 000

	/* set auto-reload value */
	TIM2->ARR = 10000 - 1;

	/* clear the timer counter */
	TIM2->CNT = 0;

	/*Enable the timer*/
	TIM2->CR1 |= TIM2_CEN;
}
