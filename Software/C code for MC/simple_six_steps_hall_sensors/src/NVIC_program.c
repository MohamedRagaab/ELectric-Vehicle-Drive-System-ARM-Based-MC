/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 1 / 8 / 2021                                                               */
/******************************************************************************************/
 /*inclusions*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableInterrupt ( u8 copy_u8IntNumber )
{
	if (copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = 1<<( copy_u8IntNumber ) ;
	}
	else if ( copy_u8IntNumber <= 59 )
	
	{
		NVIC_ISER1 = 1<<( copy_u8IntNumber - 32 ) ;
		
	}
	else 
	{
		//	return error 
	}
}
void NVIC_voidDisableInterrupt ( u8 copy_u8IntNumber )
{
	if (copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = 1<<( copy_u8IntNumber  ) ;
	}
	else if ( copy_u8IntNumber <= 59 )
	
	{
		NVIC_ICER1 = 1<<( copy_u8IntNumber - 32 ) ;
		
	}
	else 
	{
		//	return error 
	}
}
void NVIC_voidSetPendingFlag ( u8 copy_u8IntNumber )
{
	if (copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = 1<<( copy_u8IntNumber  ) ;
	}
	else if ( copy_u8IntNumber <= 59 )
	
	{
		NVIC_ISPR1 = 1<<( copy_u8IntNumber - 32 ) ;
		
	}
	else 
	{
		//	return error 
	}
}
void NVIC_voidClearPendingFlag ( u8 copy_u8IntNumber )
{
	if (copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = 1<<( copy_u8IntNumber  ) ;
	}
	else if ( copy_u8IntNumber <= 59 )
	
	{
		NVIC_ICPR1 = 1<<( copy_u8IntNumber - 32 ) ;
		
	}
	else 
	{
		//	return error 
	}
}
u8 NVIC_voidGetActiveFlag ( u8 copy_u8IntNumber )
{
	u8 Local_u8Result ;
	if (copy_u8IntNumber <= 31)
	{
			Local_u8Result = GET_BIT (NVIC_IABR0 ,copy_u8IntNumber ) ;
	}
	else if ( copy_u8IntNumber <= 59 )
	
	{
		Local_u8Result = GET_BIT (NVIC_IABR1 ,copy_u8IntNumber - 32 ) ;
		
	}
	else 
	{
		//	return error 
	}
	return Local_u8Result ;
   }
void NVIC_voidSetPriority (u8 copy_u8InterruptPosition , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32PriorityFormat )
{
	SCB_AIRCR = copy_u32PriorityFormat ;
	NVIC_IPR[copy_u8InterruptPosition] = (copy_u8SubPriority | (copy_u8GroupPriority <<(( copy_u32PriorityFormat - 0X05FA0300 ) / 0X100 ))) << 4 ;
}
