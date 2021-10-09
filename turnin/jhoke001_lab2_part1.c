/*	Author: Jackson Hoke
 *  Partner(s) Name: Jackson Hoke
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 1
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpC = 0x00;
	while(1) {
			// Read input
			tmpA = PINA & 0x01; //holds A0 value
			tmpB = PINA & 0x02; //hold A1 value
			if (tmpA==0x01 && tmpB==0x00) {
				tmpC=0x01;
			} else {
				tmpC=0x00;
			}
		// Write output
		PORTB = tmpC;	
	}
	return 0;
}
