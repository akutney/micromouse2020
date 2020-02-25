/*
 * distance_sensor_driver.c
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include "../types/types.h"
#include "distance_sensor_driver.h"
#include "adc_driver.h"
#include "i2c_driver.h"
#include "gpio_driver.h"

// Need to take two measurements, one to record a base amount IR being
// received on the sensor, and one with the IR emitter on

// Need to set up interrupts and callbacks start these actions in order:
// - Take adc measurement (baseline)
// - Set emitter high
// - Take adc measurement
// - Set emitter low

bool DISTANCE_SENSOR_DRIVER_ENABLED = true;

void adc_driver_callback_0(uint16_t *buffer);
void adc_driver_callback_1(uint16_t *buffer);
float sensor_linear_regression_model(int16_t adc_value);
static inline int sensor_idx_to_ain_idx(uint8_t sensor_idx, uint8_t *ain_idx);
static inline int ain_idx_to_sensor_idx(uint8_t ain_idx, uint8_t *sensor_idx);

uint16_t baseline_adc_values[NUM_OF_DISTANCE_SENSORS];
float final_distance_values[NUM_OF_DISTANCE_SENSORS];

int init_distance_sensor_driver(void)
{
  init_adc_driver();
  init_i2c_driver();
  // TODO: Initialize pins on I/O expander

  THROW_ERR("start_get_distance_sensor_data", ENOSYS);

  return RETURN_SUCCESS;
}

int start_get_distance_sensor_data(void)
{
  CHECK_ERR(start_get_adc_data(adc_driver_callback_0));
  return RETURN_SUCCESS;
}

int get_distance_sensor_data(distance_sensor_data_t *distances)
{
  uint16_t *buffer = NULL;
  //int16_t base_value;
  //int16_t diff_value;
//
  //get_adc_data(&buffer);
  //base_value = buffer[0];
  //free_buffer();
//
  //set_pin(test_ir_pin, PIN_HIGH);
//
  //get_adc_data(&buffer);
  //diff_value = buffer[0] - base_value;
  //free_buffer();
//
  //set_pin(test_ir_pin, PIN_LOW); // reset
//
  //printf("base_value: %d\tdiff_value: %d\n", base_value, diff_value);

  return RETURN_SUCCESS;
}

int try_get_distance_sensor_data(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distance_sensor_data", ENOSYS);
}


/* Private Functions */

void adc_driver_callback_0(uint16_t *buffer)
{
  // Completed first baseline read
  // Store Data
  uint8_t ain_idx;
  for (int i = 0; i < NUM_OF_DISTANCE_SENSORS; i++)
  {
    sensor_idx_to_ain_idx(i, &ain_idx);
    baseline_adc_values[i] = buffer[ain_idx];
  }

  // Set I/O pins over i2c
  // TODO

  // Start next conversion
  start_get_adc_data(adc_driver_callback_1);
}

void adc_driver_callback_1(uint16_t *buffer)
{
  // Completed final read
  // Process Data
  uint8_t ain_idx;
  int16_t difference;
  for (int i = 0; i < NUM_OF_DISTANCE_SENSORS; i++)
  {
    sensor_idx_to_ain_idx(i, &ain_idx);
    
    // Calculate IR difference
    difference = buffer[ain_idx] - baseline_adc_values[i]; // With emitter - without emitter
    
    // Regress with linear model
    final_distance_values[i] = sensor_linear_regression_model(difference);
  }

  // Unset I/O pins over i2c
  // TODO

  // Mark distance sensing as done
  // TODO
}

float sensor_linear_regression_model(int16_t adc_value)
{
  // TODO
  return (float)adc_value;
}

static inline int sensor_idx_to_ain_idx(sensor_idx_t sensor_idx, uint8_t *ain_idx)
{
  switch(sensor_idx)
  {
    case SENSOR_L0:
      *ain_idx = PHOTO1_AIN;
      break;
    case SENSOR_L1:
      *ain_idx = PHOTO2_AIN;
      break;
    case SENSOR_F0:
      *ain_idx = PHOTO3_AIN;
      break;
    case SENSOR_F1:
      *ain_idx = PHOTO4_AIN;
      break;
    case SENSOR_R0:
      *ain_idx = PHOTO5_AIN;
      break;
    case SENSOR_R1:
      *ain_idx = PHOTO6_AIN;
      break;
    case SENSOR_B0:
      *ain_idx = PHOTO7_AIN;
      break;
    case SENSOR_B1:
      *ain_idx = PHOTO8_AIN;
      break;
    default:
      THROW_ERR("sensor_idx_to_ain_idx", EINVAL_AIN);
  }
  
  return RETURN_SUCCESS;
}

static inline int ain_idx_to_sensor_idx(uint8_t ain_idx, sensor_idx_t *sensor_idx)
{
  switch(ain_idx)
  {
    case PHOTO1_AIN:
      *sensor_idx = SENSOR_L0;
      break;
    case PHOTO2_AIN:
      *sensor_idx = SENSOR_L1;
      break;
    case PHOTO3_AIN:
      *sensor_idx = SENSOR_F0;
      break;
    case PHOTO4_AIN:
      *sensor_idx = SENSOR_F1;
      break;
    case PHOTO5_AIN:
      *sensor_idx = SENSOR_R0;
      break;
    case PHOTO6_AIN:
      *sensor_idx = SENSOR_R1;
      break;
    case PHOTO7_AIN:
      *sensor_idx = SENSOR_B0;
      break;
    case PHOTO8_AIN:
      *sensor_idx = SENSOR_B1;
      break;
    default:
      THROW_ERR("ain_idx_to_sensor_idx", EINVAL_SENSOR);
  }
  
  return RETURN_SUCCESS;
}
