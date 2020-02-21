/*
 * led_outputs.h
 *
 * Led position definition:
 * 
 *         -------------
 *       /               \
 *     /                   \
 *   /      ^                \  
 *  |     / | \     LED0      |
 *  |       |   LED3    LED1  |
 *  |       |       LED2      |
 *   \                       /
 *     \        LED4*      /
 *       \               /
 *         -------------
 * 
 * *LED4 is not in the plus configuration
 */

#ifndef __LED_OUTPUTS_H__
#define __LED_OUTPUTS_H__

#define NUM_OF_LEDS 5

typedef enum
{
  LED0 = 0, // Front
  LED1 = 1, // Right
  LED2 = 2, // Back
  LED3 = 3, // Left
  LED4 = 4, // Other
} led_idx;

typedef struct
{
  /* Output LED data
   * Each array location corresponds to a LED by ID
   * Each value represents wether the LED should be on (true) or off (false)
   */
  bool outputs[NUM_OF_LEDS];
} led_outputs_t;

#endif /* __LED_OUTPUTS_H__ */
