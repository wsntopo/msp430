#ifndef LOG_H
#define LOG_H

#include "common.h"
#include "tick.h"
#include "string.h"

#define	EVENT_LOG_SIZE 4
#define	RSSI_LOG_SIZE 5

enum logTypeObject {
	NOT_USED,
	LOG_LISTEN_START,
	LOG_LISTEN_STOP,
	LOG_SHOUT_START,
	LOG_SHOUT_STOP,
	LOG_SLEEP_START,
	LOG_SLEEP_STOP,
	LOG_RSSI,
	EVENT_LOG_OVERFLOW,	// used when log fills up and things are dropped
	RSSI_LOG_OVERFLOW	// used when log fills up and things are dropped
};

typedef enum logTypeObject logType_t;

typedef struct {
	logType_t	event;
	uint32_t	time;
} eventLogType_t;

typedef struct {
	addr_t		peer_addr;
	int16_t		rssi_accum;
	uint8_t		rssi_num;
} rssiLogType_t;
// don't increment rssi_num past this number
#define RSSI_NUM_MAX	255


void initLog(void);

uint8_t pushEventLog(logType_t);
uint8_t popEventLog(eventLogType_t*);
void clearEventLog(void);
uint8_t eventOverflow();

uint8_t pushRssiLog(addr_t, rssi_t);
uint8_t popRssiLog(rssiLogType_t *);
void clearRssiLog(void);
uint8_t rssiOverflow();


#endif
