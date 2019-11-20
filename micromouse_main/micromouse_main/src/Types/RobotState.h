/* 
* RobotState.h
*
* Created: 11/12/2019 6:58:11 PM
* Author: Dylan Staatz
*/


#ifndef __ROBOT_STATE_H__
#define __ROBOT_STATE_H__

typedef float state_t;

#define NUM_STATE_VARIABLES 6

typedef struct RobotState
{
    state_t x;
    state_t y;
    state_t theta;

    state_t deltaX;
    state_t deltaY;
    state_t deltaTheta;

    state_t covariance[NUM_STATE_VARIABLES][NUM_STATE_VARIABLES];

} RobotState;

#endif //__ROBOT_STATE_H__
