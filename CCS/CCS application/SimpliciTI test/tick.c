#include "tick.h"

volatile unsigned int tick;
volatile unsigned int tock;
volatile uint32_t local_time;
volatile uint16_t tick_period;

void initTick(uint16_t period)
{
	tick_period = period;
	resetTick();
	tock = 0;
	resetLocalTime();
}

uint8_t getTick()
{
	return tick;
}

void resetTick()
{
	tick = 0;
}

uint32_t getLocalTime()
{
	return local_time;
}

void resetLocalTime()
{
	local_time = 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void timerA0_isr(void)
{
	tock++;
	local_time++;

	if(tock >= tick_period) {
		tick = 1;
		tock = 0;
		LPM0_EXIT;
	}
}
