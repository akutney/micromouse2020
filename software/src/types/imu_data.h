/* 
 * imu_data.h
 */

#ifndef __IMU_DATA_H__
#define __IMU_DATA_H__

#include <stdbool.h>

/* Data package from the imu */
typedef struct
{
  bool data_valid;
} imu_data_t;

#endif //__IMU_DATA_H__
