/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

typedef struct {
	volatile u32 CR1 	;
	volatile u32 CR2 	;
	volatile u32 SMCR 	;
	volatile u32 DIER	;
	volatile u32 SR		;
	volatile u32 EGR	;
	volatile u32 CCMR1	;
	volatile u32 CCMR2	;
	volatile u32 CCER	;
	volatile u32 CNT	;
	volatile u32 PSC	;
	volatile u32 ARR	;
	volatile u32 RCR	;
	volatile u32 CCR1	;
	volatile u32 CCR2	;
	volatile u32 CCR3	;
	volatile u32 CCR4	;
	volatile u32 BDTR	;
	volatile u32 DCR 	;
	volatile u32 DMAR	;
} MTIMER1_t ;
#define 	MTIMER1 	((volatile MTIMER1_t *)(0x40012C00))

#endif