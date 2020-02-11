/*
 * interrupts.h
 */ 

#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include <asf.h>

// Returns state from before
bool disable_interrupts(void);

// Returns state from before
bool enable_interrupts(void);

// Set interrupts to the given state
void set_interrupts(bool state);

#endif /* __INTERRUPTS_H__ */
