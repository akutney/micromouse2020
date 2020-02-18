/*
 * adc_test.c
 */ 

#include <asf.h>
#include <error.h>

#include "adc_test.h"
#include "../drivers/adc_driver.h"

int adc_test(void)
{
  // ASF system and board initialization
  system_init();

  /* Insert application code here, after the board has been initialized. */
  printf("System Initialized\n");

  CHECK_ERR(init_adc_driver());
  
  printf("Adc Driver Initialized\n");
  
  while (1)
  {
    printf("Getting Adc Data\n");
    
    uint16_t *data = NULL;
    CHECK_ERR(start_get_adc_data());
    CHECK_ERR(get_adc_data(data));
    
    for (int i = 0; i < ADC_BUFFER_SIZE; i++)
    {
      printf("data[%d]: %d\n", i, data[i]);
    }
    
    CHECK_ERR(free_buffer());
  }
}
