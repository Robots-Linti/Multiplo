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
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// Workaround for wrong definitions in "iom32u4.h".
// This should be fixed in the AVR toolchain.
#undef UHCON
#undef UHINT
#undef UHIEN
#undef UHADDR
#undef UHFNUM
#undef UHFNUML
#undef UHFNUMH
#undef UHFLEN
#undef UPINRQX
#undef UPINTX
#undef UPNUM
#undef UPRST
#undef UPCONX
#undef UPCFG0X
#undef UPCFG1X
#undef UPSTAX
#undef UPCFG2X
#undef UPIENX
#undef UPDATX
#undef TCCR2A
#undef WGM20
#undef WGM21
#undef COM2B0
#undef COM2B1
#undef COM2A0
#undef COM2A1
#undef TCCR2B
#undef CS20
#undef CS21
#undef CS22
#undef WGM22
#undef FOC2B
#undef FOC2A
#undef TCNT2
#undef TCNT2_0
#undef TCNT2_1
#undef TCNT2_2
#undef TCNT2_3
#undef TCNT2_4
#undef TCNT2_5
#undef TCNT2_6
#undef TCNT2_7
#undef OCR2A
#undef OCR2_0
#undef OCR2_1
#undef OCR2_2
#undef OCR2_3
#undef OCR2_4
#undef OCR2_5
#undef OCR2_6
#undef OCR2_7
#undef OCR2B
#undef OCR2_0
#undef OCR2_1
#undef OCR2_2
#undef OCR2_3
#undef OCR2_4
#undef OCR2_5
#undef OCR2_6
#undef OCR2_7

#define NUM_DIGITAL_PINS  26
#define NUM_ANALOG_INPUTS 7

// There are no TX and RX dedicated LEDs on DuinoBot v1.2
#define TX_RX_LED_INIT	{}
#define TXLED0			{}
#define TXLED1			{}
#define RXLED0			{}
#define RXLED1			{}

#define PIN_WIRE_SDA         (7)
#define PIN_WIRE_SCL         (2)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 13
// There are no TX and RX dedicated LEDs on DuinoBot v1.2
//#define LED_BUILTIN_RX 13
//#define LED_BUILTIN_TX 13

// Map SPI port to 'new' pins D14..D17
#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// Mapping of analog pins as digital I/O
// A6-A11 share with digital pins
#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (24) // Battery Status

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;

static const uint8_t BATTERY = PIN_A6;
static const uint8_t RUN_SW = 25;
static const uint8_t SPEAKER = 23;

// Motors
static const uint8_t M0_EN = 22;
static const uint8_t M0_D0 = 20;
static const uint8_t M0_D1 = 21;

static const uint8_t M1_EN = 3;
static const uint8_t M1_D0 = 4;
static const uint8_t M1_D1 = 8;


#define digitalPinToPCICR(p)    (((p) == 3 || ((p) >= 9 && (p) <= 13) || (p) == 20 || (p) == 23) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) 0
#define digitalPinToPCMSK(p)    (((p) == 3 || ((p) >= 9 && (p) <= 13) || (p) == 20 || (p) == 23) ? (&PCMSK0) : ((uint8_t *)0))
#define digitalPinToPCMSKbit(p) ((p) == 3 ? 6 : ((p) == 9 ? 7 : ((p) == 10 ? 0 : ((p) == 11 ? 2 : ((p) == 12 ? 3 : ((p) == 13 ? 1 : ((p) == 20 ? 4 : ((p) == 23 ? 5 : -1))))))))

//	__AVR_ATmega32U4__ has an unusual mapping of pins to channels
extern const uint8_t PROGMEM analog_pin_to_channel_PGM[];
#define analogPinToChannel(P)  ( pgm_read_byte( analog_pin_to_channel_PGM + (P) ) )

#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 22)

