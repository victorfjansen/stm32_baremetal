#include "stm32f4xx.h"

#define SYSTICK_LOAD_VALUE		16000
#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSRC				(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)

void systickDelayMs(int delay) {
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD = SYSTICK_LOAD_VALUE;

	/*Clear systick current value register*/
	SysTick->VAL = 0;

	/*Enable systick and select internal clock source*/
	SysTick->CRTL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i = 0; i < (delay); i++) {
		/*wait until the COUNTFLAG`s set*/

		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
	}

	SysTick->CTRL = 0;
}
