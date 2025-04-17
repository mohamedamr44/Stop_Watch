/*
 * main.c
 *
 *  Created on: May 17, 2024
 *      Author: User-H
 */

#include "functions.h"

int main(void)
{
	seven_segments_init();
	Timer1_init_ctc();
	INT0_init();
	INT1_init();
	INT2_init();

while(1)
{

		if(time.sec1>9)
		{
			time.sec1=0;
			time.sec2++;

		}
		else if(time.sec2>5)
		{
			time.sec2=0;
			time.min1++;
		}
		else if(time.min1>9)
		{
			time.min1=0;
			time.min2++;

		}
		else if(time.min2>5)
		{
			time.min2=0;
			time.hr1++;
		}
		else if(time.hr1>9)
		{
			time.hr1=0;
			time.hr2++;
		}
		else if(time.hr2>9)
		{
			time.sec1=0;
			time.sec2=0;
			time.min1=0;
			time.min2=0;
			time.hr1=0;
			time.hr2=0;
		}


	 display_sec1(time.sec1 );
	 _delay_ms(5);
	 display_sec2(time.sec2 );
	 _delay_ms(5);

	 display_min1(time.min1 );
	 _delay_ms(5);
	 display_min2(time.min2 );
	 _delay_ms(5);

	 display_hr1(time.hr1 );
	 _delay_ms(5);
	 display_hr2(time.hr2 );
	 _delay_ms(5);






}



	return 0;
}
