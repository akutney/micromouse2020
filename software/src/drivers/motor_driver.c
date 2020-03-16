/*
 * motor_driver.c
 */

#include <error.h>

#include "motor_driver.h"
#include "devices/MAX7315.h"
#include <types.h>

int create_byte(float val, bool invert, uint8_t *out);
int segment(float val, uint8_t *out);

int init_motor_driver(void)
{
  CHECK_ERR(init_max7315_driver());

  // Set overall configuration to disable INT, disable global intesity, and disable blink
  CHECK_ERR(set_max7315_reg(MAX7315_CONFIGURATION, 0x0F, 0x00));
  // Set all pins as outputs
  CHECK_ERR(set_max7315_reg(MAX7315_PORTS_CONFIGURATION, 0xFF, 0x00));

  motor_outputs_t initial;
  initial.outputs[MOTOR_F] = 0.0;
  initial.outputs[MOTOR_L] = 0.0;
  initial.outputs[MOTOR_B] = 0.0;
  initial.outputs[MOTOR_R] = 0.0;
  CHECK_ERR(set_motor_outputs(&initial));

  return RETURN_SUCCESS;
}

int set_motor_outputs(motor_outputs_t *outputs)
{
  // p1_p0, MOTOR_R
  uint8_t p1_p0;
  CHECK_ERR(create_byte(outputs[MOTOR_R], inverted_outputs[MOTOR_R], p1_p0));

  // p3_p2, MOTOR_F
  uint8_t p3_p2;
  CHECK_ERR(create_byte(outputs[MOTOR_F], inverted_outputs[MOTOR_F], p3_p2));

  // p5_p4, MOTOR_L
  uint8_t p5_p4;
  CHECK_ERR(create_byte(outputs[MOTOR_L], inverted_outputs[MOTOR_L], p5_p4));

  // p7_p6, MOTOR_B
  uint8_t p7_p6;
  CHECK_ERR(create_byte(outputs[MOTOR_B], inverted_outputs[MOTOR_B], p7_p6));

  CHECK_ERR(set_max7315_outputs(p1_p0, p3_p2, p5_p4, p7_p6));

  return RETURN_SUCCESS;
}

// Private Functions

int create_byte(float val, bool invert, uint8_t *out)
{
  bool direction = (val > 0);
  direction = invert ? !direction : direction; // invert if nessasary

  uint8_t temp = 0;
  CHECK_ERR(segment(abs(val), temp));

  if (direction)
    *out = (temp & 0x0F);
  else
    *out = (temp & 0x0F) << 4;

  return RETURN_SUCCESS;
}

// Take in val between 0.0 and 1.0 to a 4-bit value
int segment(float val, uint8_t *out)
{
  if ( !(0.0 <= val && val <= 1.0)) // If not in acceptable range
    THROW_ERR("segment", EINVAL);
  
  *out = (((uint8_t)(val * (float)0xFF)) & 0xF0) >> 4;
  return RETURN_SUCCESS;
}
