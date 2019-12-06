/* 
 * IConsumeButtonData.h
 *
 * Author: Dylan Staatz
 */


#ifndef __I_CONSUME_BUTTON_DATA_H__
#define __I_CONSUME_BUTTON_DATA_H__


#include "../Types/ButtonData.h"


class IConsumeButtonData
{
public:

    virtual void consumeButtonData(ButtonData & data);

};

#endif //__I_CONSUME_BUTTON_DATA_H__
