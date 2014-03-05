#include "common.h"

#include "vlo_rand.h"

#include "main_sleep_wake.h"
#include "log.h"
#include "backchannel.h"
#include "tick.h"
#include "init.h"
#include "radio.h"

/* end globals */

void main(void)
{
	uint8_t 	heard_something, flag;
	short int 	beacon;
	short int 	state;

	init(PERIOD_MS);
  	beacon = isBeacon();

	state = LISTEN;
	while(1) {
		switch(state)  {
			case LISTEN:
				checkin();
				pushEventLog(LOG_LISTEN_START);
				heard_something = FALSE;
				listen();		// start listening
				while(!getTick()) {
					if(messageWaiting()) {
						flag = hear();		// could have done these in one, but was more confusing for later
						heard_something = flag || heard_something;
					}
				}
				resetTick();
				if(heard_something || beacon) {
					state = next_state(state);
				}
				pushEventLog(LOG_LISTEN_STOP);
				break;
			case SHOUT:
				checkin();
				pushEventLog(LOG_SHOUT_START);
				while(!getTick()) {
					shout();
				}
				resetTick();
				state = next_state(state);
				pushEventLog(LOG_SHOUT_STOP);
				break;
			default:		// sleep
				checkin();
				pushEventLog(LOG_SLEEP_START);
				while(!getTick()) {
					sleep();
				}
				resetTick();
				state = next_state(state);
				pushEventLog(LOG_SLEEP_STOP);
				break;
		}  // switch
		BSP_Delay(10);	// wait 10ms
	} // while

}

void	shout()
{
	smplStatus_t stat;


	BSP_TURN_OFF_LED2();

	radioTx();

	stat = broadcastMessage(0xAB);

	if (stat == SMPL_SUCCESS) {
		BSP_TURN_ON_LED1();
	} else {
		BSP_TURN_OFF_LED1();
	}
	BSP_Delay(50000);	// wait approx. 50ms (not exact)
}

void	listen()
{
	BSP_TURN_OFF_LED1();
	BSP_TURN_ON_LED2();

	radioRx();

}

uint8_t hear()
{
	// we come here after waking up from LPM0 after listening.
	// we could have gotten here because we received a message, or because a timer expired.

	// try to get message sent to SMPL_LINKID_USER_UUD link address.  If nothing there, then clear Rx buffer - assume timer expired

	addr_t sender;
	smplStatus_t status;

	uint8_t done = FALSE;
	uint8_t heard_something = FALSE;
	rssi_t rssi;

	while(!done) {  // on the off chance that we have two messages waiting...
		status = getSender(&sender);
		if (status != SMPL_SUCCESS) {	// no shout messages to hear...
			done = TRUE;
			clearMessageWaiting();		// there is a possible race condition here...
		} else {
			status = getRSSI(&rssi);
			if(status == SMPL_SUCCESS) {
				pushRssiLog(sender, rssi);
				if(rssi > RSSI_CUTOFF) { // can also look at siginfo.sigInfo.lqi for link quality indicator
					heard_something = TRUE;
				}
			}
		} // Ioctl status
	}  // !done

	return(heard_something);
}

void sleep()
{

	BSP_TURN_OFF_LED1();
	BSP_TURN_OFF_LED2();
	LPM0;
}

uint8_t next_state(uint8_t state)
{
	return((state + 1) % NUM_PERIODS);
}





