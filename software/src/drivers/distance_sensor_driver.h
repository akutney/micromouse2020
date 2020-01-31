/* 
 * distance_driver.h
 */


#ifndef __DISTANCE_SENSOR_DRIVER_H__
#define __DISTANCE_SENSOR_DRIVER_H__


#include "../types/types.h"


void init_distance_sensor_driver(void);

void get_distances(distance_sensor_data_t * distances);


#endif //__DISTANCE_SENSOR_DRIVER_H__
