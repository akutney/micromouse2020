/* 
* ILogger.h
*
* Created: 11/12/2019 6:58:11 PM
* Author: Dylan Staatz
*/


#ifndef __I_LOGGER_H__
#define __I_LOGGER_H__


class ILogger
{
public:

    // Prints a '\0' terminated string to some console
    virtual void Print(char * str);

    // Prints a '\0' terminated string to some console
    // and starts a newline
    virtual void Println(char * str);

protected:

private:

};

#endif //__I_LOGGER_H__
