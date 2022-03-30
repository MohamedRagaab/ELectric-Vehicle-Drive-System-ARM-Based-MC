/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 7 / 8 / 2021                                                               */
/******************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct {
	volatile u32 CTRL  ;
	u32 LOAD  ;
	u32 VAL   ;
	u32 CALIB ;
} STK_t ;
#define STK ((STK_t * )(0xE000E010))
#define		STK_AHB_OVER_8_CLOCK	0
#define		STK_AHB_CLOCK			1

#endif
