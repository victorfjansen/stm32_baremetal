#include "stm32f4xx.h"

#define TIM2_EN			(1U<<0)
#define TIM2_CEN		(1U<<0)
#define OC_TOGGLE		((1U<<5) | (1U<<4))
#define CCER_CC1E		(1U<<0)

#define GPIOAEN 		(1U<<0)

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

void tim2_PA5_output_compare(void) {
	//configure PA5

	/*enable gpioa*/
	RCC->AHB1ENR = GPIOAEN;

	/*Set PA5 mode to alternate function*/

	//MODER to alternate function for PA2 is 10 on pint 5 and 4
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);

	// AFRL 2 -- mode 7 - 0111 starting from 11 pin to 8 pin (4its) - tx mode
	GPIOA->AFR[0] &=~(1U<<23);
	GPIOA->AFR[0] &=~(1U<<22);
	GPIOA->AFR[0] &=~(1U<<21);
	GPIOA->AFR[0] |=(1U<<20);


	/*enable clock access to timer 2*/
	RCC->APB1ENR |= TIM2_EN;

	/*Set the prescaler value*/
	TIM2->PSC = 1600 - 1;  // 16 000 000/ 1600 = 10 000

	/* set auto-reload value */
	TIM2->ARR = 10000 - 1;

	/*Set output compare toggle mode*/
	// set OC1M register to 011 - toggle mode
	TIM2->CCMR1 = OC_TOGGLE;

	/*Enable timer 2 channel 1 in compare mode*/
	TIM2->CCER |= CCER_CC1E;

	/* clear the timer counter */
	TIM2->CNT = 0;

	/*Enable the timer*/
	TIM2->CR1 |= TIM2_CEN;
}
