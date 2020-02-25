/*
 * delay.h
 * 
 * From: https://community.atmel.com/forum/samd21-delay-functions
 */ 

#ifndef __DELAY_H__
#define __DELAY_H__

#define F_CPU 48000000UL // We have a 48MHz Main Clock configured

void delay_usec (uint32_t n);

#endif // __DELAY_H__
