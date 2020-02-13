/*
 * i2c_driver.h
 */

#ifndef __I2C_DRIVER_H__
#define __I2C_DRIVER_H__

#include "../types/types.h"

void write_reg8(int8_t address, uint8_t reg, uint8_t val);

void read_reg8(int8_t address, uint8_t reg, uint8_t *val);

#endif /* __I2C_DRIVER_H__ */
