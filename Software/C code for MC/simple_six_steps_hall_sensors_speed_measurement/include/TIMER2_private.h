/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H

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
	volatile u32 Reserved	;
	volatile u32 CCR1	;
	volatile u32 CCR2	;
	volatile u32 CCR3	;
	volatile u32 CCR4	;
	volatile u32 Reserved_1	;
	volatile u32 DCR 	;
	volatile u32 DMAR	;
} MTIMER2_t ;
#define 	MTIMER2 	((volatile MTIMER2_t *)(0x40000000 ))

#endif
