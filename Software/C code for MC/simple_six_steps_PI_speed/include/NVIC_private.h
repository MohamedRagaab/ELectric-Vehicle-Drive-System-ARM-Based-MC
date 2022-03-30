/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 1 / 8 / 2021                                                               */
/******************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
		/* Register definitions */
#define		NVIC_BASE_ADREES 	0xE000E100
#define 	NVIC_ISER0			*((u32 *)(NVIC_BASE_ADREES + 0x000 )) /* Enable External Interrupts from 0  : 31 */
#define 	NVIC_ISER1			*((u32 *)(NVIC_BASE_ADREES + 0x004 )) /* Enable External Interrupts from 32 : 63 */

#define 	NVIC_ICER0			*((u32 *)(NVIC_BASE_ADREES + 0x080 )) /* Disnable External Interrupts from 0  : 31 */
#define 	NVIC_ICER1			*((u32 *)(NVIC_BASE_ADREES + 0x084 )) /* Disable External Interrupts from 32 : 63 */

#define 	NVIC_ISPR0			*((u32 *)(NVIC_BASE_ADREES + 0x100 )) /* Set pending flag for Interrupts from 0  : 31 */
#define 	NVIC_ISPR1			*((u32 *)(NVIC_BASE_ADREES + 0x104 )) /* Set pending flag for Interrupts from 32 : 63 */

#define 	NVIC_ICPR0			*((u32 *)(NVIC_BASE_ADREES + 0x180 )) /* clear pending flag for Interrupts from 0  : 31 */
#define 	NVIC_ICPR1			*((u32 *)(NVIC_BASE_ADREES + 0x184 )) /* clear pending flag for Interrupts from 32 : 63 */

#define 	NVIC_IABR0			*((volatile u32 *)(NVIC_BASE_ADREES + 0x200 )) /* read Active flag for Interrupts from 0  : 31 */
#define 	NVIC_IABR1			*((volatile u32 *)(NVIC_BASE_ADREES + 0x204 )) /* read Active flag for Interrupts from 32 : 63 */

#define 	NVIC_IPR			 ((volatile u8 *)(NVIC_BASE_ADREES + 0x300 )) 


#define SCB_BASE_ADDRESS		0xE000ED00
#define 	SCB_AIRCR			*((volatile u32 *) (SCB_BASE_ADDRESS + 0x0C))





#endif 
