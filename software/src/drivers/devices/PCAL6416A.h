/*
 * PCAL6416A.h
 */

#ifndef __PCAL6416A_H__
#define __PCAL6416A_H__

#include <stdint.h>

// Define registers for PCAL6416A
#define PCAL6416A_INPUT_PORT_0                            0x00
#define PCAL6416A_INPUT_PORT_1                            0x01
#define PCAL6416A_OUTPUT_PORT_0                           0x02
#define PCAL6416A_OUTPUT_PORT_1                           0x03
#define PCAL6416A_POLARITY_INVERSION_PORT_0               0x04
#define PCAL6416A_POLARITY_INVERSION_PORT_1               0x05
#define PCAL6416A_CONFIGURATION_PORT_0                    0x06
#define PCAL6416A_CONFIGURATION_PORT_1                    0x07
#define PCAL6416A_OUTPUT_DRIVE_STRENGTH_REGISTER_0        0x40
#define PCAL6416A_OUTPUT_DRIVE_STRENGTH_REGISTER_1        0x42
#define PCAL6416A_INPUT_LATCH_REGISTER_0                  0x44
#define PCAL6416A_INPUT_LATCH_REGISTER_1                  0x45
#define PCAL6416A_PULL_UP_PULL_DOWN_ENABLE_REGISTER_0     0x46
#define PCAL6416A_PULL_UP_PULL_DOWN_ENABLE_REGISTER_1     0x47
#define PCAL6416A_PULL_UP_PULL_DOWN_SELECTION_REGISTER_0  0x48
#define PCAL6416A_PULL_UP_PULL_DOWN_SELECTION_REGISTER_1  0x49
#define PCAL6416A_INTERRUPT_MASK_REGISTER_0               0x4A
#define PCAL6416A_INTERRUPT_MASK_REGISTER_1               0x4B
#define PCAL6416A_INTERRUPT_STATUS_REGISTER_0             0x4C
#define PCAL6416A_INTERRUPT_STATUS_REGISTER_1             0x4D
#define PCAL6416A_OUTPUT_PORT_CONFIGURATION_REGISTER      0x4F

int init_pcal6416a_driver(void);

int get_pcal6416a_reg(uint8_t reg, uint16_t *val);

int set_pcal6416a_reg(uint8_t reg, uint16_t mask, uint16_t val);

#endif /* __PCAL6416A_H__ */
