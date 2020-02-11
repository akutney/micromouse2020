/*
 * adc_driver.h
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>

#define ADC_BUFFER_SIZE 15

int init_adc_driver(void);

int start_get_adc_data(void);

int get_adc_data(uint16_t *buffer);

int free_buffer();

#endif /* ADC_DRIVER_H_ */