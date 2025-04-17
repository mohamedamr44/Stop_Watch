/*
 * functions.c
 *
 *  Created on: May 17, 2024
 *      Author: User-H
 */


#include "functions.h"



void seven_segments_init()
{
	/*Pins connected to decoder output*/
	DDRC|=(1<<0);
	DDRC|=(1<<1);
	DDRC|=(1<<2);
	DDRC|=(1<<3);

	/*Enable pins for seven segements output*/
	DDRA|=(1<<0);
	DDRA|=(1<<1);
	DDRA|=(1<<2);
	DDRA|=(1<<3);
	DDRA|=(1<<4);
	DDRA|=(1<<5);

}


void display_sec1(uint8_t sec1 )
{
	/*Enable the first seven segment only*/
	PORTA=(1<<0)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F&sec1);

}

void display_sec2(uint8_t sec2 )
{
	/*Enable the second seven segement only*/
	PORTA=(1<<1)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F&sec2);

}

void display_min1(uint8_t min1)
{
	PORTA=(1<<2)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F& min1);


}

void display_min2(uint8_t min2)
{
	PORTA=(1<<3)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F& min2);

}


void display_hr1(uint8_t hr1)
{
	PORTA=(1<<4)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F& hr1);

}

void display_hr2(uint8_t hr2)
{
	PORTA=(1<<5)|(PORTA &0xC0);

	PORTC=(PORTC&0xF0)|(0x0F& hr2);

}




/*Initializing TImer 1 in CTC mode*/
void Timer1_init_ctc(void)
{
	/*Enable global interrupt*/
	SREG|=(1<<7);

	/*Enable Output Compare A Match Interrupt*/
	TIMSK|=(1<<OCIE1A);

	/*1024 prescalar*/
	TCCR1B=(1<<WGM12)|(1<<CS10)|(1<<CS12);
	OCR1A=1000;



}


void INT0_init(void)
{
	/*falling edge on INT0*/
	MCUCR|=(1<<ISC01);

	/*enabling INT0 external interrupt*/
	GICR|=(1<<INT0);
	/*Enabling global interrupt*/
	SREG|=(1<<7);

	/*PD2 input (push buttpn) pull up resistor*/
	DDRD&=~(1<<2);
	/*activate internal pull up resistor*/
	PORTD|=(1<<2);


}

void INT1_init(void)
{
	/*INT1 rising edge*/
	MCUCR|=(1<<ISC10);
	MCUCR|=(1<<ISC10);

	/*enabling INT1 external interrupt*/
	GICR|=(1<<INT1);

	/*Enabling global interrupt*/
	SREG|=(1<<7);

	/*PD3 input (push buttpn) pull down resistor*/
	DDRD&=~(1<<3);

}

void INT2_init(void)
{
	/*falling edge on INT2*/
	MCUCSR&=~(1<<ISC2);

	/*Enabling INT2*/
	GICR|=(1<<INT2);

	/*Enabling global interrupt*/
	SREG|=(1<<7);

	/*push button input with internal pull up resistor*/
	DDRB&=~(1<<2);
	PORTB|=(1<<2);


}







ISR(INT0_vect)
{
	/*resets the time*/
	time.sec1=0;
	time.sec2=0;
	time.min1=0;
	time.min2=0;
	time.hr1=0;
	time.hr2=0;




}

ISR(INT1_vect)
{

	/*stops timer 1 to pause the stop watch*/
	TCCR1B&=~(1<<CS10);
	TCCR1B&=~(1<<CS11);
	TCCR1B&=~(1<<CS12);



}


ISR(INT2_vect)
{

	Timer1_init_ctc();

	/*resetting the flag to re use the interrupt*/
	//GIFR|=(1<<INTF2);

}



ISR(TIMER1_COMPA_vect)
{
	time.sec1++;

}

