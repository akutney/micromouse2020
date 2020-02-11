/*
 * interrupts.h
 */ 


#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__


#include <asf.h>


// Returns state from before
inline bool disable_interrupts() {
  bool to_return = Is_global_interrupt_enabled();
  Disable_global_interrupt();
  return to_return;
}

// Returns state from before
inline bool enable_interrupts() {
  bool to_return = Is_global_interrupt_enabled();
  Enable_global_interrupt();
  return to_return;
}

inline void set_interrupts(bool state) {
  if (state) {
    Enable_global_interrupt();
  }
}


#endif /* __INTERRUPTS_H__ */
