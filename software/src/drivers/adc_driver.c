/*
 * adc_driver.c
 */

#include "adc_driver.h"

#define ADC_BUFFER_SIZE 15
uint16_t read_buffer[ADC_BUFFER_SIZE];

void receive_values(struct adc_module *const module);

int init_adc_driver(void)
{
  //adc_register_callback(&adc_instance, receive_values, ADC_CALLBACK_READ_BUFFER)
  //adc_callback_t()
  //adc_read_buffer_job
}

int get_adc_values(uint16_t* vals)
{
  //adc_read_buffer_job(&adc_instance, &read_buffer, ADC_BUFFER_SIZE);
  //
  //adc_enable_interrupt()
}
