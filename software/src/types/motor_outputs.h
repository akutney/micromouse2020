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
   * Each value represents the desired angular speed in rotations per seconds
   * - A definition of the direction still needs to be made
   */
  float outputs[NUM_OF_MOTORS];
} motor_outputs_t;

#endif //__MOTOR_OUTPUTS_H__
