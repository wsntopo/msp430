#include "msp430g2553.h"

// takes a 16-bit value, and uses the bottom 12 bits to make a triggering pattern.
// best if several of the bits change on each transition.
// order is 3 LSB, then next 3, etc.
// always ends with trigger lines low.
// One way to construct is, e.g., 0b101 + (0b110 << 3) + (0b001 << 6) + (0b111 << 9)
void trigger(int pattern)
{
	int pat;
	short int i;

	pat = pattern;
	P2DIR |= 0x38;  // 0b00111000 set bits 3, 4, 5 to output
	for (i = 0; i < 4; i++) {
		// first mask bits 3, 4, 5, then mask lower 3 bits in pat and move them over into 3,4,5
		P2OUT = (P2OUT & (~0x38)) + ((pat & 0x7) << 3);
		pat = pat >> 3;
	}
	P2OUT &= ~0x38;	// set bits 3, 4, 5 low
}
