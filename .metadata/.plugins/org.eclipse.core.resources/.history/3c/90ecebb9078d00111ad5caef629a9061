#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "adc.h"
#include "systick.h"

uint32_t sensor_value;

int main(void) {


	uart2_tx_init();

	while(1) {
		sensor_value = adc_read();
		printf("Sensor value: %d  ", (int)sensor_value);
	}

}


