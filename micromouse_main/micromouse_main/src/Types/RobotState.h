/* 
 * RobotState.h
 *
 * Author: Dylan Staatz
 */


#ifndef __ROBOT_STATE_H__
#define __ROBOT_STATE_H__


#include <Eigen/Dense>

using namespace Eigen;


#define NUM_STATE_VARIABLES 6

typedef float state_t; // Can switch between float and double, maybe even int?

typedef struct RobotState
{
    /* State Vector that holds the following state information in this order:
     * [0] x location        - in mm
     * [1] y location        - in mm
     * [2] theta             - in radians, restricted between 0 and 2*pi
     * [3] velocity in x     - in mm/sec
     * [4] velocity in y     - in mm/sec
     * [5] velocity in theta - in radians/sec
     */
    Matrix<state_t, NUM_STATE_VARIABLES, 1> x_hat;

    /* Covariance Matrix coresponding to the stateVector */
    Matrix<state_t, NUM_STATE_VARIABLES, NUM_STATE_VARIABLES> P;

    // Alternatively (if Eigen doesn't work):
    // State Variables
    //state_t x, y, theta, deltaX, deltaY, deltaTheta;
    // covariance matrix
    //state_t covariance[NUM_STATE_VARIABLES][NUM_STATE_VARIABLES];

} RobotState;

#endif //__ROBOT_STATE_H__
