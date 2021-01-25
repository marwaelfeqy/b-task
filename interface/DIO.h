/*
 * DIO.h
 *
 *  Created on: Jan 24, 2021
 *      Author: toshipa
 */

#ifndef DIO_H_
#define DIO_H_



#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1


typedef enum
	{
		PORT_A,
		PORT_B,
		PORT_C,
		PORT_D
	}DIO_PORT_ID;



void Dio_init_port (DIO_PORT_ID port_name, u8 dir);
void Dio_init_pin (DIO_PORT_ID port_name, u8 pin_number, u8 dir);

void Dio_write_port(DIO_PORT_ID port_name,u8 write);
void Dio_write_pin(DIO_PORT_ID port_name,u8 pin,u8 val);

u8 Dio_Read_port (DIO_PORT_ID port_name);
u8 Dio_Read_pin (DIO_PORT_ID port_name, u8 pin_number);

void Dio_set_pin (DIO_PORT_ID port_name,u8 pin_number);
void Dio_clr_pin (DIO_PORT_ID port_name,u8 pin_number);
void Dio_tog_pin (DIO_PORT_ID port_name,u8 pin_number);

void callback_EXT0_Interrupt (void(*Ptr_Function)(void));




#define ISR(vector) \
	void vector(void) __attribute__ ((signal));\
	void vector(void)

#endif /* DIO_H_ */
