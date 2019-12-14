/* 
 * robot_state.h
 */


#ifndef __ROBOT_STATE_H__
#define __ROBOT_STATE_H__


#include "stdint.h"


#define NUM_STATE_VARIABLES 6

// Indexing definitions
const uint8_t X_LOC     = 0;
const uint8_t Y_LOC     = 1;
const uint8_t THETA     = 2;
const uint8_t VEL_X     = 3;
const uint8_t VEL_y     = 4;
const uint8_t VEL_THETA = 5;

typedef float state_t; // Can switch between float and double, maybe even int?

typedef struct
{
    /* State Vector that holds the following state information in this order:
     * [0] x location        - in mm
     * [1] y location        - in mm
     * [2] theta             - in radians, restricted between 0 and 2*pi
     * [3] velocity in x     - in mm/sec
     * [4] velocity in y     - in mm/sec
     * [5] velocity in theta - in radians/sec
     */
    state_t x_hat[NUM_STATE_VARIABLES];
    
    /* Covariance Matrix corresponding to the stateVector */
    state_t P[NUM_STATE_VARIABLES][NUM_STATE_VARIABLES];

} robot_state_t;

#endif //__ROBOT_STATE_H__
