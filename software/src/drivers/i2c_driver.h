/*
 * i2c_driver.h
 */

#ifndef __I2C_DRIVER_H__
#define __I2C_DRIVER_H__

#include <asf.h>
#include <error.h>

extern bool I2C_DRIVER_ENABLED;

typedef void (*write_callback_t)(void);
typedef void (*read_callback_t)(uint8_t val);

int init_i2c_driver(void);

int register_i2c_callbacks(
  int8_t address,
  write_callback_t write_calback,
  read_callback_t read_calback);

int write_reg8(int8_t address, uint8_t reg, uint8_t val);

int read_reg8(int8_t address, uint8_t reg, uint8_t *val);

#endif /* __I2C_DRIVER_H__ */
