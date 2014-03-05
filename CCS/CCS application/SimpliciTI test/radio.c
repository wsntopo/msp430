#include "radio.h"


static short int	radioAsleep;
static short int	radioIdle;
static short int	messageQueued;

void initRadioState()
{
	radioAsleep = FALSE;
	radioIdle = TRUE;
	clearMessageWaiting();
}

uint8_t messageWaiting()
{
	return(messageQueued);
}

void clearMessageWaiting()
{
	messageQueued = FALSE;
}

void radioTx()
{
	if(radioAsleep) {
		SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_AWAKE, 0);
		radioAsleep = FALSE;
	}

	if (!radioIdle) {
		SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXIDLE, 0);
		radioIdle = TRUE;
	}

}

void radioRx()
{
	if(radioAsleep) {
		SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_AWAKE, 0);
		radioAsleep = FALSE;
	}

	if (radioIdle) {
		SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXON, 0);
		radioIdle = FALSE;
	}
}


void radioSleep()
{
	if (!radioIdle) {
		SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_RXIDLE, 0);
		radioIdle = TRUE;
	}

	if(!radioAsleep) {
		SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SLEEP, 0);
		radioAsleep = TRUE;
	}
}

smplStatus_t broadcastMessage(uint8_t msg)
{
	return(SMPL_Send(SMPL_LINKID_USER_UUD, &msg, sizeof(msg)));   // send empty message
}

smplStatus_t getSender(addr_t *p_sender)
{
	uint8_t smpl_buffer[MAX_APP_PAYLOAD];
	uint8_t len;

	return(my_SMPL_Receive(SMPL_LINKID_USER_UUD, smpl_buffer, &len, p_sender));
}

smplStatus_t getRSSI(rssi_t *rssi)
{
	smplStatus_t status;
	ioctlRadioSiginfo_t siginfo;

	siginfo.lid = SMPL_LINKID_USER_UUD; // this is an input
	status = SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SIGINFO, &siginfo);
	if(status == SMPL_SUCCESS) {
		*rssi = siginfo.sigInfo.rssi;
	}
	return(status);
}

void clearRxBuf(linkID_t linkIDTemp)
{
	uint8_t smpl_buffer[MAX_APP_PAYLOAD];
	uint8_t len;
	smplStatus_t stat;
	do {
		stat = SMPL_Receive(linkIDTemp, smpl_buffer, &len);
	} while ((stat == SMPL_SUCCESS) || (stat == SMPL_NO_PAYLOAD));
}

uint8_t sRxCallback(linkID_t linkIDTemp)
{
	messageQueued = TRUE;
	return 0;   // don't clear frame - this callback basically just gets us to wake up from LPM0
}


void initAddr()
{
	addr_t lAddr;
	char *Flash_Addr;

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

smplStatus_t my_SMPL_Receive(linkID_t lid, uint8_t *msg, uint8_t *len, addr_t *sender)
{
  connInfo_t  *pCInfo = nwk_getConnInfo(lid);
  smplStatus_t rc = SMPL_BAD_PARAM;
  rcvContext_t rcv;

  if (!pCInfo || ((rc=nwk_checkConnInfo(pCInfo, CHK_RX)) != SMPL_SUCCESS))
  {
    return rc;
  }

  rcv.type  = RCV_APP_LID;
  rcv.t.lid = lid;
  return nwk_retrieveFrame(&rcv, msg, len, sender, 0);
}
