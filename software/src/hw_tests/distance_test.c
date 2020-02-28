/*
 * distance_test.c
 */ 

#include <asf.h>
#include <error.h>

#include "distance_test.h"
#include "../drivers/delay.h"
#include "../drivers/distance_sensor_driver.h"

int distance_test(void)
{
  // ASF system and board initialization
  system_init();

  /* Insert application code here, after the board has been initialized. */
  printf("-------------------------------------------------\n");
  printf("System Initialized\n");
  printf("Board: %s\n", BOARD_NAME);
  printf("-------------------------------------------------\n");

  CHECK_ERR(init_distance_sensor_driver());

  printf("Distance Sensor Initialized\n");

  while (1)
  {
    distance_sensor_data_t data;
    CHECK_ERR(start_get_distance_sensor_data(&data));
    CHECK_ERR(get_distance_sensor_data());

    delay_usec(1000000);
  }
}
