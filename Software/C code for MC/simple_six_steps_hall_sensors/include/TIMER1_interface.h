/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

/*	select the output mode 	*/
#define OCM_FORCED_INACTIVE		4
#define OCM_FORCED_ACTIVE		5
#define OCM_PWM		        	7
/*	select
 * CCXE	Capture/Compare 1 output enable
 * Capture/Compare 1 complementary output enable	*/
#define CC_ENABLED 	1
#define CC_DISABLED 0

void MTIMER1_voidCountUp (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER1_voidCountDown (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER1_voidCountUpDown (u16 copy_u16ReloadValue , void (* ptr )(void));
void MTIMER1_externalcounter (u16 copy_u16ReloadValue , void (*ptr1) (void) , void (*ptr2) (void)  );
void MTIMER1_voidGeneratePWM ( u16 copy_u32PeriodInMicro , u8 copy_u8DutyPercentage );
void MTIMER1_voidGeneratePWMCenterAligned ( u32 copy_u32EvenPeriodInus , u8 copy_u8DutyPercentage , u8 copy_u8DeadTimeInus );
void MTIMER1_voidConfigPWM ( u32 copy_u32EvenPeriodInus , u8 copy_u8DutyPercentage  );
void MTIMER1_voidConfigurePWM ( u16 copy_u32PeriodInMicro  );

void MTIMER1_voidConfigSlaveMode (void ( *Ptr_To_COM_Task ) ( 	void  ));
void MTIMER1_voidGenerateOutputControlSignals (u8 * OCM  ,  u8 * CCE  , u8 * CCNE );
void MTIMER1_voidGeneratePWM1 (  u8 copy_u8DutyPercentage );
void MTIMER1_voidGeneratePWM2 (  u8 copy_u8DutyPercentage );
void MTIMER1_voidGeneratePWM3 (  u8 copy_u8DutyPercentage );


#endif
