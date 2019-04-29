/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>
#include "wiring_private.h"

// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
// void initVariant() __attribute__((weak));
//void initVariant() { }

void initVariant() {
	sei();

	// BECAREFULL
	// Timer/Counter0, 1, and 3 share the same prescaler module, but the Timer/Counters can have different prescaler settings.
	
	//=====================================================================
	// Timer 0 Delay functions y OC0A como salida de PWM en pin 9
	//=====================================================================
		
	// on the ATmega168, timer 0 is also used for fast hardware pwm
	// (using phase-correct PWM would mean that timer 0 overflowed half as often
	// resulting in different millis() behavior on the ATmega8 and ATmega168)	
	sbi(TCCR0A, WGM01);
	sbi(TCCR0A, WGM00);

	// set timer 0 prescale factor to 64	
	cbi(TCCR0B, CS02);
	sbi(TCCR0B, CS01);
	sbi(TCCR0B, CS00);

	// enable timer 0 overflow interrupt
	sbi(TIMSK0, TOIE0);		
	
	//----Configuracion para OC0A-----
	// El WGM0X ya esta definido por que lo usa arduino para el timer
	//sbi(TCCR0A,COM0A1);
	cbi(TCCR0A,COM0A0);
	cbi(TCCR0B,WGM02);
	
		
	//=====================================================================
	//Timer 3 PIN 6 only OC3A
	//=====================================================================

	// se libera el timer3 para compatibilizar el core con la RGLib
	// (se pierde la funcion PWM del PIN6)
	
	//OC4D pin connected
	//nOC4D pin Disconnected
	//sbi(TCCR3A,COM3A1);
	//cbi(TCCR3A,COM3A0);
	
	//cbi(TCCR3B, WGM33);
	//cbi(TCCR3B, WGM32);
	//cbi(TCCR3A, WGM31);
	//sbi(TCCR3A, WGM30);	

	//En ppo esta apagado el pwm
	//cbi(TCCR3B,CS43);
	//cbi(TCCR3B,CS42);
	//cbi(TCCR3B,CS41);
	//sbi(TCCR3B,CS40);	
	
	//=====================================================================
	//Timer 4 Motors PWM (A & B) y GP TIMER D
	//=====================================================================
		
	//OC4A pin connected
	//nOC4A pin Disconnected
	//sbi(TCCR4A,COM4A1);
	cbi(TCCR4A,COM4A0);
	
	//OC4B pin connected
	//nOC4B pin Disconnected
	//sbi(TCCR4A,COM4B1); 
	cbi(TCCR4A,COM4B0);
	
	//Enable PWM en A y B
	//Phase and Frequency Correct PWM
	sbi(TCCR4A,PWM4A);
	sbi(TCCR4A,PWM4B);
	
	//Prescaler --> Freq sea 31.35Khz.
	
	//En ppo esta apagado el pwm
	cbi(TCCR4B,CS43);
	cbi(TCCR4B,CS42);
	cbi(TCCR4B,CS41);
	sbi(TCCR4B,CS40);	
		
	//--------------------------------------------------------------------------------------
	// Timer 4D para el pin 5
	
	//OC4D pin connected
	//nOC4D pin Disconnected
	//sbi(TCCR4D,COM4D1);
	cbi(TCCR4D,COM4D0);
	
	sbi(TCCR4C,PWM4D);
		
	//Phase and Frequency Correct PWM
	cbi(TCCR4D,WGM41);
	sbi(TCCR4D,WGM40);
	
	//=====================================================================
	// A/D
	//=====================================================================

	// set a2d prescale factor to 128
	// 16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
	// XXX: this will not work properly for other clock speeds, and
	// this code should use F_CPU to determine the prescale factor.
	sbi(ADCSRA, ADPS2);
	sbi(ADCSRA, ADPS1);
	sbi(ADCSRA, ADPS0);

	// enable a2d conversions
	sbi(ADCSRA, ADEN);

    // Wait for reset
    /*
    DDRD |= 1 << 1;
    PORTB |= 1 << 1;
    while (!PINE & (1 << 2));
    PORTB &= ~(1 << 1);
    DDRD &= ~(1 << 1);
    */
}

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	init();

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

