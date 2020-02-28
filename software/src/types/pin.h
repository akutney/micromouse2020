/*
 * pin.h
 */ 


#ifndef __PIN_H__
#define __PIN_H__

#include <stdint.h>

typedef enum
{
  PIN_INPUT,
  PIN_OUTPUT,
  PIN_INPUT_PULLUP,
} pin_config;

typedef enum
{
  PIN_LOW,
  PIN_HIGH,
} pin_value;

typedef enum
{
  PORT_A = 0,
  PORT_B = 1,
} pin_port;

typedef struct
{
  pin_port port;
  uint8_t pinNum;
} pin_t;


#endif /* __PIN_H__ */
