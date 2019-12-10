/* 
 * SerialDriver.h
 *
 * Author: Dylan Staatz
 */


#ifndef __SERIAL_DRIVER_H__
#define __SERIAL_DRIVER_H__


#include "../Interfaces/ILogger.h"
#include "../Types/Ints.h"

class SerialDriver : ILogger
{

public:

	SerialDriver(uint8_t instance);

	~SerialDriver();

	// Prints a '\0' terminated string to some console
    void Print(char * str);

	// Prints a '\0' terminated string to some console
    // and starts a newline
    void Println(char * str);

protected:

private:

    uint8_t instance_;

}; //SerialDriver

#endif //__SERIAL_DRIVER_H__
