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

/** Name string macro */
#define BOARD_NAME       "MICROMOUSE"
//#define OCTO_CAT
#define SPARKFUN_BOARD

#define PORT_A 0
#define PORT_B 1

#ifdef OCTO_CAT

// Clock Pins
#define XIN32_PORT       PORT_A
#define XIN32_PIN        00
#define XOUT32_PORT      PORT_A
#define XOUT32_PIN       01
#define XIN_PORT         PORT_A
#define XIN_PIN          14
#define XOUT_PORT        PORT_A
#define XOUT_PIN         15

// ADC Pins
#define VREFA_PORT       PORT_A
#define VREFA_PIN        3
#define PHOTO1_PORT      PORT_A
#define PHOTO1_PIN       4
#define PHOTO1_AIN       4
#define PHOTO2_PORT      PORT_A
#define PHOTO2_PIN       5
#define PHOTO2_AIN       5
#define PHOTO3_PORT      PORT_A
#define PHOTO3_PIN       6
#define PHOTO3_AIN       6
#define PHOTO4_PORT      PORT_A
#define PHOTO4_PIN       7
#define PHOTO4_AIN       7
#define PHOTO5_PORT      PORT_A
#define PHOTO5_PIN       8
#define PHOTO5_AIN       16
#define PHOTO6_PORT      PORT_A
#define PHOTO6_PIN       9
#define PHOTO6_AIN       17
#define PHOTO7_PORT      PORT_A
#define PHOTO7_PIN       10
#define PHOTO7_AIN       18
#define PHOTO8_PORT      PORT_B
#define PHOTO8_PIN       9
#define PHOTO8_AIN       3

// Bluetooth Serial
#define BT_STATE_PORT    PORT_A
#define BT_STATE_PIN     11
#define BT_TX_PORT       PORT_A
#define BT_TX_PIN        12
#define BT_RX_PORT       PORT_A
#define BT_RX_PIN        13
#define BT_EN_PORT       PORT_A
#define BT_EN_PIN        16

// Motor Encoders
#define ENCODER_1A_PORT     PORT_A
#define ENCODER_1A_PIN      21
#define ENCODER_1A_EXTINT   5
#define ENCODER_1B_PORT     PORT_A
#define ENCODER_1B_PIN      24
#define ENCODER_1B_EXTINT   12
#define ENCODER_2A_PORT     PORT_A
#define ENCODER_2A_PIN      18
#define ENCODER_2A_EXTINT   2
#define ENCODER_2B_PORT     PORT_A
#define ENCODER_2B_PIN      17
#define ENCODER_2B_EXTINT   1
#define ENCODER_3A_PORT     PORT_A
#define ENCODER_3A_PIN      20
#define ENCODER_3A_EXTINT   4
#define ENCODER_3B_PORT     PORT_A
#define ENCODER_3B_PIN      19
#define ENCODER_3B_EXTINT   3
#define ENCODER_4A_PORT     PORT_B
#define ENCODER_4A_PIN      23
#define ENCODER_4A_EXTINT   7
#define ENCODER_4B_PORT     PORT_B
#define ENCODER_4B_PIN      22
#define ENCODER_4B_EXTINT   6

// IMU
#define IMU_INT_PORT     PORT_B
#define IMU_INT_PIN      10

// I2C Pins
#define SDA_PORT         PORT_A
#define SDA_PIN          22
#define SCL_PORT         PORT_A
#define SCL_PIN          23

// Debugging Pins
#define SWDCLK_PORT      PORT_A
#define SWDCLK_PIN       30
#define SWDIO_PORT       PORT_A
#define SWDIO_PIN        31

/* Other Definitions */
#define ADC_INPUTS_TO_SCAN 15

#endif

#ifdef SPARKFUN_BOARD

// Clock Pins
#define XIN32_PORT       PORT_A
#define XIN32_PIN        00
#define XOUT32_PORT      PORT_A
#define XOUT32_PIN       01
#define XIN_PORT         PORT_A
#define XIN_PIN          14
#define XOUT_PORT        PORT_A
#define XOUT_PIN         15

// ADC Pins
#define VREFA_PORT       PORT_A
#define VREFA_PIN        3
#define PHOTO1_PORT      PORT_A
#define PHOTO1_PIN       4
#define PHOTO1_AIN       4
#define PHOTO2_PORT      PORT_A
#define PHOTO2_PIN       5
#define PHOTO2_AIN       5
#define PHOTO3_PORT      PORT_A
#define PHOTO3_PIN       6
#define PHOTO3_AIN       6
#define PHOTO4_PORT      PORT_A
#define PHOTO4_PIN       7
#define PHOTO4_AIN       7
#define PHOTO5_PORT      PORT_A
#define PHOTO5_PIN       8
#define PHOTO5_AIN       16
#define PHOTO6_PORT      PORT_A
#define PHOTO6_PIN       9
#define PHOTO6_AIN       17
#define PHOTO7_PORT      PORT_A
#define PHOTO7_PIN       10
#define PHOTO7_AIN       18
#define PHOTO8_PORT      PORT_B
#define PHOTO8_PIN       9
#define PHOTO8_AIN       3

// Bluetooth Serial
#define BT_STATE_PORT    PORT_A
#define BT_STATE_PIN     11
#define BT_TX_PORT       PORT_A
#define BT_TX_PIN        12
#define BT_RX_PORT       PORT_A
#define BT_RX_PIN        13
#define BT_EN_PORT       PORT_A
#define BT_EN_PIN        16

// Motor Encoders
#define ENCODER_1A_PORT     PORT_A
#define ENCODER_1A_PIN      21
#define ENCODER_1A_EXTINT   5
#define ENCODER_1B_PORT     PORT_A
#define ENCODER_1B_PIN      24
#define ENCODER_1B_EXTINT   12
#define ENCODER_2A_PORT     PORT_A
#define ENCODER_2A_PIN      18
#define ENCODER_2A_EXTINT   2
#define ENCODER_2B_PORT     PORT_A
#define ENCODER_2B_PIN      17
#define ENCODER_2B_EXTINT   1
#define ENCODER_3A_PORT     PORT_A
#define ENCODER_3A_PIN      20
#define ENCODER_3A_EXTINT   4
#define ENCODER_3B_PORT     PORT_A
#define ENCODER_3B_PIN      19
#define ENCODER_3B_EXTINT   3
#define ENCODER_4A_PORT     PORT_B
#define ENCODER_4A_PIN      23
#define ENCODER_4A_EXTINT   7
#define ENCODER_4B_PORT     PORT_B
#define ENCODER_4B_PIN      22
#define ENCODER_4B_EXTINT   6

// IMU
#define IMU_INT_PORT     PORT_B
#define IMU_INT_PIN      10

// I2C Pins
#define SDA_PORT         PORT_A
#define SDA_PIN          22
#define SCL_PORT         PORT_A
#define SCL_PIN          23

// Debugging Pins
#define SWDCLK_PORT      PORT_A
#define SWDCLK_PIN       30
#define SWDIO_PORT       PORT_A
#define SWDIO_PIN        31

/* Other Definitions */
#define ADC_INPUTS_TO_SCAN 2

#endif

/** @} */

#ifdef __cplusplus
}
#endif

#endif // USER_BOARD_H
