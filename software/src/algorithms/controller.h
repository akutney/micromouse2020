/* 
 * controller.h
 */

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "../types/types.h"

/* controller
 * 
 * Determine the outputs to set the motor to given the current state
 * and the desired state*/
int controller(
    const robot_state_t *const current_state,
    const robot_state_t *const desired_state,
    motor_outputs_t *const outputs);

#endif //__CONTROLLER_H__
