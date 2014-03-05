#include "backchannel.h"

void checkin()
{
	// change channel
	changeChannel(BACK_CHANNEL);

	// don't want to be dealing with something in Rx buffer - wrong RSSI?
	clearRxBuf(SMPL_LINKID_USER_UUD);

	dumpEventLog();
	dumpRssiLog();

	resetLocalTime();

	// change channel back
	changeChannel(NORMAL_CHANNEL);
}

void changeChannel(uint8_t channel)
{
	freqEntry_t chan;
	chan.logicalChan = channel;
	while(SMPL_SUCCESS != SMPL_Ioctl(IOCTL_OBJ_FREQ, IOCTL_ACT_SET, &chan));  // freeze if I can't change
}

void dumpEventLog()
{
	eventLogMessage_t	msg;
	eventLogType_t log_entry;

	if(eventOverflow()) {
		sendOverflowLogMessage(EVENT_LOG_OVERFLOW);
	}

	while(popEventLog(&log_entry)) {
		formatEventLogMsg(&log_entry, &msg);
		while(SMPL_SUCCESS != SMPL_Send(SMPL_LINKID_USER_UUD, (uint8_t*)&msg,sizeof(msg)));
	}
	clearEventLog();
}

void sendOverflowLogMessage(logType_t type)
{
	eventLogMessage_t msg;
	msg.log_type = type;
	while(SMPL_SUCCESS != SMPL_Send(SMPL_LINKID_USER_UUD,(uint8_t*)&msg,sizeof(msg)));
}

void dumpRssiLog()
{
	rssiLogMessage_t	msg;
	rssiLogType_t	log_entry;

	if(rssiOverflow()) {
		sendOverflowLogMessage(RSSI_LOG_OVERFLOW);
	}

	while(popRssiLog(&log_entry)) {
		formatRssiLogMsg(&log_entry, &msg);
		while(SMPL_SUCCESS != SMPL_Send(SMPL_LINKID_USER_UUD, (uint8_t*)&msg,sizeof(msg)));
	}
	clearRssiLog();
}


void formatEventLogMsg(eventLogType_t *event_log_entry, eventLogMessage_t *msg) 
{
	msg->log_type = event_log_entry->event;
	msg->past_time = (uint16_t)(getLocalTime() - event_log_entry->time);
}

void formatRssiLogMsg(rssiLogType_t *rssi_log_entry, rssiLogMessage_t *msg) 
{
	msg->log_type = LOG_RSSI;
	msg->peer_addr = rssi_log_entry->peer_addr;
	msg->rssi_accum = rssi_log_entry->rssi_accum;
	msg->rssi_num = rssi_log_entry->rssi_num;
}
