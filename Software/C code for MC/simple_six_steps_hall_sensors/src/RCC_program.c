/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 29 / 7 / 2021                                                              */
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock (u8 copy_u8BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB   : SET_BIT(RCC_AHBENR,copy_u8PerId);  break;
			case RCC_APB1  : SET_BIT(RCC_APB1ENR,copy_u8PerId); break;
			case RCC_APB2  : SET_BIT(RCC_APB2ENR,copy_u8PerId); break;
		/*  default    : return error                       break; */
		
		}   
	}       
	else    
	{       
		/* return error */
	}      
}           
void RCC_voidDisableClock (u8 copy_u8BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB   : CLR_BIT(RCC_AHBENR,copy_u8PerId);  break;
			case RCC_APB1  : CLR_BIT(RCC_APB1ENR,copy_u8PerId); break;
			case RCC_APB2  : CLR_BIT(RCC_APB2ENR,copy_u8PerId); break;
		/*  default    : return error                       break; */
		
		}   
	}       
	else    
	{       
		/* return error */
	}    	
}        
void RCC_voidInitSysClock (void)
{
    #if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	        RCC_CR   = 0X00010000 ; /* Enable HSE_RC (BYPASS) */
			RCC_CFGR = 0X00000001 ; /* HSE selected as system clock*/
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0X00050000 ; /* Enable HSE_RC (BYPASS) */
		RCC_CFGR = 0X00000001 ; /* HSE selected as system clock*/
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0X00000081 ; /* Enable HSI + Trimming = default value (8 MHZ)*/
		RCC_CFGR = 0x00000000 ; /* HSI selected as system clock */
	#elif RCC_CLOCK_TYPE == RCC_PLL
		RCC_CR   = 0X01000000 ; /* Enable PLL */
		RCC_CFGR = 0X00000002 ; /* PLL selected as system clock */
		#if    RCC_PLL_INPUT == RCC_PLL_IN_HSI_DEV_2
			CLR_BIT(RCC_CFGR,16); /* HSI oscillator clock / 2 selected as PLL input clock*/
		#elif  RCC_PLL_INPUT == RCC_PLL_IN_HSE_DEV_2
			SET_BIT(RCC_CFGR,16); /*  HSE oscillator clock selected as PLL input clock */
			SET_BIT(RCC_CFGR,17); /* HSE clock divided by 2 */
		#elif  RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR,16); /*  HSE oscillator clock selected as PLL input clock */
			CLR_BIT(RCC_CFGR,17); /* HSE clock not divided  */
		#else
			#error ("you chosed a wrong PLL input clock ")
		#endif

	#if	  RCC_PLL_MUL_VAL  == 2
		RCC_CFGR |= 0X00000000 ;
	#elif RCC_PLL_MUL_VAL  == 3
		RCC_CFGR |= 0X00040000 ;
	#elif RCC_PLL_MUL_VAL  == 4
		RCC_CFGR |= 0X00080000 ;
	#elif RCC_PLL_MUL_VAL  == 5
		RCC_CFGR |= 0X000C0000 ;
	#elif RCC_PLL_MUL_VAL  == 6
		RCC_CFGR |= 0X00100000 ;
	#elif RCC_PLL_MUL_VAL  == 7
		RCC_CFGR |= 0X00140000 ;
	#elif RCC_PLL_MUL_VAL  == 8
		RCC_CFGR |= 0X00180000 ;
	#elif RCC_PLL_MUL_VAL  == 9
		RCC_CFGR |= 0X001C0000 ;
	#elif RCC_PLL_MUL_VAL  == 10
		RCC_CFGR |= 0X00200000 ;
	#elif RCC_PLL_MUL_VAL  == 11
		RCC_CFGR |= 0X00240000 ;
	#elif RCC_PLL_MUL_VAL  == 12
		RCC_CFGR |= 0X00280000 ;
	#elif RCC_PLL_MUL_VAL  == 13
		RCC_CFGR |= 0X002C0000 ;
	#elif RCC_PLL_MUL_VAL  == 14
		RCC_CFGR |= 0X00300000 ;
	#elif RCC_PLL_MUL_VAL  == 15
		RCC_CFGR |= 0X00340000 ;
	#elif RCC_PLL_MUL_VAL  == 16
		RCC_CFGR |= 0X00380000 ;
	#else
		#error (" you chosed a wrong PLL mutiplier value ")
	#endif

	#else
		#error (" you chosed wrong clock type ")
#endif


					 
}
