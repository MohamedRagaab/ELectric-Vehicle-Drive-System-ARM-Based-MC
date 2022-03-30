/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 29 / 7 / 2021                                                              */
/******************************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2 
#define RCC_PLL_IN_HSI_DEV_2 0
#define RCC_PLL_IN_HSE_DEV_2 1 
#define RCC_PLL_IN_HSE		 2  

void RCC_voidEnableClock (u8 copy_u8BusId , u8 copy_u8PerId);
void RCC_voidDisableClock (u8 copy_u8BusId , u8 copy_u8PerId);
void RCC_voidInitSysClock (void);
#endif