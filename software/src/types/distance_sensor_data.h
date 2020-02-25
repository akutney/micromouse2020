/* 
 * distance_sensor_data.h
 * 
 * Micromouse sensor definition:
 *
 *               F0   F1
 *            -------------
 *          /               \
 *        /                   \
 *      /           ^           \
 *  L1 |          / | \          | R0
 *     |            |            |
 *  L0 |            |            | R1
 *      \                       /
 *        \                   /
 *          \               /
 *            -------------
 *               B1   B0
 */

#ifndef __DISTANCE_SENSOR_DATA_H__
#define __DISTANCE_SENSOR_DATA_H__

#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_DISTANCE_SENSORS 8

typedef enum
{
  SENSOR_L0 = 0, SENSOR_L1 = 1,
  SENSOR_F0 = 2, SENSOR_F1 = 3,
  SENSOR_R0 = 4, SENSOR_R1 = 5,
  SENSOR_B0 = 6, SENSOR_B1 = 7,
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
