/* 
 * sensor_driver.h
 */

#ifndef __SENSOR_DRIVER_H__
#define __SENSOR_DRIVER_H__

#include <types.h>

int init_sensor_driver(void);

int get_sensor_data(sensor_data_t *data);

#endif //__SENSOR_DRIVER_H__
