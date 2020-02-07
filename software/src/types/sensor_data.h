/* 
 * sensor_data.h
 */

#ifndef __SENSOR_DATA_H__
#define __SENSOR_DATA_H__

#include "types.h"

typedef struct
{
  distance_sensor_data_t distance_sensor_data;
  encoder_data_t encoder_data;
  float time_data;
  imu_data_t imu_data;
} sensor_data_t;

#endif //__SENSOR_DATA_H__
