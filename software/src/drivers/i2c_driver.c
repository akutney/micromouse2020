/*
 * i2c_driver.c
 */

#include <asf.h>
#include <error.h>

#include "i2c_driver.h"

bool I2C_DRIVER_ENABLED = true;

typedef struct
{
  bool enabled;
  int8_t address;
  write_callback_t write_callback;
  read_callback_t read_callback;
} registered_callback_t;

// Privates Globals
bool i2c_driver_initialized = false;

#define MAX_NUM_OF_I2C_ADDRESSES 3
registered_callback_t callbacks[MAX_NUM_OF_I2C_ADDRESSES];
int8_t callbacks_idx;

// Function Prototypes
int validate_address(int8_t address);
void i2c_write_complete_callback(struct i2c_master_module *const module);
void i2c_read_complete_callback(struct i2c_master_module *const module);

int init_i2c_driver(void)
{
  // Don't initialize twice
  if (i2c_driver_initialized)
  {
    return RETURN_SUCCESS;
  }

  for (int i = 0; i < MAX_NUM_OF_I2C_ADDRESSES; i++)
  {
    callbacks[i].enabled = false;
    callbacks[i].address = 0x00;
    callbacks[i].write_callback = NULL;
    callbacks[i].read_callback = NULL;
  }

  // Register and enable Underlying callbacks
  // Write
  i2c_master_register_callback(
    &i2c_master_instance,
    i2c_write_complete_callback,
    I2C_MASTER_CALLBACK_WRITE_COMPLETE);

  i2c_master_enable_callback(
    &i2c_master_instance,
    I2C_MASTER_CALLBACK_WRITE_COMPLETE);
  
  // Read
  i2c_master_register_callback(
    &i2c_master_instance,
    i2c_read_complete_callback,
    I2C_MASTER_CALLBACK_READ_COMPLETE);

  i2c_master_enable_callback(
    &i2c_master_instance,
    I2C_MASTER_CALLBACK_READ_COMPLETE);
   
  
  callbacks_idx = 0;
  i2c_driver_initialized = true;
  return RETURN_SUCCESS;
}

int register_i2c_callbacks(
    int8_t address,
    write_callback_t write_callback,
    read_callback_t read_callback)
{
  // Validate arguments
  if (address < 0) {
    THROW_ERR("register_i2c_callbacks", EINVAL);
  }
  if (callbacks_idx >= MAX_NUM_OF_I2C_ADDRESSES) {
    THROW_ERR("register_i2c_callbacks", ENOSR);
  }

  callbacks[callbacks_idx].enabled = true;
  callbacks[callbacks_idx].address = address;
  callbacks[callbacks_idx].write_callback = write_callback;
  callbacks[callbacks_idx].read_callback = read_callback;

  callbacks_idx++;

  return RETURN_SUCCESS;
}

int write_reg8(int8_t address, uint8_t reg, uint8_t val)
{
  THROW_ERR("write_reg8", ENOSYS);
}

int read_reg8(int8_t address, uint8_t reg, uint8_t *val)
{
  THROW_ERR("read_reg8", ENOSYS);
}

// Private functions
int validate_address(int8_t address)
{
  if (address < 0)
  {
    THROW_ERR("validate_address", EINVAL);
  }
  return RETURN_SUCCESS;
}

void i2c_write_complete_callback(struct i2c_master_module *const module)
{
  
}

void i2c_read_complete_callback(struct i2c_master_module *const module)
{

}
