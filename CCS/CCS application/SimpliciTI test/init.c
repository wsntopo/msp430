#include "init.h"
#include "log.h"
#include "tick.h"
#include "radio.h"

void init(uint16_t tick_period)
{
	BSP_Init();                               // init bsp first, then simpliciti

	initAddr();

  	initClock();
	initLog();
  	init_Timer0_A0();

  	initRadioState();	// set the state variables

  	SMPL_Init(sRxCallback);
	initTick(tick_period);

  	BSP_TURN_OFF_LED1();
  	BSP_TURN_OFF_LED2();
  	_EINT();                                  // Enable Global Interupts
}

void initClock()
{
	WDTCTL = WDTHOLD | WDTPW;
	DCOCTL = CALDCO_16MHZ;
	BCSCTL1 = CALBC1_16MHZ;
	BCSCTL2 = DIVS_1;  // SMCLK = DCOCLK/2
	// SPI (USCI) uses SMCLK, prefer SMCLK < 10MHz (SPI speed limit for nRF24 = 10MHz)
}

void init_Timer0_A0(void)
{
    TA0CCTL0 = CM_0 + CCIS_0 + OUTMOD_4 + CCIE;
    TA0CCR0 = 1000;
    TA0CTL = TASSEL_2 + ID_3 + MC_1;	// smclock = 8MHz, /8 -> 1ms = 1000
}

short int isBeacon()
{
	short int jumper_value;

	// set Jumper 1 to be output, set to 0
    JUMPER1_DIR |= JUMPER1_PIN;   // jumper1 output
    JUMPER1_OUT &= ~JUMPER1_PIN;    // set to 0

	// set jumper 2 to be input, pullup resistor
    JUMPER2_DIR &= ~JUMPER2_PIN;   // Set jumper2 pin as an input pin
    JUMPER2_OUT |= JUMPER2_PIN;    // Set pull up resistor
    JUMPER2_REN |= JUMPER2_PIN;    // Enable pull up resistor for jumper2

    __delay_cycles(160000);	// wait 10ms

	// read jumper 2 - if it is low, then there is a jumper.  Otherwise, not.
	jumper_value = JUMPER2_IN & JUMPER2_PIN;

	// Don't need to be wasting power, so disable stuff.
    JUMPER1_DIR &= ~JUMPER1_PIN;   // jumper1 as input (high impedance)
    JUMPER2_REN &= ~JUMPER2_PIN;    // disable pull up resistor on jumper2

    return(jumper_value != JUMPER2_PIN);
}

