/* 
 * time_driver.h
 */


#ifndef __TIME_DRIVER_H__
#define __TIME_DRIVER_H__

#include <time.h>


void init_time_driver(void);

/* Get the value of time since start in seconds
 * - floating not double because that is the best precision we can
 *   get with the 32.768KHz external clock */
void get_time(float * time_since_start);


#endif //__TIME_DRIVER_H__
