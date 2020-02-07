/* 
 * distance_sensor_data.h
 */

#ifndef __DISTANCE_SENSOR_DATA_H__
#define __DISTANCE_SENSOR_DATA_H__

#include <stdint.h>

#define NUM_OF_DISTANCE_SENSORS 8

typedef enum
{
  SENSOR_FL0 = 0, SENSOR_FL1 = 1,
  SENSOR_FR0 = 2, SENSOR_FR1 = 3,
  SENSOR_BR0 = 4, SENSOR_BR1 = 5,
  SENSOR_BL0 = 6, SENSOR_BL1 = 7,
} sensor_idx;

/* Distance Data */
typedef struct
{
  /* Readings from distance sensor
   * - Each array location corresponds to a distance sensor by ID
   * - Values in m
   */
  float distances[NUM_OF_DISTANCE_SENSORS];
} distance_sensor_data_t;

#endif //__DISTANCE_SENSOR_DATA_H__
