/*
 * distance_sensor_data.c
 */ 

#include "distance_sensor_data.h"

distance_sensor_offset_t get_sensor_offset[NUM_OF_DISTANCE_SENSORS] = {
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_FL0 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_FL1 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_FR0 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_FR1 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_BR0 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_BR1 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_BL0 // TODO
  { .local_x = 20.0, .local_y = 20.0, .local_theta = 20.0 }, // SENSOR_BL1 // TODO
};
