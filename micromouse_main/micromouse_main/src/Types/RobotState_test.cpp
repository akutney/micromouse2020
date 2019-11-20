/* 
 * RobotState_test.cpp
 *
 * Author: Dylan Staatz
 */

#ifndef ARDUINO
#include "RobotState.h"
#include "../testing.h"

//#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

TEST_FUNC_BEGIN("RobotState_test") {
    
    RobotState state;
    TEST_PASS("RobotState constructed");

    // Not many real tests to perform, but this is
    // a good place to try out examples
    state.x_hat << 1, 2, 3, 4, 5, 6;

    state.P << 1, 2, 3, 4, 5, 6,
               1, 2, 3, 4, 5, 6,
               1, 2, 3, 4, 5, 6,
               1, 2, 3, 4, 5, 6,
               1, 2, 3, 4, 5, 6,
               1, 2, 3, 4, 5, 6;

    asm("nop;");
} TEST_FUNC_END("RobotState_test")

#endif // ARDUINO
