/*
 * i2c_driver.c
 */

#include <asf.h>
#include <error.h>

#include "i2c_driver.h"

bool I2C_DRIVER_ENABLED = true;

// Privates Globals
struct i2c_master_packet write_packet;
struct i2c_master_packet read_packet;

uint8_t write_buffer[3];
uint8_t read_buffer[2];

// Function Prototypes
int validate_address(int8_t address);
void lock(void);
void unlock(void);

int init_i2c_driver(void)
{
  return RETURN_SUCCESS;
}

int write_reg8(int8_t address, uint8_t reg, uint8_t val)
{
  lock();
  
  // Construct write packet
  write_buffer[0] = reg;
  write_buffer[1] = val;

  write_packet.address     = address;
  write_packet.data_length = 2;
  write_packet.data        = write_buffer;

  i2c_master_write_packet_wait(&i2c_master_instance, &write_packet);

  unlock();
  
  return RETURN_SUCCESS;
}

int write_reg16(int8_t address, uint8_t reg, uint16_t val)
{
  lock();

  // Construct write packet
  write_buffer[0] = reg;
  write_buffer[1] = (val & 0xFF00) >> 8;
  write_buffer[2] = (val & 0x00FF);

  write_packet.address     = address;
  write_packet.data_length = 3;
  write_packet.data        = write_buffer;
  
  i2c_master_write_packet_wait(&i2c_master_instance, &write_packet);

  unlock();
  
  return RETURN_SUCCESS;
}

int read_reg8(int8_t address, uint8_t reg, uint8_t *val)
{
  lock();

  // Construct write packet
  write_buffer[0] = reg;

  write_packet.address     = address;
  write_packet.data_length = 1;
  write_packet.data        = write_buffer;

  i2c_master_write_packet_wait(&i2c_master_instance, &write_packet);

  // Construct read packet
  read_packet.address     = address;
  read_packet.data_length = 1;
  read_packet.data        = read_buffer;
    
  i2c_master_read_packet_wait(&i2c_master_instance, &read_packet);

  (*val) = read_buffer[0];

  unlock();
    
  return RETURN_SUCCESS;
}

int read_reg16(int8_t address, uint8_t reg, uint16_t *val)
{
  lock();

  // Construct write packet
  write_buffer[0] = reg;

  write_packet.address     = address;
  write_packet.data_length = 1;
  write_packet.data        = write_buffer;

  i2c_master_write_packet_wait(&i2c_master_instance, &write_packet);

  // Construct read packet
  read_packet.address     = address;
  read_packet.data_length = 1;
  read_packet.data        = read_buffer;
    
  i2c_master_read_packet_wait(&i2c_master_instance, &read_packet);

  (*val) = ((uint16_t)read_buffer[0] << 8) + read_buffer[1];
  
  unlock();
    
  return RETURN_SUCCESS;
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

void lock(void)
{
  while(i2c_master_lock(&i2c_master_instance) == STATUS_BUSY);
}

void unlock(void)
{
  i2c_master_unlock(&i2c_master_instance);
}
