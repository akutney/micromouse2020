/*
 * interrupts.c
 */ 

#include <asf.h>

#include "interrupts.h"

// Returns state from before
bool disable_interrupts() {
  bool to_return = Is_global_interrupt_enabled();
  Disable_global_interrupt();
  return to_return;
}

// Returns state from before
bool enable_interrupts() {
  bool to_return = Is_global_interrupt_enabled();
  Enable_global_interrupt();
  return to_return;
}

void set_interrupts(bool state) {
  if (state) {
    Enable_global_interrupt();
  } else {
    Disable_global_interrupt();
  }
}
