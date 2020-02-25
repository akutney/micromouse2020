/*
 * encoder_driver.c
 */ 


#include <asf.h>
#include <error.h>

#include "encoder_driver.h"

bool ENCODER_DRIVER_ENABLED = false;

int init_encoder_driver(void)
{
  THROW_ERR("init_encoder_driver", ENOSYS);
  
  //initialize encoder
  
}

int start_get_encoder_data(void)
{
  THROW_ERR("start_get_encoder_data", ENOSYS);
}

int get_encoder_data(encoder_data_t *values)
{
  THROW_ERR("get_encoder_data", ENOSYS);
}

void configure_extint_callbacks(void)
{
    extint_register_callback(extint_detection_callback,
            BUTTON_0_EIC_LINE,
            EXTINT_CALLBACK_TYPE_DETECT);
    extint_chan_enable_callback(BUTTON_0_EIC_LINE,
            EXTINT_CALLBACK_TYPE_DETECT);
}
void extint_detection_callback(void)
{
    bool pin_state = port_pin_get_input_level(BUTTON_0_PIN);
    port_pin_set_output_level(LED_0_PIN, pin_state);
}