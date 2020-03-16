/*
 * MAX7315.h
 */

#ifndef __MAX7315_H__
#define __MAX7315_H__

#include <stdint.h>

// Define registers for MAX7315
#define MAX7315_BLINK_PHASE_0             0x01
#define MAX7315_PORTS_CONFIGURATION       0x03
#define MAX7315_BLINK_PHASE_1             0x09
#define MAX7315_MASTER_INTENSITY          0x0E
#define MAX7315_CONFIGURATION             0x0F
#define MAX7315_OUTPUTS_INTENSITY_P1_P0   0x10
#define MAX7315_OUTPUTS_INTENSITY_P3_P2   0x11
#define MAX7315_OUTPUTS_INTENSITY_P5_P4   0x12
#define MAX7315_OUTPUTS_INTENSITY_P7_P6   0x13

int init_max7315_driver(void);

int get_max7315_reg(uint8_t reg, uint8_t *val);

int set_max7315_reg(uint8_t reg, uint8_t mask, uint8_t val);

int set_max7315_outputs(uint8_t p1_p0, uint8_t p3_p2,
                        uint8_t p5_p4, uint8_t p7_p6);

#endif /* __MAX7315_H__ */
