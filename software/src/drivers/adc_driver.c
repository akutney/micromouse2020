/*
 * adc_driver.c
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include "adc_driver.h"

uint16_t read_buffer[ADC_BUFFER_SIZE];

void receive_values(struct adc_module *const module);

int init_adc_driver(void)
{
  adc_register_callback(&adc_instance, receive_values, ADC_CALLBACK_READ_BUFFER);
  
  memset(read_buffer, 0x00, sizeof(read_buffer));
  
  return RETURN_SUCCESS;
}

int start_get_adc_data(void)
{
  THROW_ERR("start_get_adc_data", ENOSYS);
}

int get_adc_data(uint16_t *buffer)
{
  THROW_ERR("get_adc_data", ENOSYS);
}

int free_buffer()
{
  THROW_ERR("free_buffer", ENOSYS);
}

void receive_values(struct adc_module *const module)
{
  // TODO
}
