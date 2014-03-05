#include "log.h"

static eventLogType_t	eventLog[EVENT_LOG_SIZE];
static rssiLogType_t	rssiLog[RSSI_LOG_SIZE];

static uint8_t	eventLogEntries, rssiLogEntries;
static uint8_t	eventLogOverflow, rssiLogOverflow;

void initLog()
{
	clearEventLog();
	clearRssiLog();
}

uint8_t eventOverflow() 
{
	return eventLogOverflow;
}

uint8_t rssiOverflow()
{
	return rssiLogOverflow;
}

uint8_t pushEventLog(logType_t event)
{
	if (eventLogEntries >= EVENT_LOG_SIZE) {
		eventLogOverflow = TRUE;
		return(FALSE);
	} 

	eventLog[eventLogEntries].time = getLocalTime();
	eventLog[eventLogEntries].event = event;
	eventLogEntries++;
	return(TRUE);
}

uint8_t	popEventLog(eventLogType_t *log_entry)
{
	if(eventLogEntries <= 0) {
		return(FALSE);
	} 

	log_entry->event = eventLog[eventLogEntries - 1].event;
	log_entry->time = eventLog[eventLogEntries - 1].time;
	eventLogEntries--;

	return(TRUE);
}

void clearEventLog()
{
	eventLogEntries = 0;
	eventLogOverflow = FALSE;
}

uint8_t addrIsEqual(addr_t a, addr_t b)
{
	return(!memcmp(a.addr, b.addr, sizeof(addr_t)));
}

uint8_t pushRssiLog(addr_t addr, rssi_t rssi)
{
	uint8_t i;

	// find entry for addr
	for(i = 0; i < rssiLogEntries; i++) {
		if(addrIsEqual(rssiLog[i].peer_addr, addr)) {
			break;
		}
	}

	// At the end of this, "i" will be the entry if found, or 
	// will equal rssiLogEntries if not found.  Can add new one.
	// if rssiLogEntries is at max size (= RSSI_LOG_SIZE -1), then
	// not found and no space ==> i == RSSI_LOG_SIZE

	if (i == RSSI_LOG_SIZE) {   // not found in existing, overflow
		rssiLogOverflow = TRUE;
		return(FALSE);
	} // if we get here, i is the right place to log stuff
	
	if (i == rssiLogEntries) { // we are dealing with new one, need to init
		rssiLog[i].rssi_accum = rssi;
		rssiLog[i].rssi_num = 1;
		rssiLogEntries++;
	} else { 	// existing one, increment
		if (rssiLog[i].rssi_num < RSSI_NUM_MAX) {   // don't overflow
			rssiLog[i].rssi_accum += rssi;
			rssiLog[i].rssi_num++;
		}
	}

	rssiLog[i].peer_addr = addr;

	return(TRUE);
}

uint8_t	popRssiLog(rssiLogType_t *log_entry)
{
	if(rssiLogEntries <= 0) {
		return(FALSE);
	} 

	log_entry->peer_addr = rssiLog[rssiLogEntries - 1].peer_addr;
	log_entry->rssi_accum = rssiLog[rssiLogEntries - 1].rssi_accum;
	log_entry->rssi_num = rssiLog[rssiLogEntries - 1].rssi_num;
	rssiLogEntries--;

	return(TRUE);
}

void clearRssiLog()
{
	rssiLogEntries = 0;
	rssiLogOverflow = FALSE;
}
