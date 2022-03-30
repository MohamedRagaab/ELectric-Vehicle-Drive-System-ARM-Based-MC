/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H
void MTIMER2_voidCountUp (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER2_voidCountDown (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER2_voidCountUpDown (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER2_externalcounter (u16 copy_u16ReloadValue , void (*ptr1) (void) , void (*ptr2) (void)  );
void MTIMER2_voidGeneratePWM ( u16 copy_u32PeriodInMicro , u8 copy_u8DutyPercentage );
void MTIMER2_voidGeneratePWMCenterAligned ( u32 copy_u32EvenPeriodInus , u8 copy_u8DutyPercentage , u8 copy_u8DeadTimeInus );
void MTIMER2_voidMeasureHallSensorsAsynch( void ( *Ptr_TO_CC_Task ) ( u16  ));


#endif
