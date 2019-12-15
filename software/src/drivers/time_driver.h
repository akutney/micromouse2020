/* 
 * time_driver.h
 */


#ifndef __TIME_DRIVER_H__
#define __TIME_DRIVER_H__


#include "../types/types.h"


/* Get the value of time since start in seconds
 * - floating not double because that is the best precision we can
 *   get with the 32.768KHz external clock */
void get_timestamp(float * time_since_start);


#endif //__TIME_DRIVER_H__
