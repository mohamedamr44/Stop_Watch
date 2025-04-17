/*
 * timers.h
 *
 *  Created on: May 17, 2024
 *      Author: User-H
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void Timer1_init_ctc(void);

void seven_segments_init();

void display_sec1(uint8_t sec1 );
void display_sec2(uint8_t sec2 );

void display_min1(uint8_t min1 );
void display_min2(uint8_t min2 );

void display_hr1(uint8_t hr1 );
void display_hr2(uint8_t hr2 );


void INT0_init(void);
void INT1_init(void);
void INT2_init(void);



typedef struct
{
	uint8_t sec1;
	uint8_t sec2;

	uint8_t min1;
	uint8_t min2;

	uint8_t hr1;
	uint8_t hr2;

}stop_watch;

stop_watch time;



#endif /* FUNCTIONS_H_ */

