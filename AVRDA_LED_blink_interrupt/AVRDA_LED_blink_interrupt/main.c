/*
 * AVRDA_LED_blink_interrupt.c
 *
 * Created: 5/27/2019 12:58:44 PM
 * Author : M50653
 */ 

#include <avr/io.h>
#define F_CPU               4000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define TIMER_PERIOD        0x2000

ISR(TCA0_OVF_vect) {

    PORTC.OUTTGL = PIN6_bm;

    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}

int main(void)
{
	/* Configure LED0 pin as output */
    PORTC.DIRSET = PIN6_bm;

    TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
    TCA0.SINGLE.PER = TIMER_PERIOD;
    TCA0.SINGLE.CTRLA = (TCA_SINGLE_CLKSEL1_bm | TCA_SINGLE_CLKSEL2_bm);
    TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm;
   
    sei();    

    while (1)
    {
       ;
    }
}



