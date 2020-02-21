/*
 * i2c_driver.h
 */

#ifndef __I2C_DRIVER_H__
#define __I2C_DRIVER_H__

#include <asf.h>
#include <error.h>

extern bool I2C_DRIVER_ENABLED;

int init_i2c_driver(void);

int write_reg8(int8_t address, uint8_t reg, uint8_t val);

int write_reg16(int8_t address, uint8_t reg, uint16_t val);

int read_reg8(int8_t address, uint8_t reg, uint8_t *val);

int read_reg16(int8_t address, uint8_t reg, uint16_t *val);

#endif /* __I2C_DRIVER_H__ */
