#ifndef INIT_H
#define INIT_H

#include "common.h"

// jumpers - if there is a jumper between these pins, the node is a beacon and cycles.  Otherwise it does the standard sleep/listen/shout behavior.
#define JUMPER1_DIR	P2DIR
#define JUMPER1_OUT	P2OUT
#define JUMPER1_PIN	BIT3
#define JUMPER2_DIR	P2DIR
#define JUMPER2_OUT	P2OUT
#define JUMPER2_IN	P2IN
#define JUMPER2_REN	P2REN
#define	JUMPER2_PIN	BIT4

void init(uint16_t);
void init_Timer0_A0(void);
short int isBeacon(void);
void initClock(void);

#endif
