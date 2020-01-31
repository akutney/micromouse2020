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

#define PORT_A 0
#define PORT_B 1

/** Pin Definitions from Rev 1.pdf @ec186d34d300730f485768154128261eb8063653 */
#define XIN32_PORT       PORT_A
#define XIN32_PIN        00
#define XOUT32_PORT      PORT_A
#define XOUT32_PIN       01
#define XIN_PORT         PORT_A
#define XIN_PIN          14
#define XOUT_PORT        PORT_A
#define XOUT_PIN         15
#define VREFA_PORT       PORT_A
#define VREFA_PIN        03
#define PHOTO1_PORT      PORT_A
#define PHOTO1_PIN       04
#define PHOTO2_PORT      PORT_A
#define PHOTO2_PIN       05
#define PHOTO3_PORT      PORT_A
#define PHOTO3_PIN       06
#define PHOTO4_PORT      PORT_A
#define PHOTO4_PIN       07
#define PHOTO5_PORT      PORT_A
#define PHOTO5_PIN       08
#define PHOTO6_PORT      PORT_A
#define PHOTO6_PIN       09
#define PHOTO7_PORT      PORT_A
#define PHOTO7_PIN       10
#define PHOTO8_PORT      PORT_B
#define PHOTO8_PIN       09
#define BT_STATE_PORT    PORT_A
#define BT_STATE_PIN     11
#define BT_TX_PORT       PORT_A
#define BT_TX_PIN        12
#define BT_RX_PORT       PORT_A
#define BT_RX_PIN        13
#define BT_EN_PORT       PORT_A
#define BT_EN_PIN        16
#define ENCODER_1A_PORT  PORT_B
#define ENCODER_1A_PIN   03
#define ENCODER_1B_PORT  PORT_B
#define ENCODER_1B_PIN   02
#define ENCODER_2A_PORT  PORT_A
#define ENCODER_2A_PIN   18
#define ENCODER_2B_PORT  PORT_A
#define ENCODER_2B_PIN   17
#define ENCODER_3A_PORT  PORT_A
#define ENCODER_3A_PIN   20
#define ENCODER_3B_PORT  PORT_A
#define ENCODER_3B_PIN   19
#define ENCODER_4A_PORT  PORT_B
#define ENCODER_4A_PIN   23
#define ENCODER_4B_PORT  PORT_B
#define ENCODER_4B_PIN   22
#define IMU_INT_PORT     PORT_B
#define IMU_INT_PIN      10
#define SDA_PORT         PORT_A
#define SDA_PIN          22
#define SCL_PORT         PORT_A
#define SCL_PIN          23
#define SWDCLK_PORT      PORT_A
#define SWDCLK_PIN       30
#define SWDIO_PORT       PORT_A
#define SWDIO_PIN        31

/** @} */

#ifdef __cplusplus
}
#endif

#endif // USER_BOARD_H
