/*
 * DIO_DD.H
 *
 *  Created on: Oct 9, 2021
 *      Author: PC-SHOP
 */

#ifndef DIO_DD_h_
#define DIO_DD_h_
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
#define all_output 255
#define all_input 0
#define output 1
#define input 0
#define PORTA_NUM 0
#define PORTB_NUM 1
#define PORTC_NUM 2
#define PORTD_NUM 3
#define pull_up 1
#define high 1
#define low 0
#define all_high 255
#define ok 1
#define not_ok 0
#define set_bit(var,bit) var|=(1<<bit)
#define clr_bit(var,bit) var&=(~(1<<bit))
#define tog_bit(var,bit) var^=(1<<bit)
#define get_bit(var,bit) (var&(1<<bit))>>bit
#define clr_reg(reg) reg&=0
//sven segment numbers
#define num_zero  0b00111111
#define num_one   0b00000110
#define num_two   0b01011011
#define num_three 0b01001111
#define num_four  0b01100110
#define num_five  0b01101101
#define num_six   0b01111101
#define num_seven 0b01000111
#define num_eight 0b01111111
#define num_nine  0b01101111
#define dot       0b10000000
//adress of registers
#define PORTA *((volatile unsigned char *)0X3B)
#define DDRA *((volatile unsigned char *)0X3A)
#define PINA *((volatile unsigned char *)0X39)
#define PORTB *((volatile unsigned char *)0X38)
#define DDRB *((volatile unsigned char *)0X37)
#define PINB *((volatile unsigned char *)0X36)
#define PORTC *((volatile unsigned char *)0X35)
#define DDRC *((volatile unsigned char *)0X34)
#define PINC *((volatile unsigned char *)0X33)
#define PORTD *((volatile unsigned char *)0X32)
#define DDRD *((volatile unsigned char *)0X31)
#define PIND *((volatile unsigned char *)0X30)
#define F_CPU 8000000
#include<avr/delay.h>
u8 DIO_SET_PORT_DIRECTION(u8 port_num,u8 direction);
u8 DIO_SET_PIN_DIRECTION(u8 port_num,u8 pin_num,u8 direction);
u8 DIO_SET_PORT_VALUE(u8 port_num,u8 value);
u8 DIO_SET_PIN_VALUE(u8 port_num,u8 pin_num,u8 value);
u8 DIO_GET_PORT_VALUE(u8 port_num,u8 *register_reading);
u8 DIO_GET_PIN_VALUE(u8 port_num ,u8 pin_num,u8 *register_reading);
#endif /* DIO_DD_h_ */
