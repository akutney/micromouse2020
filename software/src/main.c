/*
 * main.c
 */

#include <error.h>

//#define RUN_ROBOT_MAIN
#define RUN_ADC_TEST

#include "robot/robot_main.h"
#include "hw_tests/adc_test.h"

int main(void)
{

#ifdef RUN_ROBOT_MAIN
  robot_main();
#endif

#ifdef RUN_ADC_TEST
  adc_test();
#endif

}
