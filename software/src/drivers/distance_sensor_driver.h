/* 
 * distance_sensor_driver.h
 */

#ifndef __DISTANCE_SENSOR_DRIVER_H__
#define __DISTANCE_SENSOR_DRIVER_H__

#include <stdbool.h>

#include "../types/types.h"

extern bool DISTANCE_SENSOR_DRIVER_ENABLED;

int init_distance_sensor_driver(void);

int start_get_distance_sensor_data(void);

int get_distance_sensor_data(distance_sensor_data_t *distances);

#endif //__DISTANCE_SENSOR_DRIVER_H__
