//#####################################################
//#  For the sake of simplicity going to use a lot of
//#  the same code as for one of the nodes, even though
//#  I don't actually need most of it.
//#####################################################

#include "common.h"

#include "vlo_rand.h"

#include "main_sleep_wake.h"
#include "log.h"
#include "backchannel.h"
#include "tick.h"
#include "init.h"
#include "radio.h"

#include "uart.h"
/*
#include <stdio.h>
#include <string.h>

int fputc(int _c, register FILE *_fp)
{
	uart_putc((unsigned char)_c);
 	return((unsigned char)_c);
}

int fputs(const char *_ptr, register FILE *_fp)
{
	unsigned int len;
	len = strlen(_ptr);
	uart_puts(( char*)_ptr);
	return len;
}
*/
//
#include "bsp_external/mrfi_board_defs.h"
//

void uart_rx_isr(unsigned char c) {
	uart_putc(c);
}
/*
typedef union msgbuf
{
	eventLogMessage_t event;
	rssiLogMessage_t rssi;
} messageBufferUnion_t;
*/
void frameStart()
{
	uart_putc((char)0);
	uart_putc((char)0);
	uart_putc((char)0);
	uart_putc((char)0);
}

void frameEnd()
{
	uart_putc((char)255);
}
void dumpTime(uint32_t time)
{
	uint8_t i;
	if(time == 0) {	// try not to screw up marker - this shouldn't happen anyway
		time = 1;
	}

	for(i = 0; i < 4; i++) {
		uart_putc((char)((time >> (i * 8)) & 0xf));
	}
}

void receiveMessage(linkID_t linkIDTemp)
{
	uint8_t smpl_buffer[MAX_APP_PAYLOAD];
	uint8_t len;
	uint8_t i;
	smplStatus_t stat;
	uint32_t receive_time = getLocalTime();
	uint32_t offset_time = 0;

	do {
		stat = SMPL_Receive(linkIDTemp, smpl_buffer, &len);
		if(stat == SMPL_SUCCESS){
			frameStart();
			switch(smpl_buffer[0]) {
				case LOG_RSSI:
					for(i = 0; i < len; i++) {
						uart_putc((char)smpl_buffer[i]);
					}
					dumpTime(receive_time);
					break;

				case EVENT_LOG_OVERFLOW:
				case RSSI_LOG_OVERFLOW:
					for(i = 0; i < 2; i++) {
						uart_putc((char)smpl_buffer[i]);
					}
					dumpTime(receive_time);
					break;

				default: 					// normal event messages
					for(i = 0; i < (len - 2); i++) {
						uart_putc((char)smpl_buffer[i]);
					}
					offset_time += smpl_buffer[len - 2] + (smpl_buffer[len - 1] << 8);
					dumpTime(receive_time - offset_time);
					break;

			}
			frameEnd();
		}
	} while ((stat == SMPL_SUCCESS) || (stat == SMPL_NO_PAYLOAD));
	clearMessageWaiting();
}


/* end globals */

void main(void)
{
	int i = 0;

	// init the UART stuff
	uart_init();
	// register ISR called when data was received
    uart_set_rx_isr_ptr(uart_rx_isr);


	init(PERIOD_MS);

    __bis_SR_register(GIE);

    uart_puts((char *)"\n\r***************\n\r");
    uart_puts((char *)"Listen/Shout/Sleep Automaton monitor\n\r");
    uart_puts((char *)"***************\n\r\n\r");


	changeChannel(BACK_CHANNEL);
	radioRx();
	while(TRUE) {
		if(messageWaiting()) {
			receiveMessage(SMPL_LINKID_USER_UUD);
//		    uart_puts((char *)"X\n\r");
//		    uart_putc((char)((int)'0' + (i++ % 10)));
		    BSP_TURN_ON_LED1();
//			BSP_Delay(50000);	// wait approx. 50ms (not exact)
			// parse message, put in output buffer
			BSP_TURN_OFF_LED1();

		}
	}

}



