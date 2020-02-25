/*
 * adc_driver.h
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <asf.h>

#define ADC_BUFFER_SIZE ADC_INPUTS_TO_SCAN

typedef void (*adc_driver_callback_t)(uint16_t *buffer);

int init_adc_driver(void);

/* Callback Based */
int start_get_adc_data(adc_driver_callback_t func);

#endif /* ADC_DRIVER_H_ */
