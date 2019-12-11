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
#  pragma weak board_init=system_board_init
#endif

void configure_usart(void);
void configure_stdio_serial(void);
void configure_rtc_count(void);

void system_board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */

    configure_stdio_serial();
}

void configure_usart(void)
{
    struct usart_config config_usart;
    usart_get_config_defaults(&config_usart);
    config_usart.baudrate = 38400;
    config_usart.mux_setting = USART_RX_1_TX_0_XCK_1;
    config_usart.pinmux_pad0 = PINMUX_PA08C_SERCOM0_PAD0; // TX
    config_usart.pinmux_pad1 = PINMUX_PA09C_SERCOM0_PAD1; // RX/XCK
    config_usart.pinmux_pad2 = PINMUX_UNUSED;
    config_usart.pinmux_pad3 = PINMUX_UNUSED;
    while (usart_init(&usart_instance, SERCOM0, &config_usart) != STATUS_OK);
        
    usart_enable(&usart_instance);
}

void configure_stdio_serial(void)
{
    struct usart_config config_usart;
    usart_get_config_defaults(&config_usart);
    config_usart.baudrate = 38400;
    config_usart.mux_setting = USART_RX_1_TX_0_XCK_1;
    config_usart.pinmux_pad0 = PINMUX_PA08C_SERCOM0_PAD0; // TX
    config_usart.pinmux_pad1 = PINMUX_PA09C_SERCOM0_PAD1; // RX/XCK
    config_usart.pinmux_pad2 = PINMUX_UNUSED;
    config_usart.pinmux_pad3 = PINMUX_UNUSED;
    stdio_serial_init(&usart_instance, SERCOM0, &config_usart);
    
    usart_enable(&usart_instance);
}

void configure_rtc_count(void)
{
    // TODO: Configure what clock goes to rtc module
    
    enum status_code status;
    struct rtc_count_config config_rtc_count;
    rtc_count_get_config_defaults(&config_rtc_count);
    config_rtc_count.clear_on_match     = false;
    //config_rtc_count.compare_values[0]  = ;
    //config_rtc_count.compare_values[1]  = ;
    config_rtc_count.mode               = RTC_COUNT_MODE_32BIT;
    config_rtc_count.prescaler          = 1;
    status = rtc_count_init(&rtc_instance, RTC, &config_rtc_count);
   
    if (status == STATUS_OK) {
        rtc_count_enable(&rtc_instance);
    }
    
    // use rtc_tamper_get_stamp(&rtc_instance) to read the count value
}