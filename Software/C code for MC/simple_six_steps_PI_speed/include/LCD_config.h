/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 17 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*	LCD pins configurations 		 */
/*	write pin configuration in pairs */
#define LCD_RS PORTB,PIN11
#define LCD_EN PORTB,PIN10
#define LCD_RW 
#define LCD_D0 
#define LCD_D1 
#define LCD_D2 
#define LCD_D3 
#define LCD_D4 PORTB,PIN1
#define LCD_D5 PORTB,PIN0
#define LCD_D6 PORTA,PIN7
#define LCD_D7 PORTA,PIN6
/*	set LCD mode configurations 			*/
/*	Select FOUR_BIT_MODE or EIGHT_BIT_MODE	*/
#define  	FOUR_BIT_MODE
/*	LCD commands 		*/
#ifdef 	 			FOUR_BIT_MODE
#define  			FUNCTION_SET 0x28
#elif defined 		EIGHT_BIT_MODE
#define 			FUNCTION_SET 0x38
#endif
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_OFF_CONTROL 0x0e



#endif
