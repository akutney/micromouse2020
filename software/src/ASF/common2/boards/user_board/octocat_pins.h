/*
 * octocat_pins.h
 */

#ifndef __OCTOCAT_PINS_H__
#define __OCTOCAT_PINS_H__

#include <stdint.h>
#include <types.h>


/* ----- Pin Definitions directly from schematic ----- */
// Clock Pins
extern pin_t XIN32;
extern pin_t XOUT32;
extern pin_t XIN;
extern pin_t XOUT;

// ADC Pins
extern pin_t VREFA;
extern pin_t PHOTO1;
extern pin_t PHOTO2;
extern pin_t PHOTO3;
extern pin_t PHOTO4;
extern pin_t PHOTO5;
extern pin_t PHOTO6;
extern pin_t PHOTO7;
extern pin_t PHOTO8;

// Bluetooth Serial Pins
extern pin_t BT_STATE;
extern pin_t BT_TX;
extern pin_t BT_RX;
extern pin_t BT_EN;

// Motor Encoders Pins
extern pin_t ENCODER_1A;
extern pin_t ENCODER_1B;
extern pin_t ENCODER_2A;
extern pin_t ENCODER_2B;
extern pin_t ENCODER_3A;
extern pin_t ENCODER_3B;
extern pin_t ENCODER_4A;
extern pin_t ENCODER_4B;

// IMU Pins
extern pin_t IMU_INT;

// I2C Pins
extern pin_t SDA;
extern pin_t SCL;

// Debugging Pins
extern pin_t SWDCLK;
extern pin_t SWDIO;

#endif /* __OCTOCAT_PINS_H__ */
