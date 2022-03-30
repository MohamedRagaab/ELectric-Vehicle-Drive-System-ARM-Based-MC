/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 29 / 7 / 2021                                                              */
/******************************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*	options :		RCC_HSE_CRYSTAL
					RCC_HSE_RC
					RCC_HSI
					RCC_PLL        			    */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL
/* note : select option if you chosed the PLL as input clock source */
/* options :		RCC_PLL_IN_HSI_DEV_2
					RCC_PLL_IN_HSE_DEV_2
					RCC_PLL_IN_HSE				*/
#if RCC_CLOCK_TYPE == RCC_PLL 
#define RCC_PLL_INPUT 
#endif

/* options : from 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL 
#define RCC_PLL_MUL_VAL  
#endif

#endif