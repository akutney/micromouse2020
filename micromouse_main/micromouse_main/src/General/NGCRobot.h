/* 
 * Robot.h
 *
 * Author: Dylan Staatz
 */


#ifndef __NGC_ROBOT_H__
#define __NGC_ROBOT_H__

#include "../Types/ButtonData.h"
#include "../Types/SensorData.h"

#include "../Interfaces/IConsumeButtonData.h"
#include "../Interfaces/IConsumeSensorData.h"
#include "../Interfaces/ILogger.h"
#include "../Interfaces/ISetMotorOutput.h"


class NGCRobot : IConsumeSensorData, IConsumeButtonData
{
public:

    NGCRobot(ButtonData & initState,
             ILogger & logger,
             ISetMotorOutput & motorOutput);

    void consumeSensorData(SensorData & data);

    void consumeButtonData(ButtonData & data);

private:

};

#endif //__NGC_ROBOT_H__
