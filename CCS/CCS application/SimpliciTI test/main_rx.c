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

	while (SMPL_SUCCESS != SMPL_LinkListen(&linkIDTemp))    // link to Tx
	{
		BSP_TOGGLE_LED1();                      // toggle red for not linked
	}

  	BSP_TURN_OFF_LED1();                      // red off
  	NWK_DELAY(2000);                             // for 2 seconds
  	BSP_TURN_ON_LED1();

  	_EINT();                                  // Enable Global Interupts

	while (1)
	{

	}
}

static uint8_t sRxCallback(linkID_t linkIDTemp)
{
	SMPL_Receive(linkIDTemp, (uint8_t*)&smpl_buffer, &len);

	if(len == sizeof(my_sensors))
	{
  		memcpy(&sensor, smpl_buffer, len);
	} else {
  	__no_operation();
  	BSP_TOGGLE_LED1();
	}

	// replace with_  return message;
	return 0;
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
