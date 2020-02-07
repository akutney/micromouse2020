/*
 * adc_driver.h
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>

int init_adc_driver(void);

int get_adc_value(uint16_t* val);

#endif /* ADC_DRIVER_H_ */