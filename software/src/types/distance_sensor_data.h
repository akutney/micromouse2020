/* 
 * distance_data.h
 */


#ifndef __DISTANCE_DATA_H__
#define __DISTANCE_DATA_H__


#include "stdint.h"


#define NUM_OF_DISTANCE_SENSORS 8

const uint8_t FL0 = 0;
const uint8_t FL1 = 1;
const uint8_t FR0 = 2;
const uint8_t FR1 = 3;
const uint8_t BR0 = 4;
const uint8_t BR1 = 5;
const uint8_t BL0 = 6;
const uint8_t BL1 = 7;


/* Distance Data */
typedef struct
{
    /* Readings from distance sensor
     * - Each array location corresponds to a distance sensor by ID
     * - Values in m
     */
    float distances[NUM_OF_DISTANCE_SENSORS];
} distance_sensor_data_t;


#endif //__DISTANCE_DATA_H__
