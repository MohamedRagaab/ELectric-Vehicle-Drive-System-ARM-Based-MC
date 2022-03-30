/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 7 / 8 / 2021                                                               */
/******************************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit ( void );

void MSTK_voidSetBusyWait (u32 copy_u32Ticks);

void MSTK_voidSetIntervalSingle (u32 copy_u32Ticks , void (*ptr)(void));
void MSTK_voidSetIntervalPeriodic (u32 copy_u32Ticks , void (*ptr)(void) );
void MSTK_voidStopTimer (void);
u32  MSTK_u32GetElapsedTime (void );
u32  MSTK_u32GetRemainingTime (void );

#endif
