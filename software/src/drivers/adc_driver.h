/*
 * adc_driver.h
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <asf.h>

#define ADC_BUFFER_SIZE ADC_INPUTS_TO_SCAN

int init_adc_driver(void);

// Non-blocking call to start reading adc data to obtain later
int start_get_adc_data(void);

// Blocking call that starts reading if needed, otherwise, gives the adc data
int get_adc_data(uint16_t **buffer);

// Non-Blocking call to start reading if needed, otherwise, checks if adc data is ready
// returns EBUSY if adc data is not ready yet
int try_get_adc_data(uint16_t **buffer);

// A call must be made to free_buffer after every call to get_adc_data.
// If not called, another read cannot be started
int free_buffer(void);

#endif /* ADC_DRIVER_H_ */
