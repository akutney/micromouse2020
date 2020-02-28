/*
 * distance_sensor_driver.c
 * 
 * Need to take two measurements, one to record a base amount IR being
 * received on the sensor, and one with the IR emitter on
 *
 * Need to set up interrupts and callbacks start these actions in order:
 * - Take adc measurement (baseline)
 * - Set emitter high
 * - Take adc measurement
 * - Set emitter low
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include <types.h>
#include "distance_sensor_driver.h"
#include "adc_driver.h"
#include "devices/PCAL6416A.h"

#ifdef SPARKFUN_BOARD
#include "gpio_driver.h"
#endif

bool DISTANCE_SENSOR_DRIVER_ENABLED = true;

volatile distance_sensor_data_t * distance_data_ptr;
volatile uint16_t baseline_adc_values[NUM_OF_DISTANCE_SENSORS];

volatile bool started;
volatile bool ready_flag;

int _get_distance_sensor_data(bool is_blocking);
void adc_driver_callback_0(uint16_t *buffer);
void adc_driver_callback_1(uint16_t *buffer);
float sensor_linear_regression_model(int16_t adc_value);
static inline int sensor_idx_to_ain_idx(uint8_t sensor_idx, uint8_t *ain_idx);

int init_distance_sensor_driver(void)
{
  CHECK_ERR(init_adc_driver());
  CHECK_ERR(init_pcal6416a_driver());

#ifdef SPARKFUN_BOARD
  // pin_t pin = { .port = , .pinNum =  }
  // configure_pin() // TODO
#endif

  system_interrupt_enter_critical_section();
  started = false;
  ready_flag = false;
  system_interrupt_leave_critical_section();

  // Initialize IR pins on I/O expander
  // - Set all of port 1 as output
  CHECK_ERR(set_pcal6416a_reg(PCAL6416A_CONFIGURATION_PORT_0, 0x00FF, 0x00FF));

  return RETURN_SUCCESS;
}

int start_get_distance_sensor_data(distance_sensor_data_t *distance_data)
{
  system_interrupt_enter_critical_section();

  if (started)
  {
    system_interrupt_leave_critical_section();
    return RETURN_SUCCESS;
  }

  started = true;
  ready_flag = false;
  distance_data_ptr = distance_data;
  distance_data_ptr->data_valid = false;

  system_interrupt_leave_critical_section();

  CHECK_ERR(start_get_adc_data(adc_driver_callback_0));

  return RETURN_SUCCESS;
}

int get_distance_sensor_data()
{
  CHECK_ERR(_get_distance_sensor_data(true));
  return RETURN_SUCCESS;
}

int try_get_distance_sensor_data()
{
  CHECK_ERR(_get_distance_sensor_data(false));
  return RETURN_SUCCESS;
}


/* Private Functions */

int _get_distance_sensor_data(bool is_blocking)
{
  // Start read if not already started, then give user the distance_data once ready
  system_interrupt_enter_critical_section();

  if (!started)
  {
    system_interrupt_leave_critical_section();
    THROW_ERR("_get_distance_sensor_data", EIO);
  }

  if (is_blocking)
  {
    // Block
    system_interrupt_leave_critical_section();
    while (!ready_flag)
      ;
    system_interrupt_enter_critical_section();
  }
  else
  {
    // Non-Blocking
    if (!ready_flag)
    {
      system_interrupt_leave_critical_section();
      return RETURN_SUCCESS;
    }
  }

  // Reset flag
  ready_flag = false;

  system_interrupt_leave_critical_section();
  return RETURN_SUCCESS;
}

void adc_driver_callback_0(uint16_t *buffer)
{
  // Completed first baseline read
  // Store Data for later
  uint8_t ain_idx;
  for (int i = 0; i < NUM_OF_DISTANCE_SENSORS; i++)
  {
    sensor_idx_to_ain_idx(i, &ain_idx);
    baseline_adc_values[i] = buffer[ain_idx];
  }

  // Set I/O pins over i2c on port 1 as high
  set_pcal6416a_reg(PCAL6416A_OUTPUT_PORT_0, 0x00FF, 0x00FF);

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
    difference = buffer[ain_idx] - baseline_adc_values[i]; // With emitter minus without emitter

    // Regress with linear model
    distance_data_ptr->distances[i] = sensor_linear_regression_model(difference);
  }

  // Unset I/O pins over i2c on port 1 back to low
  set_pcal6416a_reg(PCAL6416A_OUTPUT_PORT_0, 0x00FF, 0x0000);

  // Mark distance sensing as done
  system_interrupt_enter_critical_section();
  ready_flag = true;
  distance_data_ptr->data_valid = true;
  system_interrupt_leave_critical_section();
}

float sensor_linear_regression_model(int16_t adc_value)
{
  // TODO: Complete linear regression model
  return (float)adc_value;
}

static inline int sensor_idx_to_ain_idx(sensor_idx_t sensor_idx, uint8_t *ain_idx)
{
  switch (sensor_idx)
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
