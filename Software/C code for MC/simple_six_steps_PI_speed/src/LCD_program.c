/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 17 / 9 / 2021                                                              */
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

 void LCD_EnablePulse()
{
	DIO_voidSetPinValue ( LCD_EN , HIGH );
	MSTK_voidSetBusyWait (2000);
	DIO_voidSetPinValue ( LCD_EN , LOW  );
}
void LCD_voidSetPinsDirection (void)
{
	#if defined EIGHT_BIT_MODE
	DIO_voidSetPinDirection (LCD_D0 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D1 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D2 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D3 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D4 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D5 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D6 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D7 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_RS , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_EN , OUTPUT_2MHZ_PP );
	#elif defined FOUR_BIT_MODE
	DIO_voidSetPinDirection (LCD_D4 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D5 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D6 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_D7 , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_RS , OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection (LCD_EN , OUTPUT_2MHZ_PP );
	#endif

}
void LCD_voidSendCmd(u8 copy_u8Cmd)
{
#if defined EIGHT_BIT_MODE
DIO_voidSetPinValue (LCD_D0 , GET_BIT(copy_u8Cmd , 0));
DIO_voidSetPinValue (LCD_D1 , GET_BIT(copy_u8Cmd , 1));
DIO_voidSetPinValue (LCD_D2 , GET_BIT(copy_u8Cmd , 2));
DIO_voidSetPinValue (LCD_D3 , GET_BIT(copy_u8Cmd , 3));
DIO_voidSetPinValue (LCD_D4 , GET_BIT(copy_u8Cmd , 4));
DIO_voidSetPinValue (LCD_D5 , GET_BIT(copy_u8Cmd , 5));
DIO_voidSetPinValue (LCD_D6 , GET_BIT(copy_u8Cmd , 6));
DIO_voidSetPinValue (LCD_D7 , GET_BIT(copy_u8Cmd , 7));
DIO_voidSetPinValue (LCD_RS ,LOW);
LCD_EnablePulse();
#elif defined FOUR_BIT_MODE
DIO_voidSetPinValue (LCD_D4 , GET_BIT(copy_u8Cmd , 4));
DIO_voidSetPinValue (LCD_D5 , GET_BIT(copy_u8Cmd , 5));
DIO_voidSetPinValue (LCD_D6 , GET_BIT(copy_u8Cmd , 6));
DIO_voidSetPinValue (LCD_D7 , GET_BIT(copy_u8Cmd , 7));
DIO_voidSetPinValue (LCD_RS ,LOW);
LCD_EnablePulse();
DIO_voidSetPinValue (LCD_D4 , GET_BIT(copy_u8Cmd , 0));
DIO_voidSetPinValue (LCD_D5 , GET_BIT(copy_u8Cmd , 1));
DIO_voidSetPinValue (LCD_D6 , GET_BIT(copy_u8Cmd , 2));
DIO_voidSetPinValue (LCD_D7 , GET_BIT(copy_u8Cmd , 3));
LCD_EnablePulse();
#endif
}
void LCD_voidSendChar(u8 copy_u8Data)
{
#if defined EIGHT_BIT_MODE
DIO_voidSetPinValue ( LCD_D0 , GET_BIT(copy_u8Data , 0) );
DIO_voidSetPinValue ( LCD_D1 , GET_BIT(copy_u8Data , 1) );
DIO_voidSetPinValue ( LCD_D2 , GET_BIT(copy_u8Data , 2) );
DIO_voidSetPinValue ( LCD_D3 , GET_BIT(copy_u8Data , 3) );
DIO_voidSetPinValue ( LCD_D4 , GET_BIT(copy_u8Data , 4) );
DIO_voidSetPinValue ( LCD_D5 , GET_BIT(copy_u8Data , 5) );
DIO_voidSetPinValue ( LCD_D6 , GET_BIT(copy_u8Data , 6) );
DIO_voidSetPinValue ( LCD_D7 , GET_BIT(copy_u8Data , 7) );
DIO_voidSetPinValue (LCD_RS, HIGH );
lcd_enablepulse();
#elif defined FOUR_BIT_MODE
DIO_voidSetPinValue ( LCD_D4 , GET_BIT(copy_u8Data , 4) );
DIO_voidSetPinValue ( LCD_D5 , GET_BIT(copy_u8Data , 5) );
DIO_voidSetPinValue ( LCD_D6 , GET_BIT(copy_u8Data , 6) );
DIO_voidSetPinValue ( LCD_D7 , GET_BIT(copy_u8Data , 7) );
DIO_voidSetPinValue (LCD_RS, HIGH );
LCD_EnablePulse();
DIO_voidSetPinValue ( LCD_D4 , GET_BIT(copy_u8Data , 0 ) );
DIO_voidSetPinValue ( LCD_D5 , GET_BIT(copy_u8Data , 1 ) );
DIO_voidSetPinValue ( LCD_D6 , GET_BIT(copy_u8Data , 2 ) );
DIO_voidSetPinValue ( LCD_D7 , GET_BIT(copy_u8Data , 3 ) );
DIO_voidSetPinValue (LCD_RS, HIGH );
LCD_EnablePulse();
#endif
}
void LCD_voidInitialize()
{
#if defined EIGHT_BIT_MODE
 LCD_voidSendCmd(FUNCTION_SET); //8 bit mode
MSTK_voidSetBusyWait(1000);
 LCD_voidSendCmd(DISPLAY_ON_OFF_CONTROL);//display on cursor on
MSTK_voidSetBusyWait(1000);
LCD_voidSendCmd(CLR_SCREEN);//clear the screen
MSTK_voidSetBusyWait(10000);
LCD_voidSendCmd(ENTRY_MODE); //entry mode
MSTK_voidSetBusyWait(1000);
#elif defined FOUR_BIT_MODE
LCD_voidSendCmd(RETURN_HOME); //return home
MSTK_voidSetBusyWait(10000);
LCD_voidSendCmd(FUNCTION_SET); //4bit mode
MSTK_voidSetBusyWait(1000);
LCD_voidSendCmd(DISPLAY_ON_OFF_CONTROL);//display on cursor on
MSTK_voidSetBusyWait(1000);
LCD_voidSendCmd(CLR_SCREEN);//clear the screen
MSTK_voidSetBusyWait(10000);
LCD_voidSendCmd(ENTRY_MODE); //entry mode
MSTK_voidSetBusyWait(1000);
#endif
}
void LCD_voidClearScreen()
{
LCD_voidSendCmd(CLR_SCREEN);//clear the screen
MSTK_voidSetBusyWait(10000);
}
void LCD_voidMoveCursor(u8 copy_u8Row,u8 copy_u8Coloumn)
{
	u8 cmd = 0  ;
	if(copy_u8Row>2||copy_u8Row<1||copy_u8Coloumn>16||copy_u8Coloumn<1)
	{cmd = 0x80;}
	else if(copy_u8Row==1)
	{cmd=0x80+copy_u8Coloumn-1 ;}
	else if (copy_u8Row==2)
	{cmd=0xc0+copy_u8Coloumn-1;}
	LCD_voidSendCmd(cmd);
	MSTK_voidSetBusyWait(1000);
}
void LCD_voidSendString(u8 *Data)
{
	while((*Data)!='\0')
	{
	LCD_voidSendChar( *Data );
	Data++;
	}
}

void LCD_voidSendDNumber(s16 Copy_u16DNumber)
{
	u16 pdnumber ; //positive decimal number
	s8 i = 0 ;
	u8 arr[16] ={0}  ;
	if (Copy_u16DNumber < 0)
	{
		LCD_voidSendChar('-');
		pdnumber = -1 * Copy_u16DNumber ;
	}
	else if (Copy_u16DNumber == 0)
	{
		LCD_voidSendChar('0');
		return ;
	}
	else
	{
		pdnumber = Copy_u16DNumber ; 
	}
	while (pdnumber!=0)
	{
	arr[i] = (pdnumber%10) + '0' ;
	pdnumber/=10;
	i++;
	}
	i--;
	for(;i>=0;i--)
	{
		LCD_voidSendChar(arr[i]);
	}
}
void LCD_voidSendFNumber(f32 copy_f32FNumber , u8 copy_u8NumOfDigitsAfterPoint)
{
	s16  local_u16DecimalNum = copy_f32FNumber ;
	f32   local_u8DigitsAfterPoint =  copy_f32FNumber - local_u16DecimalNum ;
	LCD_voidSendDNumber( local_u16DecimalNum ) ;
	if (copy_u8NumOfDigitsAfterPoint > 0)
	{
	LCD_voidSendChar   ( '.') ;
	if ( local_u8DigitsAfterPoint < 0 )
	{
		local_u8DigitsAfterPoint *= -1 ;
	}
	for (u8 i = 0 ; i <copy_u8NumOfDigitsAfterPoint ; i++ )
	{
		local_u8DigitsAfterPoint *= 10 ;
	}
	u16 local_u8DigitsAfterPointAsDecimal = local_u8DigitsAfterPoint ;
	LCD_voidSendDNumber( local_u8DigitsAfterPointAsDecimal ) ;
	}
	else 
	{return ;}
}
void LCD_voidGenerateCutomChar( u8 copy_u8CharacterNumber , u8 * Ptr)
{
	u8 i ;
	for (i=0;i<8;i++)
	{
	LCD_voidSendCmd(0x40 + 8 *( copy_u8CharacterNumber - 1 ) + i ); /*	Set CGRAM address	*/
	MSTK_voidSetBusyWait(1000);
	LCD_voidSendChar(*(Ptr+i));
	}
}
void LCD_voidDiplayCustomChar(u8 copy_u8CharacterNumber)
{
	LCD_voidSendChar(copy_u8CharacterNumber - 1);
}

		 
