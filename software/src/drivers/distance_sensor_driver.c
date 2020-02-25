/*
 * distance_sensor_driver.c
 */

#include <asf.h>
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

typedef enum {
  NOT_STARTED,
  PHOTO_0,
  EMITTER_0,
  PHOTO_1,
  EMITTER_1,
} distance_driver_state;

distance_driver_state state;

#ifdef SPARKFUN_BOARD
pin_t test_ir_pin = { .port = PORT_A, .pinNum = 2, };
#endif


int init_distance_sensor_driver(void)
{
  state = NOT_STARTED;
  init_adc_driver();
  
#ifdef OCTO_CAT_BOARD
  init_i2c_driver();
  // TODO: Initialize pins on I/O expander
  
  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
#endif

#ifdef SPARKFUN_BOARD
  CHECK_ERR(configure_pin(test_ir_pin, PIN_OUTPUT));
#endif

  return RETURN_SUCCESS;
}

int start_get_distance_sensor_data(void)
{
  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
}

#ifdef SPARKFUN_BOARD
int get_distance_sensor_data(distance_sensor_data_t *distances)
{
  uint16_t * buffer = NULL;
  int16_t base_value;
  int16_t diff_value;

  get_adc_data(&buffer);
  base_value = buffer[0];
  free_buffer();

  //set_pin(test_ir_pin, PIN_HIGH);

  get_adc_data(&buffer);
  diff_value = buffer[0] - base_value;
  free_buffer();

  //set_pin(test_ir_pin, PIN_LOW); // reset

  printf("base_value: %d\tdiff_value: %d\n", base_value, diff_value);
  
  return RETURN_SUCCESS;
}
#endif

int try_get_distance_sensor_data(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distance_sensor_data", ENOSYS);
}
