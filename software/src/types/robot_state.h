/* 
 * robot_state.h
 */

#ifndef __ROBOT_STATE_H__
#define __ROBOT_STATE_H__

#include <stdint.h>

#define NUM_STATE_VARIABLES 6

// Indexing definitions
typedef enum
{
  X_LOC = 0,
  Y_LOC = 1,
  THETA = 2,
  VEL_X = 3,
  VEL_y = 4,
  VEL_THETA = 5,
} state_idx;

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
  float x_hat[NUM_STATE_VARIABLES];

  /* Covariance Matrix corresponding to the stateVector */
  float P[NUM_STATE_VARIABLES][NUM_STATE_VARIABLES];

} robot_state_t;

#endif //__ROBOT_STATE_H__
