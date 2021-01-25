#include "config.h"
//#include"lcd.h"
//#include"keypad.h"
#include"timer0.h"
#include"DIO.h"
#include <util/delay.h>



void stop()
{
	Disable_Alarm_TMR0();
	PORTD|=1;
	PORTD&= ~2;
}
void ext()
{
	SetAlarm_TMR0(stop,3000);


}

int main()
{
	DDRD=3;
	PORTD=5;
	gie_enable();
	SETBIT(gicr,6);
	mcucr |= 3 ;
	callback_EXT0_Interrupt(ext);


	while(1)
	{
		if(TIMSK&2)
		{
			PORTD|=2;
			PORTD^=1;

			_delay_ms(150);
		}
		else{}

	}



	return 0;

}
