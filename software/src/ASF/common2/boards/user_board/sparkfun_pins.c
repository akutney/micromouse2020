/*
 * sparkfun_pins.c
 */

#include "sparkfun_pins.h"

/* ----- Pin Definitions from sparkfun datasheet ----- */
/* https://cdn.sparkfun.com/assets/learn_tutorials/4/5/4/graphicalDatasheet-Mini.pdf */

// Analog I/O
#define AREF_PORT       PORT_A
#define AREF_PIN_NUM    3
#define A0_PORT         PORT_A
#define A0_PIN_NUM      2
#define A1_PORT         PORT_B
#define A1_PIN_NUM      8
#define A2_PORT         PORT_B
#define A2_PIN_NUM      9
#define A3_PORT         PORT_A
#define A3_PIN_NUM      4

// Digital I/O
#define D0_PORT         PORT_A
#define D0_PIN_NUM      11
#define D1_PORT         PORT_A
#define D1_PIN_NUM      10
#define D2_PORT         PORT_A
#define D2_PIN_NUM      14
#define D3_PORT         PORT_A
#define D3_PIN_NUM      9
#define D4_PORT         PORT_A
#define D4_PIN_NUM      8
#define D5_PORT         PORT_A
#define D5_PIN_NUM      15
#define D6_PORT         PORT_A
#define D6_PIN_NUM      20
#define D7_PORT         PORT_A
#define D7_PIN_NUM      21
#define D8_PORT         PORT_A
#define D8_PIN_NUM      6
#define D9_PORT         PORT_A
#define D9_PIN_NUM      7
#define D10_PORT        PORT_A
#define D10_PIN_NUM     18
#define D11_PORT        PORT_A
#define D11_PIN_NUM     16
#define D12_PORT        PORT_A
#define D12_PIN_NUM     19
// Didn't double define D13 with LED_13

// LEDs
#define TXLED_PORT      PORT_A
#define TXLED_PIN_NUM   27
#define RXLED_PORT      PORT_B
#define RXLED_PIN_NUM   3
#define LED_13_PORT     PORT_A
#define LED_13_PIN_NUM  17

// I2C
#define SCL_I2C_PORT    PORT_A
#define SCL_I2C_PIN_NUM 23
#define SDA_I2C_PORT    PORT_A
#define SDA_I2C_PIN_NUM 22


pin_t AREF    = { .port = AREF_PORT,    .pinNum = AREF_PIN_NUM    };
pin_t A0      = { .port = A0_PORT,      .pinNum = A0_PIN_NUM      };
pin_t A1      = { .port = A1_PORT,      .pinNum = A1_PIN_NUM      };
pin_t A2      = { .port = A2_PORT,      .pinNum = A2_PIN_NUM      };
pin_t A3      = { .port = A3_PORT,      .pinNum = A3_PIN_NUM      };
pin_t D0      = { .port = D0_PORT,      .pinNum = D0_PIN_NUM      };
pin_t D1      = { .port = D1_PORT,      .pinNum = D1_PIN_NUM      };
pin_t D2      = { .port = D2_PORT,      .pinNum = D2_PIN_NUM      };
pin_t D3      = { .port = D3_PORT,      .pinNum = D3_PIN_NUM      };
pin_t D4      = { .port = D4_PORT,      .pinNum = D4_PIN_NUM      };
pin_t D5      = { .port = D5_PORT,      .pinNum = D5_PIN_NUM      };
pin_t D6      = { .port = D6_PORT,      .pinNum = D6_PIN_NUM      };
pin_t D7      = { .port = D7_PORT,      .pinNum = D7_PIN_NUM      };
pin_t D8      = { .port = D8_PORT,      .pinNum = D8_PIN_NUM      };
pin_t D9      = { .port = D9_PORT,      .pinNum = D9_PIN_NUM      };
pin_t D10     = { .port = D10_PORT,     .pinNum = D10_PIN_NUM     };
pin_t D11     = { .port = D11_PORT,     .pinNum = D11_PIN_NUM     };
pin_t D12     = { .port = D12_PORT,     .pinNum = D12_PIN_NUM     };
pin_t TXLED   = { .port = TXLED_PORT,   .pinNum = TXLED_PIN_NUM   };
pin_t RXLED   = { .port = RXLED_PORT,   .pinNum = RXLED_PIN_NUM   };
pin_t LED_13  = { .port = LED_13_PORT,  .pinNum = LED_13_PIN_NUM  };
pin_t SCL_I2C = { .port = SCL_I2C_PORT, .pinNum = SCL_I2C_PIN_NUM };
pin_t SDA_I2C = { .port = SDA_I2C_PORT, .pinNum = SDA_I2C_PIN_NUM };
