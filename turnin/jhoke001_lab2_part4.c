/*	Author: Jackson Hoke
 *  Partner(s) Name: Jackson Hoke
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0x00; PORTC = 0xFF;
				 PORTD = 0x00;
	unsigned char sum = 0x00;
	unsigned char isBalanced = 0x00;
	unsigned char isOverWeight = 0x00;
	while(1) {
		sum=PINA+PINB+PINC;

		if (PINA+PINB+PINC > 140) isOverWeight=0x01;
		else isOverWeight=0x00;

		if (-80 <= PINA-PINC && PINA-PINC <= 80) isBalanced=0x00;
		else isBalanced=0x01;

		PORTD = ((sum>>2) & 0xFC) | (isBalanced << 1) | isOverWeight;
	}
	return 0;
}
