/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define TX_RX_LED_INIT	DDRB |= (1<<0) // , DDRD |= (1<<5)
/*
#define TXLED0			PORTD |= (1<<5)
#define TXLED1			PORTD &= ~(1<<5)
*/
#define RXLED0			PORTB |= (1<<0)
#define RXLED1			PORTB &= ~(1<<0)
#define TXLED0			RXLED0
#define TXLED1			RXLED1

static const uint8_t SDA = 3;
static const uint8_t SCL = 2;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 24; // Battery Status

static const uint8_t BATTERY = 6;

const static uint8_t RUN_SW = 25;
static const uint8_t SPEAKER = 23;

// Motors
static const uint8_t M0_EN = 22;
static const uint8_t M0_D0 = 20;
static const uint8_t M0_D1 = 21;

static const uint8_t M1_EN = 3;
static const uint8_t M1_D0 = 4;
static const uint8_t M1_D1 = 8;

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define NOT_ON_TIMER 0
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER2  5
#define TIMER2A 6
#define TIMER2B 7

#define TIMER3A 8
#define TIMER3B 9
#define TIMER3C 10
#define TIMER4A 11
#define TIMER4B 12
#define TIMER4C 13

//##RG.Labs.20110305 begin
// Added the definitions for the MEGA32U4

#define TIMER4D 14
#define TIMER5A 15
#define TIMER5B 16
#define TIMER5C 17

//#define TIMER5A 14
//#define TIMER5B 15
//#define TIMER5C 16

//##RG.Labs.20110305 end

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
const static uint8_t SS   = 53;
const static uint8_t MOSI = 51;
const static uint8_t MISO = 50;
const static uint8_t SCK  = 52;
#else
const static uint8_t SS   = 10;
const static uint8_t MOSI = 11;
const static uint8_t MISO = 12;
const static uint8_t SCK  = 13;
#endif

//##RG.Labs.20110305 begin
// Added for DuinoBot V1.XX pins
extern const uint8_t PROGMEM analog_pin_to_adc_channel_PGM[];
extern const uint8_t PROGMEM analog_channel_to_adc_mux_PGM[];
//##RG.Labs.20110305 end


// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.
extern const uint16_t PROGMEM port_to_mode_PGM[];
extern const uint16_t PROGMEM port_to_input_PGM[];
extern const uint16_t PROGMEM port_to_output_PGM[];

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_bit_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
// 
// These perform slightly better as macros compared to inline functions
//
#define digitalPinToPort(P) ( pgm_read_byte( digital_pin_to_port_PGM + (P) ) )
#define digitalPinToBitMask(P) ( pgm_read_byte( digital_pin_to_bit_mask_PGM + (P) ) )
#define digitalPinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
#define analogInPinToBit(P) (P)
#define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portModeRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_mode_PGM + (P))) )

//##RG.Labs.20110305 begin
#define analogPinToAdcChannel(P) ( pgm_read_byte( analog_pin_to_adc_channel_PGM + (P) ) )
#define analogChannelToMux(P) ( pgm_read_byte( analog_channel_to_adc_mux_PGM + (P) ) )
//##RG.Labs.20110305 end

#endif
