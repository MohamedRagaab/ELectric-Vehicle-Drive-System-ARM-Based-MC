/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 17 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
void LCD_voidSetPinsDirection (void);
void LCD_voidSendCmd(u8 copy_u8Cmd);
void LCD_voidInitialize();
void LCD_voidSendChar(u8 copy_u8Data);
void LCD_voidSendString(u8 * Data);
void LCD_voidClearScreen();
void LCD_voidMoveCursor(u8 copy_u8Row,u8 copy_u8Coloumn);
void LCD_voidSendDNumber(s16 Copy_u16DNumber);
void LCD_voidSendFNumber(f32 copy_f32FNumber , u8 copy_u8NumOfDigitsAfterPoint);
void LCD_voidGenerateCutomChar( u8 copy_u8CharacterNumber , u8 * Ptr);
void LCD_voidDiplayCustomChar(u8 copy_u8CharacterNumber);

#endif
