/*	Author: root
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
				 PORTC = 0x00;
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char cntavail = 0x00;
	unsigned char isFull = 0x00;
	while(1) {
			// Read input
			tmpA = PINA & 0x01; //holds A0 value
			tmpB = PINA & 0x02; //hold A1 value
			tmpC = PINA & 0x04;
			tmpD = PINA & 0x08;
			cntavail=0x00;
			isFull=0x00;
			if (tmpA==0x00) cntavail++;
			if (tmpB==0x00) cntavail++;
			if (tmpC==0x00) cntavail++;
			if (tmpD==0x00) cntavail++;
			if (cntavail==0) isFull=0x01;
		// Write output
		PORTC=cntavail | (isFull<<7);
	}
	return 0;
}
