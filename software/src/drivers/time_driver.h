/* 
 * time_driver.h
 */


#ifndef __TIME_DRIVER_H__
#define __TIME_DRIVER_H__

#include <time.h>

/* Get the value of time since start in seconds
 * - floating not double because that is the best precision we can
 *   get with the 32.768KHz external clock */
float get_time(void);
float get_time(void) { return 1.0; } // TODO


#endif //__TIME_DRIVER_H__
