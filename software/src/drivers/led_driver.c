/*
 * led_driver.c
 */ 

#include <asf.h>
#include <error.h>
#include "i2c_driver.h"
#include "../types/types.h"

bool LED_DRIVER_ENABLED = true;

int init_led_driver(void)
{
  init_i2c_driver();
  write_reg16(IO_I2C_ADDRESS,0x06,0x0000);
}

int set_led_outputs(led_outputs_t * out_led)
{
  uint16_t val = 0xFFFF;
  
  val = val & (out_led->outputs[LED0] ? ~0x0100 : ~0x0000);
  val = val & (out_led->outputs[LED1] ? ~0x0200 : ~0x0000);
  val = val & (out_led->outputs[LED2] ? ~0x0800 : ~0x0000);
  val = val & (out_led->outputs[LED3] ? ~0x1000 : ~0x0000);
  val = val & (out_led->outputs[LED4] ? ~0x0400 : ~0x0000);

  write_reg16(IO_I2C_ADDRESS, 0x02, val);
  THROW_ERR("set_led_outputs", ENOSYS);
}
