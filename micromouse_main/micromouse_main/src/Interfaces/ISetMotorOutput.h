/* 
 * ISetMotorOutput.h
 *
 * Author: Dylan Staatz
 */


#ifndef __I_SET_MOTOR_OUTPUT_H__
#define __I_SET_MOTOR_OUTPUT_H__


#include "../Types/MotorOutputs.h"


class ISetMotorOutput
{
public:

    virtual void setMotorOutput(MotorOutputs * outputs);

protected:

private:

};

#endif //__I_SET_MOTOR_OUTPUT_H__
