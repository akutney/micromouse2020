/*
 * PCAL6416A.c
 */ 

#include <asf.h>
#include <error.h>

#include "PCAL6416A.h"
#include "i2c_driver.h"

int init_pcal6416a_driver(void)
{
  CHECK_ERR(init_i2c_driver());
  return RETURN_SUCCESS;
}

int get_pcal6416a_reg(uint8_t reg, uint16_t *val)
{
  CHECK_ERR(read_reg16(IO_I2C_ADDRESS, reg, val));
  return RETURN_SUCCESS;
}

int set_pcal6416a_reg(uint8_t reg, uint16_t mask, uint16_t val)
{
  uint16_t cur_val;
  CHECK_ERR(read_reg16(IO_I2C_ADDRESS, reg, &cur_val));
  // Keep everything not included in the mask the same
  // while setting everything in the mask to val
  cur_val = (cur_val & ~mask) | (val & mask);
  CHECK_ERR(write_reg16(IO_I2C_ADDRESS, reg, cur_val));
  return RETURN_SUCCESS;
}
