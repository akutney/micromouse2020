/* 
 * motor_driver.h
 */

#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include "../types/types.h"

int init_motor_driver(void);

int set_motor_outputs(motor_outputs_t *outputs);

#endif //__MOTOR_DRIVER_H__
