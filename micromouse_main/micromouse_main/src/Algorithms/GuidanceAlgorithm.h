/* 
 * GuidanceAlgorithm.h
 *
 * Author: Dan
 */


#ifndef __GUIDANCE_ALGORITHM__H__
#define __GUIDANCE_ALGORITHM__H__


#include "../Types/RobotState.h"
#include "../Types/MazeState.h"


class GuidanceAlgorithm
{
public:

    GuidanceAlgorithm();

    void nextState(RobotState * currentState, MazeState * currentMaze, RobotState * nextState);

private:

};

#endif //__GUIDANCE_ALGORITHM__H__
