/* 
 * time_driver.h
 */

#ifndef __TIME_DRIVER_H__
#define __TIME_DRIVER_H__

extern bool TIME_DRIVER_ENABLED;

int init_time_driver(void);

/* Get the value of time since start in seconds
 * - floating not double because that is the best precision we can
 *   get with the 32.768KHz external clock */
int get_time(float *time_since_start);

/* Get the value of time since start in milliseconds */
int get_time_ms(uint64_t *millis);

#endif //__TIME_DRIVER_H__
