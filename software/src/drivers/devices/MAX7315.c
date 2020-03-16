/*
 * MAX7315.c
 */ 

#include <asf.h>
#include <error.h>

#include "MAX7315.h"
#include "../i2c_driver.h"

int init_max7315_driver(void)
{
  CHECK_ERR(init_i2c_driver());
  return RETURN_SUCCESS;
}

int get_max7315_reg(uint8_t reg, uint8_t *val)
{
  CHECK_ERR(read_reg8(PWM_I2C_ADDRESS, reg, val));
  return RETURN_SUCCESS;
}

int set_max7315_reg(uint8_t reg, uint8_t mask, uint8_t val)
{
  uint8_t cur_val;
  CHECK_ERR(read_reg8(PWM_I2C_ADDRESS, reg, &cur_val));
  // Keep everything not included in the mask the same
  // while setting everything in the mask to val
  cur_val = (cur_val & ~mask) | (val & mask);
  CHECK_ERR(write_reg8(PWM_I2C_ADDRESS, reg, cur_val));
  return RETURN_SUCCESS;
}

int set_max7315_outputs(uint8_t p1_p0, uint8_t p3_p2,
                        uint8_t p5_p4, uint8_t p7_p6)
{
  const uint8_t buf_size = 5;
  uint8_t buffer[buf_size];
  buffer[0] = MAX7315_OUTPUTS_INTENSITY_P1_P0;
  buffer[1] = p1_p0;
  buffer[2] = p3_p2;
  buffer[3] = p5_p4;
  buffer[4] = p7_p6;
  CHECK_ERR(write_bytes(PWM_I2C_ADDRESS, buffer, buf_size));
  return RETURN_SUCCESS;
}
