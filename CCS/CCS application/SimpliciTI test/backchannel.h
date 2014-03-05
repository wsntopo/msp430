#ifndef BACKCHANNEL_H
#define BACKCHANNEL_H

#include "common.h"
#include "log.h"
#include "radio.h"
#include "tick.h"

#define	NORMAL_CHANNEL	0
#define BACK_CHANNEL	1

typedef struct {
	logType_t	log_type;
	uint16_t	past_time;
} eventLogMessage_t;

typedef struct {
	logType_t	log_type;
	addr_t		peer_addr;
	int16_t		rssi_accum;
	uint8_t		rssi_num;
} rssiLogMessage_t;

void changeChannel(uint8_t);
void checkin();
void dumpEventLog(void);
void dumpRssiLog(void);
void sendOverflowLogMessage(logType_t);
void formatEventLogMsg(eventLogType_t *, eventLogMessage_t *);
void formatRssiLogMsg(rssiLogType_t *, rssiLogMessage_t *);


#endif
