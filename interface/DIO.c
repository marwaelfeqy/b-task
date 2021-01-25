
#include "config.h"
#include "DIO.h"
#include <util/delay.h>


extern u8 blink;
static void (*Ptr_EXT0)(void);

void Dio_init_port (DIO_PORT_ID port_name, u8 write)
{
	switch (port_name)
	{
	case PORT_A: DDRA=write; break;
	case PORT_B: DDRB=write; break;
	case PORT_C: DDRC=write; break;
	case PORT_D: DDRD=write; break;
	}
}

void Dio_init_pin (DIO_PORT_ID port_name, u8 pin_number, u8 dir)
{
	switch (port_name)
	{
	case PORT_A: (dir==OUTPUT)?SETBIT(DDRA,pin_number):CLRBIT(DDRA,pin_number); break;
	case PORT_B: (dir==OUTPUT)?SETBIT(DDRB,pin_number):CLRBIT(DDRB,pin_number); break;
	case PORT_C: (dir==OUTPUT)?SETBIT(DDRC,pin_number):CLRBIT(DDRC,pin_number); break;
	case PORT_D: (dir==OUTPUT)?SETBIT(DDRD,pin_number):CLRBIT(DDRD,pin_number); break;

	}

}

void Dio_write_port(DIO_PORT_ID port_name,u8 write)
{
	switch (port_name)
	{
	case PORT_A: PORTA=write; break;
	case PORT_B: PORTB=write; break;
	case PORT_C: PORTC=write; break;
	case PORT_D: PORTD=write; break;
	}
}
void Dio_write_pin(DIO_PORT_ID port_name,u8 pin,u8 val)
{
	if (val==1)
		Dio_set_pin (port_name , pin);
	else if (val==0)
		Dio_clr_pin (port_name , pin);

}



u8 Dio_Read_port (DIO_PORT_ID port_name)
{
	switch(port_name)
	{
		PORT_A: return PINA; break;
		PORT_B: return PINB; break;
		PORT_C: return PINC; break;
		PORT_D: return PIND; break;
	}
	return -1;
}
u8 Dio_Read_pin (DIO_PORT_ID port_name, u8 pin_number)
{
	switch(port_name)
	{
		case PORT_A: return READBIT(PINA,pin_number); break;
		case PORT_B: return READBIT(PINB,pin_number); break;
		case PORT_C: return READBIT(PINC,pin_number); break;
		case PORT_D: return READBIT(PIND,pin_number); break;
	}
	return -1;
}


void Dio_set_pin (DIO_PORT_ID port_name,u8 pin_number)
{
	switch(port_name)
		{
			case PORT_A: SETBIT(PORTA,pin_number); break;
			case PORT_B: SETBIT(PORTB,pin_number); break;
			case PORT_C: SETBIT(PORTC,pin_number); break;
			case PORT_D: SETBIT(PORTD,pin_number); break;
		}
}
void Dio_clr_pin (DIO_PORT_ID port_name,u8 pin_number)
{
	switch(port_name)
		{
			case PORT_A: CLRBIT(PORTA,pin_number); break;
			case PORT_B: CLRBIT(PORTB,pin_number); break;
			case PORT_C: CLRBIT(PORTC,pin_number); break;
			case PORT_D: CLRBIT(PORTD,pin_number); break;
		}
}
void Dio_tog_pin (DIO_PORT_ID port_name,u8 pin_number)
{
	switch(port_name)
		{
			case PORT_A: TOGBIT(PORTA,pin_number); break;
			case PORT_B: TOGBIT(PORTB,pin_number); break;
			case PORT_C: TOGBIT(PORTC,pin_number); break;
			case PORT_D: TOGBIT(PORTD,pin_number); break;
		}
}
void callback_EXT0_Interrupt (void(*Ptr_Function)(void))
{

	Ptr_EXT0=Ptr_Function;
}

ISR(__vector_1)
{
(*Ptr_EXT0)();

}
