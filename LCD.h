/*
 * LCD.h
 *
 *  Created on: Oct 16, 2021
 *      Author: PC-SHOP
 */

#ifndef LCD_H_
#define LCD_H_
#define LCD_CONTROL_PORT PORTA_NUM
#define RS               0
#define RW               1
#define E                2
#define line_1           0
#define line_2           1
#define LCD_DATA_PORT    PORTC_NUM
#define CLEAR_DISPLAY    0x01
#define RETURN_HOME      0x02
#define FUNCTION_SET     0x38 //0b00111000
#define DISPLAY_ON       0x0f //0b00001111
void LCD_SEND_COMMAND(u8 command);
void LCD_SEND_STRING(u8 *string);
void LCD_SEND_DATA(u8 data);
void LCD_INIT(void);
void LCD_GOTO_X_Y(u8 col, u8 row);

#endif /* LCD_H_ */
