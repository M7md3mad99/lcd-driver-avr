/*
 * LCD.c
 *
 *  Created on: Oct 16, 2021
 *      Author: PC-SHOP
 */
#include"DIO_DD.h"
#include"LCD.h"
#include<stdio.h>
int main(void)
{
	LCD_INIT();
   /*while(1)
   {
	   LCD_SEND_DATA('A');
   }*/

      LCD_GOTO_X_Y(5,1);
      LCD_SEND_STRING("EMAD");

	}

void LCD_SEND_COMMAND(u8 command)
{
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,RS,low);
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,RW,low);
DIO_SET_PORT_VALUE(LCD_DATA_PORT,command);
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,E,high);
_delay_ms(20);
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,E,low);
_delay_ms(50);
}
void LCD_SEND_DATA(u8 data)
{
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,RS,high);
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,RW,low);
	DIO_SET_PORT_VALUE(LCD_DATA_PORT,data);
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,E,high);
	_delay_ms(20);
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,E,low);
}
void LCD_INIT(void)
{
	DIO_SET_PORT_DIRECTION(LCD_DATA_PORT,all_output);
	DIO_SET_PIN_DIRECTION(LCD_CONTROL_PORT,RS,output);
	DIO_SET_PIN_DIRECTION(LCD_CONTROL_PORT,RW,output);
	DIO_SET_PIN_DIRECTION(LCD_CONTROL_PORT,E,output);
	LCD_SEND_COMMAND(FUNCTION_SET);
	LCD_SEND_COMMAND(DISPLAY_ON);
	LCD_SEND_COMMAND(RETURN_HOME);
	LCD_SEND_COMMAND(CLEAR_DISPLAY);
}
void LCD_SEND_STRING(u8 *string)
{

		for(u8 i=0;string[i]!='\0';i++)
		{
		LCD_SEND_DATA(string[i]);

		}

}
void LCD_GOTO_X_Y(u8 col, u8 row)
{
u8 command=0;
 switch(row)
 {
 case line_1:

command=0b10000000+col;
LCD_SEND_COMMAND(command);
break;
 case line_2 :

command=0b11000000+col;
LCD_SEND_COMMAND(command);
 break;
}
}
