/*
 * adc_driver.c
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include "interrupts.h"
#include "adc_driver.h"

uint16_t read_buffer_[ADC_BUFFER_SIZE]; // To fill during reading and give to user when done

bool read_started;
bool buffer_ready_flag;

void receive_values(struct adc_module *const module);

int init_adc_driver(void)
{
  // Clear buffers and flags
  memset(read_buffer_, 0x00, sizeof(read_buffer_));
  
  read_started = false;
  buffer_ready_flag = false;
  
  adc_register_callback(&adc_instance, receive_values, ADC_CALLBACK_READ_BUFFER);
  return RETURN_SUCCESS;
}

int start_get_adc_data(void)
{
  // Start job
  if (read_started) {
    return RETURN_SUCCESS; // Read is already started
  }
  
  while (adc_read_buffer_job(&adc_instance, read_buffer_, ADC_BUFFER_SIZE) != STATUS_OK);
  read_started = true;
  
  return RETURN_SUCCESS;
}

int get_adc_data(uint16_t *buffer)
{
  // Start read if not already started, then give user the data once ready
  if (!read_started) {
    start_get_adc_data();
  }
  
  // Block on buffer_ready_flag
  while (!buffer_ready_flag);
  buffer_ready_flag = false;
  
  buffer = read_buffer_;
  
  return RETURN_SUCCESS;
}

// A call must be made to free_buffer after every call to get_adc_data.
// If not called, another read cannot be started
int free_buffer(void)
{
  bool state = disable_interrupts();
  read_started = false;
  set_interrupts(state);
  
  return RETURN_SUCCESS;
}

void receive_values(struct adc_module *const module)
{
  bool state = disable_interrupts();
  buffer_ready_flag = true;
  set_interrupts(state);
}
