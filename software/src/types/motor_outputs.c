/*
 * motor_outputs.c
 */ 

#include <stdbool.h>

#include "motor_outputs.h"

bool inverted_outputs[NUM_OF_MOTORS] = {
  false, // MOTOR_F // TODO: give corrent value
  false, // MOTOR_L // TODO: give corrent value
  false, // MOTOR_B // TODO: give corrent value
  false  // MOTOR_R // TODO: give corrent value
};
