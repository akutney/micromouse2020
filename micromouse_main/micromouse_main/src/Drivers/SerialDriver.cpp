/* 
 * SerialDriver.cpp
 *
 * Author: Dylan Staatz
 */


#include "SerialDriver.h"

#include "sam.h"
#include "../Types/Ints.h"

Sercom * const SERCOM[SERCOM_INST_NUM] = SERCOM_INSTS;

SerialDriver::SerialDriver(uint8_t instance) :
instance_(instance)
{   
    // Configure IO with PORT
    // TODO
    
    // Configure Initialization of SERCOM (page 443)
    SERCOM[instance]->USART.CTRLA.reg |= SERCOM_USART_CTRLA_MODE_USART_EXT_CLK;
    SERCOM[instance]->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
    SERCOM[instance]->USART.CTRLA.reg &= ~SERCOM_USART_CTRLA_CMODE;
    SERCOM[instance]->USART.CTRLA.reg |= SERCOM_USART_CTRLA_RXPO(0x0);
    SERCOM[instance]->USART.CTRLA.reg |= SERCOM_USART_CTRLA_TXPO(0x0);
    SERCOM[instance]->USART.CTRLB.reg |= SERCOM_USART_CTRLB_CHSIZE(0x0);
    SERCOM[instance]->USART.CTRLA.reg &= ~SERCOM_USART_CTRLA_DORD;
    // If needed: parity goes here
    SERCOM[instance]->USART.CTRLB.reg &= ~SERCOM_USART_CTRLB_SBMODE;
    
    // Configure baud rate
    
    
    // Enable
    SERCOM[instance]->USART.CTRLB.reg |= SERCOM_USART_CTRLB_RXEN;
    SERCOM[instance]->USART.CTRLB.reg |= SERCOM_USART_CTRLB_TXEN;
    

}

// default destructor
SerialDriver::~SerialDriver()
{
    
}

// Prints a '\0' terminated string to some console
void Print(char * str)
{

}

// Prints a '\0' terminated string to some console
// and starts a newline
void Println(char * str)
{

}
