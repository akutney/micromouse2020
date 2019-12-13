/* 
 * robot_state_test.cpp
 */

#ifndef ARDUINO
#include "robot_state.h"
#include "../testing.h"

TEST_FUNC_BEGIN("robot_state_test") {
    
    robot_state_t state;
    TEST_PASS("robot_state constructed");

    // Not many real tests to perform, but this is
    // a good place to try out examples
    state.x_hat[0] = 1;
    state.x_hat[1] = 2;
    state.x_hat[2] = 3;
    state.x_hat[3] = 4;
    state.x_hat[4] = 5;
    state.x_hat[5] = 6;

    for (int i = 0; i < NUM_STATE_VARIABLES; i++){
        state.P[i][0] = 1;
        state.P[i][1] = 2;
        state.P[i][2] = 3;
        state.P[i][3] = 4;
        state.P[i][4] = 5;
        state.P[i][5] = 6;
    }

    asm("nop;");
} TEST_FUNC_END("robot_state_test")

#endif // ARDUINO
