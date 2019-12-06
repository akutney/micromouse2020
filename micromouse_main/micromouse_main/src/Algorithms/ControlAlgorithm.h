/* 
 * ControlAlgorithm.h
 *
 * Author: Dan
 */


#ifndef __CONTROL_ALGORITHM__H__
#define __CONTROL_ALGORITHM__H__


#include "../Types/RobotState.h"
#include "../Types/MotorOutputs.h"


class ControlAlgorithm
{
public:

    ControlAlgorithm();

    void determineOutputs(
        RobotState * currentState,
        RobotState * desiredState,
        MotorOutputs * outputs);

private:

};

#endif //__CONTROL_ALGORITHM__H__
