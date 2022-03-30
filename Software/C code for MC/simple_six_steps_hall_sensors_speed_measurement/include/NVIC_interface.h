/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 1 / 8 / 2021                                                               */
/******************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define PERIORITY_FORMAT_0		0X05FA0300		// 4 bits for group periority 0 bits sub periority
#define PERIORITY_FORMAT_1		0X05FA0400		// 3 bits for group periority 1 bits sub periority
#define PERIORITY_FORMAT_2		0X05FA0500		// 2 bits for group periority 2 bits sub periority
#define PERIORITY_FORMAT_3		0X05FA0600		// 1 bits for group periority 3 bits sub periority
#define PERIORITY_FORMAT_4		0X05FA0700		// 0 bits for group periority 4 bits sub periority

void NVIC_voidEnableInterrupt ( u8 copy_u8IntNumber );
void NVIC_voidDisableInterrupt ( u8 copy_u8IntNumber );
void NVIC_voidSetPendingFlag ( u8 copy_u8IntNumber );
void NVIC_voidClearPendingFlag ( u8 copy_u8IntNumber );
u8 NVIC_voidGetActiveFlag ( u8 copy_u8IntNumber );
void NVIC_voidSetPriority (u8 copy_u8InterruptPosition , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32PriorityFormat );
#endif 
