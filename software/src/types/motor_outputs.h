/* 
 * motor_outputs.h
 *
 * Micromouse robot wheel definition:
 * 
 *         -------------
 *   FL  /               \  FR
 *     /                   \
 *   /          ^            \  
 *  |         / | \           |
 *  |           |             |
 *  |           |             |
 *   \                       /
 *     \                   /
 *   BL  \               /  BL
 *         -------------
 */


#ifndef __MOTOR_OUTPUTS_H__
#define __MOTOR_OUTPUTS_H__


#include "stdint.h"


#define NUM_OF_MOTORS 4

const uint8_t FL = 0;
const uint8_t FR = 1;
const uint8_t BR = 2;
const uint8_t BL = 3;

typedef struct
{
    /* Output motor data
     * Each array location corresponds to a motor by ID
     * Each value is a floating point number between -1.0 and 1.0
     */
    float outputs[NUM_OF_MOTORS];
} motor_outputs_t;


#endif //__MOTOR_OUTPUTS_H__
