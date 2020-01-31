/*
 * robot.c
 */ 


#include <asf.h>

#include "robot.h"


#define LED_PORT    PORT_A
#define LED_PIN     17


void init_robot(void)
{
    // Initialize all sub components
    // TODO

    // Configure LED pin
    PORT->Group[LED_PORT].DIR.reg |= 0x1 << LED_PIN;
    PORT->Group[LED_PORT].PINCFG[LED_PIN].reg = 0x0;
}

void run_robot_loop(float current_time)
{
    // TODO: Make work in CONTINUOUS_MODE by using current_time
    
    static uint32_t tickCount = 0;

    tickCount++ ;
    // Toggle LEDs every second (i.e. 1000ms)
    if(tickCount % 1000 == 0){
        // Toggle LED pin output level.
        PORT->Group[LED_PORT].OUTTGL.reg |= 0x1 << LED_PIN;
    }
}
