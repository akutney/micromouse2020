/* 
 * imu_driver.h
 */


#ifndef __IMU_DRIVER_H__
#define __IMU_DRIVER_H__


#include "../types/types.h"


#ifdef IMU_ENABLE
void init_imu_driver(void);

void get_imu_data(imu_data_t * data);
#endif // IMU_ENABLE


#endif //__IMU_DRIVER_H__
