/*******************************************************************************************/
/*			Auther 		: Ezzeldin Magdy                                                   */
/*			Version 	: v02                                                              */
/*			Date		: 8/1/2021														   */
/*******************************************************************************************/
#ifndef		DIO_PRIVATE_H
#define 	DIO_PRIVATE_H

		/*  register definition  */
#define		GPIOA_BASE_ADDRESS		0x40010800
#define		GPIOB_BASE_ADDRESS		0x40010C00
#define		GPIOC_BASE_ADDRESS		0x40011000 
		/* PORTA register definition */
#define		GPIOA_CRL				*((u32 *)(GPIOA_BASE_ADDRESS + 0X00))
#define		GPIOA_CRH				*((u32 *)(GPIOA_BASE_ADDRESS + 0X04))
#define		GPIOA_IDR				*((u32 *)(GPIOA_BASE_ADDRESS + 0X08))
#define		GPIOA_ODR				*((u32 *)(GPIOA_BASE_ADDRESS + 0X0C))
#define		GPIOA_BSRR				*((u32 *)(GPIOA_BASE_ADDRESS + 0X10))
#define		GPIOA_BRR    			*((u32 *)(GPIOA_BASE_ADDRESS + 0X14))
#define		GPIOA_LCKR				*((u32 *)(GPIOA_BASE_ADDRESS + 0X18))
		/* PORTB register definition */
#define		GPIOB_CRL				*((u32 *)(GPIOB_BASE_ADDRESS + 0X00))
#define		GPIOB_CRH				*((u32 *)(GPIOB_BASE_ADDRESS + 0X04))
#define		GPIOB_IDR				*((u32 *)(GPIOB_BASE_ADDRESS + 0X08))
#define		GPIOB_ODR				*((u32 *)(GPIOB_BASE_ADDRESS + 0X0C))
#define		GPIOB_BSRR				*((u32 *)(GPIOB_BASE_ADDRESS + 0X10))
#define		GPIOB_BRR    			*((u32 *)(GPIOB_BASE_ADDRESS + 0X14))
#define		GPIOB_LCKR				*((u32 *)(GPIOB_BASE_ADDRESS + 0X18))
		/* PORTC register definition */
#define		GPIOC_CRL				*((u32 *)(GPIOC_BASE_ADDRESS + 0X00))
#define		GPIOC_CRH				*((u32 *)(GPIOC_BASE_ADDRESS + 0X04))
#define		GPIOC_IDR				*((u32 *)(GPIOC_BASE_ADDRESS + 0X08))
#define		GPIOC_ODR				*((u32 *)(GPIOC_BASE_ADDRESS + 0X0C))
#define		GPIOC_BSRR				*((u32 *)(GPIOC_BASE_ADDRESS + 0X10))
#define		GPIOC_BRR    			*((u32 *)(GPIOC_BASE_ADDRESS + 0X14))
#define		GPIOC_LCKR				*((u32 *)(GPIOC_BASE_ADDRESS + 0X18))


#endif
