/* 
* IConsumeSensorData.h
*
* Created: 11/12/2019 6:58:11 PM
* Author: Dylan Staatz
*/


#ifndef __I_CONSUME_SENSOR_DATA_H__
#define __I_CONSUME_SENSOR_DATA_H__


class IConsumeSensorData
{
public:

    virtual void consumeSensorData(SensorData & data);

};

#endif //__I_CONSUME_SENSOR_DATA_H__
