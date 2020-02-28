/**
 * \file
 *
 * \brief User board definition template
 *
 */

 /* This file is intended to contain definitions and configuration details for
 * features and devices that are available on the board, e.g., frequency and
 * startup time for an external crystal, external memory devices, LED and USART
 * pins.
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef USER_BOARD_H
#define USER_BOARD_H

#include <conf_board.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_common_boards
 * \defgroup user_board_group User board
 *
 * @{
 */

void system_board_init(void);

/* ----- Board Selection ----- */
//#define OCTOCAT_BOARD
#define SPARKFUN_BOARD
/* --------------------------- */

#define USER_BOARD_H_CONCAT(a, b) USER_BOARD_H_CONCAT_AGAIN(a, b)
#define USER_BOARD_H_CONCAT_AGAIN(a, b) a ## b


#ifdef OCTOCAT_BOARD
#define BOARD_NAME "OCTOCAT"

// Include pin definitions
#include "octocat_pins.h"

// ADC Settings
#define ADC_INPUT_START_AIN 4
#define ADC_INPUT_START     USER_BOARD_H_CONCAT(ADC_POSITIVE_INPUT_PIN, ADC_INPUT_START_AIN)
#define ADC_INPUTS_TO_SCAN  15
#define PHOTO1_AIN          4
#define PHOTO2_AIN          5
#define PHOTO3_AIN          6
#define PHOTO4_AIN          7
#define PHOTO5_AIN          16
#define PHOTO6_AIN          17
#define PHOTO7_AIN          18
#define PHOTO8_AIN          3
#define PHOTO1_AIN_IDX      (PHOTO1_AIN - ADC_INPUT_START_AIN)
#define PHOTO2_AIN_IDX      (PHOTO2_AIN - ADC_INPUT_START_AIN)
#define PHOTO3_AIN_IDX      (PHOTO3_AIN - ADC_INPUT_START_AIN)
#define PHOTO4_AIN_IDX      (PHOTO4_AIN - ADC_INPUT_START_AIN)
#define PHOTO5_AIN_IDX      (PHOTO5_AIN - ADC_INPUT_START_AIN)
#define PHOTO6_AIN_IDX      (PHOTO6_AIN - ADC_INPUT_START_AIN)
#define PHOTO7_AIN_IDX      (PHOTO7_AIN - ADC_INPUT_START_AIN)
#define PHOTO8_AIN_IDX      (PHOTO8_AIN - ADC_INPUT_START_AIN)

// ENTINT Settings
#define ENCODER_1A_EXTINT   5
#define ENCODER_1B_EXTINT   12
#define ENCODER_2A_EXTINT   2
#define ENCODER_2B_EXTINT   1
#define ENCODER_3A_EXTINT   4
#define ENCODER_3B_EXTINT   3
#define ENCODER_4A_EXTINT   7
#define ENCODER_4B_EXTINT   6

// I2C Settings
#define I2C_USE_FAST_MODE
#define PWM_I2C_ADDRESS     0x20
#define IO_I2C_ADDRESS      0x20
#define IMU_I2C_ADDRESS     0x28

#endif /* OCTOCAT_BOARD */



#ifdef SPARKFUN_BOARD
#define BOARD_NAME "SPARKFUN"

// Include pin definitions
#include "sparkfun_pins.h"

// ADC Settings
#define ADC_INPUT_START_AIN 2
#define ADC_INPUT_START     USER_BOARD_H_CONCAT(ADC_POSITIVE_INPUT_PIN, ADC_INPUT_START_AIN)
#define ADC_INPUTS_TO_SCAN  1
#define PHOTO1_AIN          ADC_INPUT_START_AIN
#define PHOTO2_AIN          ADC_INPUT_START_AIN
#define PHOTO3_AIN          ADC_INPUT_START_AIN
#define PHOTO4_AIN          ADC_INPUT_START_AIN
#define PHOTO5_AIN          ADC_INPUT_START_AIN
#define PHOTO6_AIN          ADC_INPUT_START_AIN
#define PHOTO7_AIN          ADC_INPUT_START_AIN
#define PHOTO8_AIN          ADC_INPUT_START_AIN
#define PHOTO1_AIN_IDX      (PHOTO1_AIN - ADC_INPUT_START_AIN)
#define PHOTO2_AIN_IDX      (PHOTO2_AIN - ADC_INPUT_START_AIN)
#define PHOTO3_AIN_IDX      (PHOTO3_AIN - ADC_INPUT_START_AIN)
#define PHOTO4_AIN_IDX      (PHOTO4_AIN - ADC_INPUT_START_AIN)
#define PHOTO5_AIN_IDX      (PHOTO5_AIN - ADC_INPUT_START_AIN)
#define PHOTO6_AIN_IDX      (PHOTO6_AIN - ADC_INPUT_START_AIN)
#define PHOTO7_AIN_IDX      (PHOTO7_AIN - ADC_INPUT_START_AIN)
#define PHOTO8_AIN_IDX      (PHOTO8_AIN - ADC_INPUT_START_AIN)

// ENTINT Settings
#define ENCODER_1A_EXTINT   5
#define ENCODER_1B_EXTINT   12
#define ENCODER_2A_EXTINT   2
#define ENCODER_2B_EXTINT   1
#define ENCODER_3A_EXTINT   4
#define ENCODER_3B_EXTINT   3
#define ENCODER_4A_EXTINT   7
#define ENCODER_4B_EXTINT   6

// I2C Settings
#define I2C_USE_FAST_MODE
#define PWM_I2C_ADDRESS     0x20
#define IO_I2C_ADDRESS      0x20
#define IMU_I2C_ADDRESS     0x28

#endif /* SPARKFUN_BOARD */


/** @} */

#ifdef __cplusplus
}
#endif

// #undef USER_BOARD_H_CONCAT_AGAIN
// #undef USER_BOARD_H_CONCAT
#endif // USER_BOARD_H
