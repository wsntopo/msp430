#ifndef MAIN_SLEEP_WAKE_H
#define MAIN_SLEEP_WAKE_H

#include "common.h"

#define	RSSI_CUTOFF	-45
#define PERIOD_MS	1000	// number of milliseconds in a single clock period
#define NUM_PERIODS	4		// "n", the number of total periods in the sleep/listen/shout automata.  Must be an integer, 2 or higher

// states
#define	LISTEN	0
#define	SHOUT	1
#define	SLEEP	2		// whenever checking for sleep state, need to check for >=, not ==
#define IDLE	3	// this one is for the radio...

void shout();
void listen();
void sleep();
uint8_t hear(void);

uint8_t next_state(uint8_t);

#endif
