/*
 * time_driver.c
 */

#include <asf.h>
#include <error.h>

#include "time_driver.h"

// Extern declarations
bool TIME_DRIVER_ENABLED = true;

// Driver Globals
uint32_t seconds_since_start;

// Function Declarations
void rtc_overflow_callback(void);
int get_time_counts(uint64_t *counts);

int init_time_driver(void)
{
  seconds_since_start = 0;

  rtc_count_register_callback(&rtc_instance, rtc_overflow_callback, RTC_COUNT_CALLBACK_OVERFLOW);
  rtc_count_enable(&rtc_instance);
  
  return RETURN_SUCCESS;
}

int get_time(float *time_since_start)
{
  if (time_since_start == NULL) { THROW_ERR("get_time", EINVAL); }

  uint64_t counts;
  get_time_counts(&counts);
  *time_since_start = (counts / 32768.0);

  return RETURN_SUCCESS;
}

int get_time_ms(uint64_t *millis)
{
  if (millis == NULL) { THROW_ERR("get_time_ms", EINVAL); }

  uint64_t counts;
  get_time_counts(&counts);
  *millis = (uint64_t)((counts * 1000) / 32768);

  return RETURN_SUCCESS;
}

/**
 * Since the RTC clock is running at 32.768 KHz, the 32-bit counter will
 * overflow at 1 Hz. Therefore, this function is called at 1 Hz.
 */
void rtc_overflow_callback(void)
{
  seconds_since_start++;
}

/**
 * Calculates the number of rtc counts based on seconds past and current
 * timestamp value.
 */
int get_time_counts(uint64_t *counts)
{
  if (counts == NULL) { THROW_ERR("get_time_counts", EINVAL); }

  system_interrupt_enter_critical_section();

  uint32_t seconds = seconds_since_start;
  uint32_t current_counts = rtc_count_get_count(&rtc_instance);

  system_interrupt_leave_critical_section();

  // 32768 is the current rtc frequency configuration
  *counts = (seconds * 32768) + current_counts;

  return RETURN_SUCCESS;
}
