/* receiver code */

#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>

#include "vlo_rand.h"

#include "bsp.h"                          // bsp header files
#include "bsp_leds.h"                     // included with simpliciti
#include "bsp_buttons.h"

#include "mrfi.h"                         // simpliciti headers
#include "nwk_types.h"
#include "nwk_api.h"
#include "nwk.h"

void shout();
void listen();
void clearRxBuf(linkID_t);

/* global variables */

typedef struct sensors_struct
{
	char cadc;
	int iadc;
}my_sensors;

struct sensors_struct sensor;

 /* bsp related variables */
linkID_t  linkIDTemp;
uint8_t smpl_buffer[MAX_APP_PAYLOAD];
uint8_t len;
uint8_t flag;

addr_t lAddr;
char *Flash_Addr;

static uint8_t sRxCallback(linkID_t);

void createRandomAddress(void);

/* end globals */

void main(void)
{
  	BSP_Init();                               // init bsp first, then simpliciti

  	// address check and creation
	Flash_Addr = (char *)0x10F0;              // RF Address = 0x10F0
	if( Flash_Addr[0] == 0xFF &&              // Check if device Address is missing
    	Flash_Addr[1] == 0xFF &&
    	Flash_Addr[2] == 0xFF &&
    	Flash_Addr[3] == 0xFF )
  	{
    	createRandomAddress();                  // Create Random device address at
	}                                         // initial startup if missing
	lAddr.addr[0] = Flash_Addr[0];
	lAddr.addr[1] = Flash_Addr[1];
	lAddr.addr[2] = Flash_Addr[2];
	lAddr.addr[3] = Flash_Addr[3];
	// load address
	SMPL_Ioctl(IOCTL_OBJ_ADDR, IOCTL_ACT_SET, &lAddr);

  	SMPL_Init(sRxCallback);

	SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0); // turn on radio, listen
  	BSP_TURN_OFF_LED1();
  	BSP_TURN_OFF_LED2();
  	_EINT();                                  // Enable Global Interupts

	while (1) {
		if (BSP_BUTTON1()) {
			shout();
		} else {
			listen();
		}
	}
}

void	shout()
{
	smplStatus_t stat;
	uint8_t	msg[1];

	SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXIDLE, 0);
	msg[0] = 0xAB;
	stat = SMPL_Send(SMPL_LINKID_USER_UUD, msg, sizeof(msg));   // send empty message
	if (stat == SMPL_SUCCESS) {
		BSP_TURN_ON_LED1();                      // on
		BSP_Delay(10);                             // for 2 microseconds
		BSP_TURN_OFF_LED1();
	}
}

void	listen()
{
	SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);
	BSP_Delay(10);
}

static uint8_t sRxCallback(linkID_t linkIDTemp)
{
	// right now this callback simply clears out the buffer, then toggles the LED briefly
	smplStatus_t status;
	ioctlRadioSiginfo_t siginfo;


	status = SMPL_Receive(linkIDTemp, (uint8_t*)&smpl_buffer, &len);
	if ((status == SMPL_SUCCESS) || (status == SMPL_NO_PAYLOAD)) {
		siginfo.lid = linkIDTemp; // this is an input
		status = SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SIGINFO, &siginfo);
		if(status == SMPL_SUCCESS) {
			if(siginfo.sigInfo.rssi > -50) { // can also look at siginfo.sigInfo.lqi for link quality indicator
				BSP_TURN_ON_LED2();                      // on
				clearRxBuf(linkIDTemp);
				BSP_Delay(10);                             // for 2 microseconds
				BSP_TURN_OFF_LED2();
			}
		}
	}

	return 0;
}

void clearRxBuf(linkID_t linkIDTemp)
{
	smplStatus_t stat;
	do {
		stat = SMPL_Receive(linkIDTemp, (uint8_t*)&smpl_buffer, &len);
	} while ((stat == SMPL_SUCCESS) || (stat == SMPL_NO_PAYLOAD));
}

void createRandomAddress(void)
{
  unsigned int rand, rand2;
  char *Flash_Addr;
  Flash_Addr = (char *)0x10F0;

  do
  {
    rand = TI_getRandomIntegerFromADC();    // first byte can not be 0x00 of 0xFF
  }
  while( (rand & 0xFF00)==0xFF00 || (rand & 0xFF00)==0x0000 );
  rand2 = TI_getRandomIntegerFromADC();

  BCSCTL1 = CALBC1_1MHZ;                    // Set DCO to 1MHz
  DCOCTL = CALDCO_1MHZ;
  FCTL2 = FWKEY + FSSEL0 + FN1;             // MCLK/3 for Flash Timing Generator
  FCTL3 = FWKEY + LOCKA;                    // Clear LOCK & LOCKA bits
  FCTL1 = FWKEY + WRT;                      // Set WRT bit for write operation

  Flash_Addr[0]=(rand>>8) & 0xFF;
  Flash_Addr[1]=rand & 0xFF;
  Flash_Addr[2]=(rand2>>8) & 0xFF;
  Flash_Addr[3]=rand2 & 0xFF;

  FCTL1 = FWKEY;                            // Clear WRT bit
  FCTL3 = FWKEY + LOCKA + LOCK;             // Set LOCK & LOCKA bit
}
