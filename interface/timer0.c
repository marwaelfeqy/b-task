#include "timer0.h"


struct STimer0_Settings Timer0_Configuration;
u32 TOV_Number ;
u32 num ;

static void (*Ptr_OFI)(void);
static void (*Ptr_CMI)(void);


void TMR0_Init(struct STimer0_Settings Configuration)
{
	Timer0_Configuration = Configuration ;

	/*********************Adjust Mode***********************/
	if (Timer0_Configuration.Timer0_Mode == NORMAL )
	{
		TCCR0 &= ~(1<<WGM00);
		TCCR0 &= ~( 1<< WGM01);
	}

	if (Timer0_Configuration.Timer0_Mode == CTC )
	{
		TCCR0 &= ~(1<<WGM00);
		TCCR0 |= ( 1<< WGM01);
	}

	/************************Adjust prescalar************************/
	TCCR0 = TCCR0 | Timer0_Configuration.Timer0_PRESCALAR;

	/**************************TMR0 Enable/Disable********************/
	if (Timer0_Configuration.Timer0_OVFI == TOIE0_enable )
	{
		TIMSK |= 1<< TOIE0 ;
	}
	else if (Timer0_Configuration.Timer0_OVFI == TOIE0_disable)
	{
		TIMSK &= ~(1<< TOIE0) ;

	}

	/**************************OCR0 Enable/Disable********************/
	if (Timer0_Configuration.Timer0_OCIE == OCIE0_enable )
	{
		TIMSK |= 1<< OCIE0 ;
	}
	else if (Timer0_Configuration.Timer0_OCIE == OCIE0_disable)
	{
		TIMSK &= ~(1<< OCIE0) ;

	}

}

void TMR0_ReadCounterValue(u8 *u8NumOfTicks)
{
	*u8NumOfTicks = TCNT0;
}
void TMR0_Set_Compare_Value(u8 u8Val)
{
	OCR0 = u8Val;
}

void TMR0_Set_Counter_Value(u8 u8Val)
{
	TCNT0 = u8Val;

}


//used for set the Number of OverFlow (Used for SW Counters)

void TMR0_Set_TOV_Number(u8 u8Val)
{
	TOV_Number = u8Val;

}
void TMR0_Get_TOV_Number(u8 *u8Val)
{
	*u8Val = TOV_Number ;
}


void SetAlarm_TMR0(void(*Ptr_to_OCM_Function)(void),u32 t)
{
	struct STimer0_Settings config;
	TMR0_Set_Compare_Value(100);
	config.Timer0_Mode=CTC;
	config.Timer0_OVFI=TOIE0_disable;
	config.Timer0_OCIE=OCIE0_enable;
	config.Timer0_PRESCALAR=PRESCALING_CLK8;
	TOV_Number=t*10;
	callback_OCR0_Compare_Match_Interrupt( Ptr_to_OCM_Function );
	TMR0_Init(config);


}
void Disable_Alarm_TMR0()
{
	struct STimer0_Settings config;
	config.Timer0_Mode=CTC;
	config.Timer0_OVFI=TOIE0_disable;
	config.Timer0_OCIE=OCIE0_disable;
	config.Timer0_PRESCALAR=PRESCALING_CLK8;
	TMR0_Init(config);


}

void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void))
{
	Ptr_OFI = Ptr_to_OVI_Function ;
	num=TOV_Number;

}
void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void))
{
	Ptr_CMI = Ptr_to_OCM_Function ;
	num=TOV_Number;

}



ISR(__vector_10)
{
	num--;
	if(num==0)
	{
	(*Ptr_CMI)();
	num=TOV_Number;
	}
}
ISR(__vector_11)
{
		num--;
		if(num==0)
		{
		(*Ptr_OFI)();
		num=TOV_Number;
		}
}
