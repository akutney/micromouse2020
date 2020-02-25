/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>

#if defined(__GNUC__)
void board_init(void) WEAK __attribute__((alias("system_board_init")));
#elif defined(__ICCARM__)
void board_init(void);
#pragma weak board_init = system_board_init
#endif

// ASF module configuration functions
void configure_stdio_serial(void);
void configure_rtc_count(void);
void configure_adc(void);
void configure_i2c_master(void);

void system_board_init(void)
{
  /* This function is meant to contain board-specific initialization code
     * for, e.g., the I/O pins. The initialization can rely on application-
     * specific board configuration, found in conf_board.h.
     */

  configure_stdio_serial();
  configure_rtc_count();
  configure_adc();
  configure_i2c_master();
}

/**
 * After this function, stdio library should work
 */
void configure_stdio_serial(void)
{
  struct usart_config config_usart;
  usart_get_config_defaults(&config_usart);
  config_usart.baudrate = 9600;
  config_usart.mux_setting = USART_RX_1_TX_0_XCK_1;
  config_usart.pinmux_pad0 = PINMUX_PA08C_SERCOM0_PAD0; // TX
  config_usart.pinmux_pad1 = PINMUX_PA09C_SERCOM0_PAD1; // RX/XCK // TODO: Use correct pins
  config_usart.pinmux_pad2 = PINMUX_UNUSED;
  config_usart.pinmux_pad3 = PINMUX_UNUSED;
  stdio_serial_init(&usart_instance, SERCOM0, &config_usart);

  usart_enable(&usart_instance);
  
  printf("\n");
}

void configure_rtc_count(void)
{
  enum status_code status;
  struct rtc_count_config config_rtc_count;
  rtc_count_get_config_defaults(&config_rtc_count);
  config_rtc_count.clear_on_match = false;
  //config_rtc_count.compare_values[0]  = ;
  //config_rtc_count.compare_values[1]  = ;
  config_rtc_count.mode = RTC_COUNT_MODE_32BIT;
  config_rtc_count.prescaler = 1;
  status = rtc_count_init(&rtc_instance, RTC, &config_rtc_count);

  if (status != STATUS_OK)
  {
    while (1)
      ; // Error, stop everything
  }
  // Will be enabled when needed
}

/**
 * Configure the adc module to read 12-bit analog values,
 * - 12-bit is default
 */
void configure_adc(void)
{
  struct adc_config config_adc;
  adc_get_config_defaults(&config_adc);
  config_adc.reference = ADC_REFERENCE_AREFA;
  config_adc.positive_input = ADC_INPUT_START;
  config_adc.negative_input = ADC_NEGATIVE_INPUT_IOGND;
  config_adc.freerunning = false;

  config_adc.pin_scan.offset_start_scan = 0;
  config_adc.pin_scan.inputs_to_scan = ADC_INPUTS_TO_SCAN;

  enum status_code status;
  while ((status = adc_init(&adc_instance, ADC, &config_adc)) != STATUS_OK)
  {
    if (status != STATUS_BUSY)
    {
      while (1)
        ; // Error, stop everything
    }
  }
  
  adc_enable_callback(&adc_instance, ADC_CALLBACK_READ_BUFFER);

  adc_enable(&adc_instance);
}

void configure_i2c_master(void)
{
  /* I2C Master module configuration */
  struct i2c_master_config config_i2c_master;
  i2c_master_get_config_defaults(&config_i2c_master);
  config_i2c_master.buffer_timeout = 65535;
  config_i2c_master.pinmux_pad0 = PINMUX_PA22C_SERCOM3_PAD0; // SDA
  config_i2c_master.pinmux_pad1 = PINMUX_PA23C_SERCOM3_PAD1; // SCL
#ifdef I2C_USE_FAST_MODE
  config_i2c_master.baud_rate = I2C_MASTER_BAUD_RATE_400KHZ;
#endif

  /* Initialize and enable device with config */
  while (i2c_master_init(&i2c_master_instance, SERCOM3, &config_i2c_master) != STATUS_OK)
    ;

  i2c_master_enable(&i2c_master_instance);
}
