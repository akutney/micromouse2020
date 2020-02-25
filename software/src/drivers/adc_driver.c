/*
 * adc_driver.c
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include "adc_driver.h"

// To fill during reading and give to user when done
uint16_t read_buffer[ADC_BUFFER_SIZE];

// To Callback after conversion is done
volatile adc_driver_callback_t callback;

void receive_values(struct adc_module *const module);

int init_adc_driver(void)
{
  // Clear buffers and flags
  memset(read_buffer, 0x00, sizeof(read_buffer));

  adc_register_callback(&adc_instance, receive_values, ADC_CALLBACK_READ_BUFFER);
  return RETURN_SUCCESS;
}

int start_get_adc_data(adc_driver_callback_t func)
{
  enum status_code status;
  
  system_interrupt_enter_critical_section();
  
  status = adc_read_buffer_job(&adc_instance, read_buffer, ADC_BUFFER_SIZE);

  if (status == STATUS_OK)
  {
    callback = func;
  }

  system_interrupt_leave_critical_section();

  if (status != STATUS_OK) {
    THROW_ERR("start_get_adc_data", ENOSR);
  }

  return RETURN_SUCCESS;
}


/* Private functions */

void receive_values(struct adc_module *const module)
{
  callback(read_buffer);
  // After callback exits, the buffer can be considered free
}
