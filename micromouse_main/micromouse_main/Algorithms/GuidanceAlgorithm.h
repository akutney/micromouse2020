/* 
* GuidanceAlgorithm.h
*
* Created: 11/12/2019 6:58:11 PM
* Author: 
*/


#ifndef __GUIDANCE_ALGORITHM__H__
#define __GUIDANCE_ALGORITHM__H__


#include "../Types/RobotState.h"
#include "../Types/MazeState.h"


class GuidanceAlgorithm
{
public:

    GuidanceAlgorithm();

    bool setup();

    void nextState(RobotState * currentState, MazeState * currentMaze, RobotState * nextState);

private:

};

#endif //__GUIDANCE_ALGORITHM__H__
