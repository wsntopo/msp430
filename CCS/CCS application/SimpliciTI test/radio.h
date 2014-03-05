#ifndef RADIO_H
#define RADIO_H

#include "common.h"
#include "vlo_rand.h"

void radioTx();
void radioRx();
void radioSleep();
void initRadioState();

smplStatus_t broadcastMessage(uint8_t);
smplStatus_t getSender(addr_t*);
smplStatus_t getRSSI(rssi_t*);
void clearRxBuf(linkID_t);
void createRandomAddress(void);
void initAddr();
uint8_t sRxCallback(linkID_t);
uint8_t messageWaiting();
void clearMessageWaiting();
smplStatus_t my_SMPL_Receive(linkID_t, uint8_t *, uint8_t *, addr_t *);


#endif
