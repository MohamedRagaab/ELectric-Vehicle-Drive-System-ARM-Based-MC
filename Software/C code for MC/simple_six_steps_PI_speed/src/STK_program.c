/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 7 / 8 / 2021                                                               */
/******************************************************************************************/
/*inclusions*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
void ( * MSTK_CallBack ) ( void );
u8 MSTK_State ;
/* MSTK_voidInit : select the systick clock source , Disable the STK and Disable the STK interrupt */
void MSTK_voidInit ( void )
{
	#if STK_CLOCK_SELECTION == STK_AHB_OVER_8_CLOCK
			STK->CTRL = 0X00000000 ;
	#elif STK_CLOCK_SELECTION == STK_AHB_CLOCK
			STK->CTRL = 0X00000004 ;
	#else 
			#error " STK clock selection is not true "
	#endif
	
}

void MSTK_voidSetBusyWait (u32 copy_u32Ticks)
{

	CLR_BIT(STK->CTRL,1); /* Enable STK */
	STK->LOAD = copy_u32Ticks   ;
	STK->VAL  = 0 ;
	SET_BIT(STK->CTRL,0); /* Enable STK */

	while( GET_BIT( STK->CTRL , 16 ) == 0 );
 /*wait in the function until counter flag is set to 1 and reset the flag to zero by reading it */
}

void MSTK_voidSetIntervalSingle (u32 copy_u32Ticks , void (*ptr)(void))
{
	STK->LOAD = copy_u32Ticks ;
	STK->VAL  = 0 ;
	SET_BIT(STK->CTRL,0); /* Enable STK */
	SET_BIT(STK->CTRL,1); /* Enable STK interrupt */
	MSTK_CallBack = ptr ;
	MSTK_State = 0;
}
void MSTK_voidSetIntervalPeriodic (u32 copy_u32Ticks ,  void (*ptr)(void) )
{
	STK->LOAD = copy_u32Ticks - 1  ;
	STK->VAL  = 0 ;
	SET_BIT(STK->CTRL,0); /* Enable STK */
	SET_BIT(STK->CTRL,1); /* Enable STK interrupt */
	MSTK_CallBack = ptr ;
	MSTK_State = 1 ;

}
void MSTK_voidStopTimer (void)
{
	CLR_BIT(STK->CTRL,0); /* Disable STK */
	CLR_BIT(STK->CTRL,1); /* Disable STK interrupt */
}
u32  MSTK_u32GetElapsedTime (void )
{
	u32 local_u32ElapsedTime = (STK->LOAD) - (STK->VAL);
	return local_u32ElapsedTime ;
}
u32  MSTK_u32GetRemainingTime (void )
{
	u32 local_u32RemainingTime = (STK->VAL);
	return local_u32RemainingTime ;
}


void SysTick_Handler (void)
{
	if 	(MSTK_State == 0)
	{
	CLR_BIT(STK->CTRL,0); /* Disable STK */
	CLR_BIT(STK->CTRL,1); /* Disable STK interrupt */
	}
	MSTK_CallBack();
}
