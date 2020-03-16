/* 
 * distance_sensor_data.h
 * 
 * Sensor definition:
 *
 *            -------------
 *     FL0  /               \  FR1
 *   FL1  /                   \  FR0
 *      /           ^           \
 *     |          / | \          |
 *     |            |            |
 *     |            |            |
 *      \                       /
 *   BL0  \                   /  BR1
 *     BL1  \               /  BR0
 *            -------------
 */

#ifndef __DISTANCE_SENSOR_DATA_H__
#define __DISTANCE_SENSOR_DATA_H__

#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_DISTANCE_SENSORS 8

typedef enum
{
  SENSOR_FL0 = 0, SENSOR_FL1 = 1,
  SENSOR_BL0 = 2, SENSOR_BL1 = 3,
  SENSOR_BR0 = 4, SENSOR_BR1 = 5,
  SENSOR_FR0 = 6, SENSOR_FR1 = 7,
} sensor_idx_t;

/* Distance Data */
typedef struct
{
  bool data_valid;
  /* Readings from distance sensor
   * - Each array location corresponds to a distance sensor by ID
   * - Values in m
   */
  float distances[NUM_OF_DISTANCE_SENSORS];
} distance_sensor_data_t;

/* Sensor Offsets */
typedef struct
{
  float local_x;
  float local_y;
  float local_theta;
} distance_sensor_offset_t;

extern distance_sensor_offset_t get_sensor_offset[NUM_OF_DISTANCE_SENSORS];

#endif //__DISTANCE_SENSOR_DATA_H__
