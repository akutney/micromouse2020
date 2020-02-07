/*
 * controller.c
 */

#include <error.h>

#include "controller.h"

int controller(
  const robot_state_t *const current_state,
  const robot_state_t *const desired_state,
  motor_outputs_t *const outputs)
{
  THROW_ERR("guidance", ENOSYS);
}