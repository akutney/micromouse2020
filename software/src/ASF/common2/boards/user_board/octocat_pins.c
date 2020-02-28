/*
 * octocat_pins.c
 */ 

#include "octocat_pins.h"


/* Pin Definitions directly from schematic (rev1.pdf) */
/* https://github.com/ksurct/micromouse2020/blob/master/pcb/Rev%201.pdf */

// Clock Pins
#define XIN32_PORT          PORT_A
#define XIN32_PIN_NUM       0
#define XOUT32_PORT         PORT_A
#define XOUT32_PIN_NUM      1
#define XIN_PORT            PORT_A
#define XIN_PIN_NUM         14
#define XOUT_PORT           PORT_A
#define XOUT_PIN_NUM        15

// ADC Pins
#define VREFA_PORT          PORT_A
#define VREFA_PIN_NUM       3
#define PHOTO1_PORT         PORT_A
#define PHOTO1_PIN_NUM      4
#define PHOTO2_PORT         PORT_A
#define PHOTO2_PIN_NUM      5
#define PHOTO3_PORT         PORT_A
#define PHOTO3_PIN_NUM      6
#define PHOTO4_PORT         PORT_A
#define PHOTO4_PIN_NUM      7
#define PHOTO5_PORT         PORT_A
#define PHOTO5_PIN_NUM      8
#define PHOTO6_PORT         PORT_A
#define PHOTO6_PIN_NUM      9
#define PHOTO7_PORT         PORT_A
#define PHOTO7_PIN_NUM      10
#define PHOTO8_PORT         PORT_B
#define PHOTO8_PIN_NUM      9

// Bluetooth Serial Pins
#define BT_STATE_PORT       PORT_A
#define BT_STATE_PIN_NUM    11
#define BT_TX_PORT          PORT_A
#define BT_TX_PIN_NUM       12
#define BT_RX_PORT          PORT_A
#define BT_RX_PIN_NUM       13
#define BT_EN_PORT          PORT_A
#define BT_EN_PIN_NUM       16

// Motor Encoders Pins
#define ENCODER_1A_PORT     PORT_A
#define ENCODER_1A_PIN_NUM  21
#define ENCODER_1B_PORT     PORT_A
#define ENCODER_1B_PIN_NUM  24
#define ENCODER_2A_PORT     PORT_A
#define ENCODER_2A_PIN_NUM  18
#define ENCODER_2B_PORT     PORT_A
#define ENCODER_2B_PIN_NUM  17
#define ENCODER_3A_PORT     PORT_A
#define ENCODER_3A_PIN_NUM  20
#define ENCODER_3B_PORT     PORT_A
#define ENCODER_3B_PIN_NUM  19
#define ENCODER_4A_PORT     PORT_B
#define ENCODER_4A_PIN_NUM  23
#define ENCODER_4B_PORT     PORT_B
#define ENCODER_4B_PIN_NUM  22

// IMU Pins
#define IMU_INT_PORT        PORT_B
#define IMU_INT_PIN_NUM     10

// I2C Pins
#define SDA_PORT            PORT_A
#define SDA_PIN_NUM         22
#define SCL_PORT            PORT_A
#define SCL_PIN_NUM         23

// Debugging Pins
#define SWDCLK_PORT         PORT_A
#define SWDCLK_PIN_NUM      30
#define SWDIO_PORT          PORT_A
#define SWDIO_PIN_NUM       31

pin_t XIN32       = { .port = XIN32_PORT,       .pinNum = XIN32_PIN_NUM       };
pin_t XOUT32      = { .port = XOUT32_PORT,      .pinNum = XOUT32_PIN_NUM      };
pin_t XIN         = { .port = XIN_PORT,         .pinNum = XIN_PIN_NUM         };
pin_t XOUT        = { .port = XOUT_PORT,        .pinNum = XOUT_PIN_NUM        };
pin_t VREFA       = { .port = VREFA_PORT,       .pinNum = VREFA_PIN_NUM       };
pin_t PHOTO1      = { .port = PHOTO1_PORT,      .pinNum = PHOTO1_PIN_NUM      };
pin_t PHOTO2      = { .port = PHOTO2_PORT,      .pinNum = PHOTO2_PIN_NUM      };
pin_t PHOTO3      = { .port = PHOTO3_PORT,      .pinNum = PHOTO3_PIN_NUM      };
pin_t PHOTO4      = { .port = PHOTO4_PORT,      .pinNum = PHOTO4_PIN_NUM      };
pin_t PHOTO5      = { .port = PHOTO5_PORT,      .pinNum = PHOTO5_PIN_NUM      };
pin_t PHOTO6      = { .port = PHOTO6_PORT,      .pinNum = PHOTO6_PIN_NUM      };
pin_t PHOTO7      = { .port = PHOTO7_PORT,      .pinNum = PHOTO7_PIN_NUM      };
pin_t PHOTO8      = { .port = PHOTO8_PORT,      .pinNum = PHOTO8_PIN_NUM      };
pin_t BT_STATE    = { .port = BT_STATE_PORT,    .pinNum = BT_STATE_PIN_NUM    };
pin_t BT_TX       = { .port = BT_TX_PORT,       .pinNum = BT_TX_PIN_NUM       };
pin_t BT_RX       = { .port = BT_RX_PORT,       .pinNum = BT_RX_PIN_NUM       };
pin_t BT_EN       = { .port = BT_EN_PORT,       .pinNum = BT_EN_PIN_NUM       };
pin_t ENCODER_1A  = { .port = ENCODER_1A_PORT,  .pinNum = ENCODER_1A_PIN_NUM  };
pin_t ENCODER_1B  = { .port = ENCODER_1B_PORT,  .pinNum = ENCODER_1B_PIN_NUM  };
pin_t ENCODER_2A  = { .port = ENCODER_2A_PORT,  .pinNum = ENCODER_2A_PIN_NUM  };
pin_t ENCODER_2B  = { .port = ENCODER_2B_PORT,  .pinNum = ENCODER_2B_PIN_NUM  };
pin_t ENCODER_3A  = { .port = ENCODER_3A_PORT,  .pinNum = ENCODER_3A_PIN_NUM  };
pin_t ENCODER_3B  = { .port = ENCODER_3B_PORT,  .pinNum = ENCODER_3B_PIN_NUM  };
pin_t ENCODER_4A  = { .port = ENCODER_4A_PORT,  .pinNum = ENCODER_4A_PIN_NUM  };
pin_t ENCODER_4B  = { .port = ENCODER_4B_PORT,  .pinNum = ENCODER_4B_PIN_NUM  };
pin_t IMU_INT     = { .port = IMU_INT_PORT,     .pinNum = IMU_INT_PIN_NUM     };
pin_t SDA         = { .port = SDA_PORT,         .pinNum = SDA_PIN_NUM         };
pin_t SCL         = { .port = SCL_PORT,         .pinNum = SCL_PIN_NUM         };
pin_t SWDCLK      = { .port = SWDCLK_PORT,      .pinNum = SWDCLK_PIN_NUM      };
pin_t SWDIO       = { .port = SWDIO_PORT,       .pinNum = SWDIO_PIN_NUM       };
