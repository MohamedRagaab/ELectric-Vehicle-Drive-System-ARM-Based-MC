/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 5 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

typedef struct {
	volatile u32 SR 	;
	volatile u32 CR1 	;
	volatile u32 CR2 	;
	volatile u32 SMPR1 	;
	volatile u32 SMPR2	;
	volatile s32 JOFR1 	;
	volatile s32 JOFR2	;
	volatile s32 JOFR3	;
	volatile s32 JOFR4	;
	volatile u32 HTR 	;
	volatile u32 LTR	;
	volatile u32 SQR1	;
	volatile u32 SQR2	;
	volatile u32 SQR3	;
	volatile u32 JSQR	;
	volatile u32 JDR1	;
	volatile u32 JDR2	;
	volatile u32 JDR3	;
	volatile u32 JDR4	;
	volatile u32 DR		;
} MADC1_t ;
#define MADC1		(( volatile MADC1_t *)0X40012400)


#endif