#define digitalPinToInterrupt(p) ((p) == 0 ? 2 : ((p) == 1 ? 3 : ((p) == 2 ? 0 : ((p) == 7 ? 1 : ((p) == 21 ? 4 : NOT_AN_INTERRUPT)))))

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATMEGA32U4 / DUINOBOT 1.2
//
// D0				PD2					RXD1/INT2
// D1				PD3					TXD1/INT3
// D2				PD0					OC0B/SCL/INT0
// D3#				PB6		PWM1	OC1B/0c4B/ADC13/PCINT6
// D4				PD5					XCK1/CTS
// D5#				PD7		PWM2		#OC4D/ADC10
// D6#				PC6		PWM3		OC3A/#OC4A
// D7				PD1					SDA/INT1
//
// D8		A11		PD6					T1/#OC4D/ADC9
// D9#				PB7		PWM8/16		0C0A/OC1C/#RTS/PCINT7
// D10				PB0		SS			RXLED,SS/PCINT0
// D11				PB2		MOSI		MOSI,PCINT2
// D12				PB3		MISO		MISO,PCINT3
// D13				PB1		SCK			SCK,PCINT1
//
// A0		D14		PF7					ADC7
// A1		D15		PF6					ADC6
// A2		D16 	PF5					ADC5
// A3		D17 	PF4					ADC4
// A4		D18		PF1					ADC1
// A5		D19 	PF0					ADC0
//
// HWB				PE2					HWB

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, // D0 - PD2
	PD,	// D1 - PD3
	PD, // D2 - PD0
	PB,	// D3 - M1_EN - PB6
	PD,	// D4 - M1_D0 - GREEN_LED - PD5
	PD, // D5 - PD7
	PC, // D6 - PC6
	PD, // D7 - PD1
	
	PD, // D8 - M1_D1 - RED_LED - PD6
	PB,	// D9 - PB7
	PB, // D10 - PB0
	PB,	// D11 - PB2
	PB, // D12 - PB3
	PB, // D13 - PB1
	
	PF,	// D14 - A0 - PF7
	PF,	// D15 - A1 - PF6
	PF,	// D16 - A2 - PF5
	PF,	// D17 - A3 - PF4
	PF,	// D18 - A4 - PF1
	PF, // D19 - A5 - PF0

	PB, // D20 - M0_D0  - PB4
	PE, // D21 - M0_D1 - PE6
	PC, // D22 - M0_EN - PC7

	PB, // D23 / SPEAKER - PB5
	PD, // D24 / A6 - BATTERY - PD4
	PE, // D25 / HWB - RUN_SW - PE2
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(2), // D0 - PD2
	_BV(3),	// D1 - PD3
	_BV(0), // D2 - PD0
	_BV(6),	// D3 - PB6
	_BV(5),	// D4 - PD5
	_BV(7), // D5 - PD7
	_BV(6), // D6 - PC6
	_BV(1), // D7 - PD1
	
	_BV(6), // D8 - PD6
	_BV(7),	// D9 - PB7
	_BV(0), // D10 - PB0
	_BV(2),	// D11 - PB2
	_BV(3), // D12 - PB3
	_BV(1), // D13 - PB1
	
	_BV(7),	// D14 - A0 - PF7
	_BV(6), // D15 - A1 - PF6
	_BV(5), // D16 - A2 - PF5
	_BV(4), // D17 - A3 - PF4
	_BV(1), // D18 - A4 - PF1
	_BV(0), // D19 - A5 - PF0
	
	_BV(4), // D20 / M0_D0 - PB4
	_BV(6), // D21 / M0_D1 - PE6
	_BV(7), // D22 / M0_EN - PC7
	
	_BV(5), // D23 / SPEAKER - PB5
	_BV(4), // D24 / A6 - BATTERY - PD4
	_BV(2), // D25 / HWB - RUN_SW - PE2
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER4B,		/* 3 */ // TIMER1B
	NOT_ON_TIMER,
	TIMER4D,		/* 5 */
	TIMER3A,		/* 6 */ // ~TIMER4A
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0A,		/* 9 */ // TIMER1C
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER4A,		/* 22 */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

const uint8_t PROGMEM analog_pin_to_channel_PGM[] = {
	7,	// A0				PF7					ADC7
	6,	// A1				PF6					ADC6
	5,	// A2				PF5					ADC5
	4,	// A3				PF4					ADC4
	1,	// A4				PF1					ADC1
	0,	// A5				PF0					ADC0
	8,	// A6				PD4					ADC8
};

#endif /* ARDUINO_MAIN */

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR        Serial
#define SERIAL_PORT_USBVIRTUAL     Serial
#define SERIAL_PORT_HARDWARE       Serial1
#define SERIAL_PORT_HARDWARE_OPEN  Serial1

// Alias SerialUSB to Serial
#define SerialUSB SERIAL_PORT_USBVIRTUAL

#endif /* Pins_Arduino_h */
