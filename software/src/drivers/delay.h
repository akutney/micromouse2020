/*
 * delay.h
 * 
 * From: https://community.atmel.com/forum/samd21-delay-functions
 */ 

#define F_CPU 48000000UL // We have a 48MHz Main Clock configured

#if F_CPU == 8000000UL
__attribute__ ( ( section ( ".ramfunc" ) ) ) void delay_usec ( uint32_t n )
{
  __asm (
  "mydelay: \n"
  " sub  r0, r0, #1 \n"  // 1 cycle
  " nop             \n"  // 1 cycle
  " nop             \n"  // 1 cycle
  " nop             \n"  // 1 cycle
  " nop             \n"  // 1 cycle
  " nop             \n"  // 1 cycle
  " bne  mydelay    \n"  // 2 if taken, 1 otherwise
  );
}
#elif F_CPU == 48000000UL
__attribute__ ( ( section ( ".ramfunc" ) ) ) void delay_usec ( uint32_t n )
{
  __asm (
  "mydelay: \n"
  " mov  r1, #15    \n"  // 1 cycle
  "mydelay1: \n"
  " sub  r1, r1, #1 \n"  // 1 cycle
  " bne  mydelay1    \n" // 2 if taken, 1 otherwise
  " sub  r0, r0, #1 \n"  // 1 cycle
  " bne  mydelay    \n"  // 2 if taken, 1 otherwise
  );
}
#else
#error F_CPU is not defined
#endif