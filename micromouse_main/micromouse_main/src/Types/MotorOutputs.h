/* 
 * MotorOutputs.h
 *
 * Author: Dylan Staatz
 */


#ifndef __MOTOR_OUTPUTS_H__
#define __MOTOR_OUTPUTS_H__


#define NUM_OF_MOTORS 4

typedef struct MotorOutputs
{
    /* Output motor data
     * Each array location corresponds to a motor by ID
     * Each value is a floating point number between -1.0 and 1.0
     * */
    float outputs[NUM_OF_MOTORS];

} MotorOutputs;

#endif //__MOTOR_OUTPUTS_H__
