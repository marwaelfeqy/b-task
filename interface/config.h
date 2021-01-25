/*
 * config.h
 *
 *  Created on: Jan 23, 2021
 *      Author: toshipa
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define u8 unsigned char
#define u32 long

#define NULL ((void*)0)


#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)
#define gie_enable() SREG |=  (1 << (7))

#define DDRA *(( unsigned char*)0x3A)
#define PORTA *(( unsigned char*)0x3B)
#define PINA *(( unsigned char*)0x39)
#define DDRB *(( volatile unsigned char*)0x37)
#define PORTB *(( volatile unsigned char*)0x38)
#define PINB *(( unsigned char*)0x36)
#define DDRC *(( unsigned char*)0x34)
#define PORTC *(( unsigned char*)0x35)
#define PINC *(( unsigned char*)0x33)
#define DDRD *(( unsigned char*)0x31)
#define PORTD *(( unsigned char*)0x32)
#define PIND *(( unsigned char*)0x30)
#define admux *(( unsigned char*)0x27)
#define adcsra *(( unsigned char*)0x26)
#define adcl *(( unsigned char*)0x24)
#define adch *(( unsigned char*)0x25)
//interrupts
#define SREG *(( unsigned char*)0x5F)//(pin7)(GIE Global Interrupt Enable) bit must be set for the interrupts to be enabled

#define gicr *(( unsigned char*)0x5B) /*(PIE)General external Interrupt Control Register   bit(6,7,5) for enable external (0,1,2)  */

#define mcucr *(( unsigned char*)0x55) /* to select the event for int0 and int 1
                                          The MCU Control Register contains control bits for interrupt sense control
                                          bit (0,1) for external 0      bit (2,3) for external 1  */
#define mcucsr *(( unsigned char*)0x54) /* to select event for int2*/

#define gifr *(( unsigned char*)0x5A) /*General Interrupt Flag Register    bit(6,7,5) for  (0,1,2)  */

//timer
#define TCNT0	*((volatile unsigned char*)0x52) // counter 8 bit reg to read from 0 to 255

#define TCCR0	*((volatile unsigned char*)0x53) /*
                                          (bit3-wgm01 &bit6-wgm00) to select the mode (normal-pwm-ctc)
                                          (bit4-com00 &bit5-com01) to select the mode for co0(inverting -non)
                                          (bit0,1,2) to select the freq/?? (change time cycle)
                                        */
#define OCR0	*((volatile unsigned char*)0x5C) //  set a value to compared with the counter value (TCNT0)
#define TIMSK	*((volatile unsigned char*)0x59) /*
                                        (bit-0) to enable normal overflow interrupt (PIE)
                                        (bit-1) to enable *ctc* overflow interrupt (PIE)
                                       */
#define tccr1a *(( unsigned char*)0x4f)
#define tccr1b *(( unsigned char*)0x4e)
#define wdtcr *(( unsigned char*)0x41) /*
										bit3 watchdog enable
										bit4 wdtoe to turnof watchdog(bit3,4=1 -->bit3=0)
										bit(0-2) clk pre
 	 	 	 	 	 	 	 	 	   */

#define ucsra *(( unsigned char*)0x2b)
#define ucsrb *(( unsigned char*)0x2a)
#define ucsrc *(( unsigned char*)0x40)
#define ubrrh *(( unsigned char*)0x40)
#define ubrrl *(( unsigned char*)0x29)
#define udr *(( unsigned char*)0x2c)
#define spcr *(( unsigned char*)0x2d)
#define spsr *(( unsigned char*)0x2e)
#define spdr *(( unsigned char*)0x2f)
#define TWBR *(( unsigned char*)0x20)
#define TWSR *(( unsigned char*)0x21)
#define TWAR *(( unsigned char*)0x22)
#define TWDR *(( unsigned char*)0x23)
#define TWCR *(( unsigned char*)0x56)


#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received

#define TWPS1 1
#define TWPS0 0
#define TWEN 2
#define TWSTA 5
#define TWINT 7
#define TWSTO 4
#define TWEA 6



#endif /* CONFIG_H_ */
