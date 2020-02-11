/*
 * interrupts.h
 */ 

#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include <asf.h>

// Returns state from before
inline bool disable_interrupts();

// Returns state from before
inline bool enable_interrupts();

// Set interrupts to the given state
inline void set_interrupts(bool state);

#endif /* __INTERRUPTS_H__ */
