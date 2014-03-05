#ifndef TICK_H
#define TICK_H

#include "common.h"

void initTick(uint16_t);
void resetTick(void);
uint8_t getTick(void);
uint32_t getLocalTime(void);
void resetLocalTime(void);

#endif
