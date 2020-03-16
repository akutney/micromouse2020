/* 
 * motor_outputs.h
 *
 * Micromouse robot wheel definition:
 * 
 *                F
 *           -------------
 *         /               \
 *       /                   \
 *     /          ^            \  
 *    |         / | \           |
 *  L |           |             | R
 *    |           |             |
 *     \                       /
 *       \                   /
 *         \               /
 *           -------------
 *                B
 */

#ifndef __MOTOR_OUTPUTS_H__
#define __MOTOR_OUTPUTS_H__

#include <stdbool.h>

#define NUM_OF_MOTORS 4

typedef enum
{
  MOTOR_F = 0,
  MOTOR_L = 1,
  MOTOR_B = 2,
  MOTOR_R = 3,
} motor_idx_t;

typedef struct
{
  /* Output motor data
   * Each array location corresponds to a motor by ID
   * Each value is between -1.0 and 1.0, positive values represent clockwise rotation
   */
  float outputs[NUM_OF_MOTORS];
} motor_outputs_t;

extern bool inverted_outputs[NUM_OF_MOTORS];

#endif //__MOTOR_OUTPUTS_H__
