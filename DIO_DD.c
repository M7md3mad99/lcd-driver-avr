/*
 * DIO_DD.C
 *
 *  Created on: Oct 9, 2021
 *      Author: PC-SHOP
 */
#include "DIO_DD.h"
#include<stdio.h> //DO 3 THNGS : ALL LEDS ON , BLINKING LIDS , LEDS ON BY ORDER
/*int main(void)
{
	  DIO_SET_PORT_DIRECTION(PORTD_NUM,all_output);
	  DIO_SET_PIN_DIRECTION(PORTA_NUM,0,input);
	  DIO_SET_PIN_DIRECTION(PORTB_NUM,3,input);
	  DIO_SET_PIN_DIRECTION(PORTC_NUM,7,input);
	  DIO_SET_PIN_VALUE(PORTA_NUM,0,pull_up);
	  DIO_SET_PIN_VALUE(PORTB_NUM,3,pull_up);
	  DIO_SET_PIN_VALUE(PORTC_NUM,7,pull_up);
	  u8 pin0_value;
	  u8 pin3_value;
	  u8 pin7_value;
      u8 i,m;
	while(1)
  {
		DIO_GET_PIN_VALUE(PORTA_NUM,0,&pin0_value);
		DIO_GET_PIN_VALUE(PORTB_NUM,3,&pin3_value);
		DIO_GET_PIN_VALUE(PORTC_NUM,7,&pin7_value);

		if(pin0_value==0)
		{
			DIO_SET_PORT_VALUE(PORTD_NUM,all_high);
		}
		else if(pin3_value==0)
		{
			DIO_SET_PORT_VALUE(PORTD_NUM,all_high);
			_delay_ms(500);
			DIO_SET_PORT_VALUE(PORTD_NUM,low);
			_delay_ms(500);

		}
		else if(pin7_value==0)
		{   DIO_SET_PORT_VALUE(PORTD_NUM,all_high);

			_delay_ms(250);

			       for(i=0;i<8;i++)
			       {
			    	   PORTD=1<<i;
			    	   _delay_ms(250);
			       }
			       for(m=0;m<8;m++)
			       {
			    	   PORTD=0b10000000>>m;
			    	   _delay_ms(250);
			       }
		}

		else
		{

			   DIO_SET_PORT_VALUE(PORTD_NUM,low);

		}

  }
   DIO_SET_PORT_DIRECTION(PORTC_NUM,all_output);
 u8 seven_segment[11]={num_zero,num_one,num_two,num_three,num_four,num_five,num_six,num_seven,num_eight,num_nine,dot};
while(1)
{
	for(u8 z=0 ; z<=10;z++)
	{
		DIO_SET_PORT_VALUE(PORTC_NUM,seven_segment[z]);
		_delay_ms(1000);
	}
}

}*/
u8 DIO_SET_PORT_DIRECTION(u8 port_num,u8 direction)
{
	if(port_num<=PORTD_NUM)
	{
	switch(port_num)
	{
	case PORTA_NUM :
	DDRA=direction;
	break;
	case PORTB_NUM :
	DDRB=direction;
	break;
	case PORTC_NUM :
	DDRC=direction;
	break;
	case PORTD_NUM :
	DDRD=direction;
	break;
	}
	return ok;
	}
	else
	{
		return not_ok;
	}

}
u8 DIO_SET_PIN_DIRECTION(u8 port_num,u8 pin_num,u8 direction)
{
	if(port_num<=PORTD_NUM && direction<=1)
	{
	switch(port_num)
	{
	case PORTA_NUM :
	switch(direction)
	{ case output :
		set_bit(DDRA,pin_num);
		break;
	case input :
		clr_bit(DDRA,pin_num);
		break;
	}
	break;
	case PORTB_NUM :
	switch(direction)
	{ case output :
		set_bit(DDRB,pin_num);
			break;
	  case input :
		clr_bit(DDRB,pin_num);
			break;
	}
	break;
	case PORTC_NUM :
	switch(direction)
	{ case output :
	  set_bit(DDRC,pin_num);
		break;
	  case input :
	  clr_bit(DDRC,pin_num);
	   break;
	}
	break;
	case PORTD_NUM :
	switch(direction)
	{ case output :
	  set_bit(DDRD,pin_num);
	  break;
	  case input :
	  clr_bit(DDRD,pin_num);
	  break;
	}
	break;
	}
	return ok;
	}
	else
	{
		return not_ok;
	}


}
u8 DIO_SET_PORT_VALUE(u8 port_num,u8 value)
{
	if (port_num<=PORTD_NUM)
	{
		switch (port_num)
		{
		case PORTA_NUM :
		PORTA=value;
		break;

		case PORTB_NUM :
		PORTB=value;
		break;

		case PORTC_NUM :
		PORTC=value;
		break;

		case PORTD_NUM :
		PORTD=value;
		break;

		}
     return ok;

	}
	else
	{return not_ok;}
}
u8 DIO_SET_PIN_VALUE(u8 port_num,u8 pin_num,u8 value)
{
	if(port_num<=PORTD_NUM && value<=1)
	{
	switch(port_num)
	{
	case PORTA_NUM :
	switch(value)
	{ case high :
		set_bit(PORTA,pin_num);
		break;
	case low :
		clr_bit(PORTA,pin_num);
		break;
	}
	break;
	case PORTB_NUM :
	switch(value)
	{ case high :
		set_bit(PORTB,pin_num);
			break;
	  case low :
		clr_bit(PORTB,pin_num);
			break;
	}
	break;
	case PORTC_NUM :
	switch(value)
	{ case high :
	  set_bit(PORTC,pin_num);
		break;
	  case low :
	  clr_bit(PORTC,pin_num);
	   break;
	}
	break;
	case PORTD_NUM :
	switch(value)
	{ case high :
	  set_bit(PORTD,pin_num);
	  break;
	  case low :
	  clr_bit(PORTD,pin_num);
	  break;
	}
	break;
	}
	return ok;
	}
	else
	{
		return not_ok;
	}


}
u8 DIO_GET_PORT_VALUE(u8 port_num,u8 *register_reading)
{
	if(port_num<=PORTD_NUM)
	{
	switch(port_num)
	{
	case PORTA_NUM :
	*register_reading=PINA;
	break;
	case PORTB_NUM :
    *register_reading=PINB;
	break;
	case PORTC_NUM :
	*register_reading=PINC;
	break;
	case PORTD_NUM :
    *register_reading=PIND;
	break;
	}
	return ok;
	}
	else
	{
		return not_ok;
	}

}
u8 DIO_GET_PIN_VALUE(u8 port_num ,u8 pin_num,u8 *register_reading)
{
	if(port_num<=PORTD_NUM && pin_num<8)
	{
	switch(port_num)
	{
	case PORTA_NUM :
	*register_reading=get_bit(PINA,pin_num);
	break;
	case PORTB_NUM :
	*register_reading=get_bit(PINB,pin_num);
	break;
	case PORTC_NUM :
	*register_reading=get_bit(PINC,pin_num);
	break;
	case PORTD_NUM :
	*register_reading=get_bit(PIND,pin_num);
	break;
	}
	return ok;
	}
	else
	{
		return not_ok;
	}


}
