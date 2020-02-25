/* 
 * encoder_data.h
 */

#ifndef __ENCODER_DATA_H__
#define __ENCODER_DATA_H__


/*
 * Micromouse robot wheel definition:
 * 
 *         -------------
 *   FL  /               \  FR
 *     /                   \
 *   /          ^            \  
 *  |         / | \           |
 *  |           |             |
 *  |           |             |
 *   \                       /
 *     \                   /
 *   BL  \               /  BR
 *         -------------
 */

typedef enum
{
  ENCODER_FL = 0,
  ENCODER_FR = 1,
  ENCODER_BR = 2, 
  ENCODER_BL = 3
} encoder_idx;


typedef struct
{
  /* Readings from encoders
   * - Each array location corresponds to a distance encoder by ID
   * - Values in m
   */
  float distance[4];
} encoder_data_t;

#endif //__ENCODER_DATA_H__
